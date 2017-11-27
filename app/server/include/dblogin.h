//
// DB接続クラス
//

#ifndef TBLOGIN_H
#define TBLOGIN_H

#include <errno.h>
#include <postgres.h>


class DBLOGIN
{
public:
  　// コンストラクタ
   DBLOGIN(char serv_name, char user_name, char pass, char dbarg_name);
   //　DBに接続
   void DBConnect();
   // デストラクタ
   ~DBLOGIN();

protected:
  // メンバー変数宣言
  PGconn   *conn
  char     *sql_serv
  char     *user
  char     *passwd
  char     *db_name
};
#endif // TBLOGIN_H
