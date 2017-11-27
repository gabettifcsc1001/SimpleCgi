#include "dblogin.h"

// 接続先の情報を格納
DBLOGIN::DBLOGIN(const char serv_name, const char user_name,
                  const char pass, const char dbagr_name){
  conn = NULL;
  *sql_serv = serv_name;
  *db_name  = dbagr_name;
  *user     = user_name;
  *passwd   = pass;
}
void DBLOGIN::DBConnect(){

    int dbconnect (){

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
}
~DBLOGIN::DBLOGIN(){

}
