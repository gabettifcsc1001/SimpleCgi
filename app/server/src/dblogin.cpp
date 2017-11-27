#include "dblogin.h"

// 接続先の情報を格納
DBLOGIN::DBLOGIN(char *serv_name, char *user_name,
                char *pass, char *dbarg_name){
  conn = NULL;
  strcpy(sql_serv, serv_name);
  strcpy(db_name, dbagr_name;
  strcpy(user, user_name);
  strcpy(passwd, pass);
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
