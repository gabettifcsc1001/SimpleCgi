#include "sql.h"

#define DPGS_GETRESLT_TEXT   0
#define DPGS_GETRESLT_BINARY 1

PUT_SQL::PUT_SQL(const char argaction){
    strcpy(action, argaction);
}

PUT_SQL::PUT_SQL(char argaction int id, char *buf){
    strcpy(action, argaction);
    m_id = id;
    strcpy(m_buf, buf);

}

void PUT_SQL::Put(){
// パラメータの判定
if (strcmp(action, "SELECT") == 0){
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
}
// パラメータの判定
else if(strcmp(action, "INSERT") == 0){
  // INSERT文の発行
  snprintf( &sql_str[0] , sizeof(sql_str)-1 , "insert into " tb_test valuese(m_id, m_buf) );
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
}

/*
// レスポンス
resp_cnt = PQntuples( resp );
for(loop=0; loop < resp_cnt ;loop++) {
  printf( "%d : %s\n" ,
          atoi( PQgetvalue( resp , loop , 0 ) ) ,
          PQgetvalue( resp , loop , 1 )
        );
}
