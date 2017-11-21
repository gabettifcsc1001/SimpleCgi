#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <postgres.h>
#include <libpq-fe.h>

#define DPGS_GETRESLT_TEXT   0
#define DPGS_GETRESLT_BINARY 1

int main(void){
  PGconn   *conn      = NULL;
  PGresult *resp      = NULL;
  char      sql_str[255];
  char     *sql_serv  = "localhost";
  char     *user      = "testuser";
  char     *passwd    = "";
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
  // select文の発行
  snprintf( &sql_str[0] , sizeof(sql_str)-1 , "select * from tb_test" );
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

  // レスポンス
  resp_cnt = PQntuples( resp );
  for(loop=0; loop < resp_cnt ;loop++) {
    printf( "%d : %s\n" ,
            atoi( PQgetvalue( resp , loop , 0 ) ) ,
            PQgetvalue( resp , loop , 1 )
          );
  }

  // 後片づけ
  PQclear( resp );
  return 0;
}
