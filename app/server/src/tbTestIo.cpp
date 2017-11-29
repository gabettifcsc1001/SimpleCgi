#include "Tbtest.h"
#include <postgres.h>

#define DPGS_GETRESLT_TEXT   0
#define DPGS_GETRESLT_BINARY 1

tbTestIo::tbTestIo(){

}
int tbTestIo::Set(const char *fieldName, const char  *value){
    if (strcmp(fieldName, "id") == 0){
        mId = atoi(value);
    }
    else if(strcmp(fieldName, "name") == 0){
        strcpy(mName, value);
    }

    return 0;
}

int tbTestIo::Add(){
    PGconn   *conn      = NULL;
    PGresult *resp      = NULL;
    char      sql_str[255];
    char     *sql_serv  = "localhost";
    char     *user      = "testuser";
    char     *passwd    = "testuser";
    char     *db_name   = "db_test";
    int      resp_cnt   = 0;
    int      loop       = 0;
    memset( &sql_str[0] , 0x00 , sizeof(sql_str) );

    /* DB接続 */
    conn = PQsetdbLogin(
          sql_serv , // 接続先
          NULL ,     // ポート番号
          NULL ,     // デバッグオプション
          NULL ,     //デバッグ出力のためのファイル,またはtty名
          db_name ,  // DB名
          user    ,  // ユーザ名
          passwd     // パスワード
    );

    // エラーチェック
    if( PQstatus( conn ) == CONNECTION_BAD ){
        // error 内容はPQerrorMessage(con)で取得
        printf( "%s" ,PQerrorMessage(conn));
        exit(-1);
    }
    // insert文の発行
    snprintf( &sql_str[0] , sizeof(sql_str)-1 , "INSERT INTO tb_test(id, name) VALUES('%d', '%s')", mId, mName);
    resp = PQexecParams(
        conn                 , // 接続オブジェクト
        &sql_str[0]          , // 発行SQL文
        0                    , // パラメータ数
        NULL                 , // パラメータのデータ型
        NULL                 , // パラメータ値
        NULL                 , // パラメータのデータ長
        NULL                 , // パラメータのフォーマット形式
        DPGS_GETRESLT_BINARY   // 結果をバイナリで取得
    );

    resp = PQexec( conn , &sql_str[0] );
    // エラーチェック
    if( PQresultStatus( resp ) != PGRES_TUPLES_OK ) {
        // error
        printf("error_2 %d\n", PQresultStatus(resp));
        exit(-1);
    }
    return 0;
}
tbTestIo::~tbTestIo(){

}
