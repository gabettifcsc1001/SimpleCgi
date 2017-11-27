#ifndef TBLOGIN_H
#define TBLOGIN_H

#include <errno.h>
#include <postgres.h>


class TBLOGIN
{
public:
   TBLOGIN(char serv_name, char user_name, char pass, char dbarg_name);
   void DBConnect();
   ~TBLOGIN();

protected:
  PGconn   *conn
  char     *sql_serv
  char     *user
  char     *passwd
  char     *db_name
};
#endif // TBLOGIN_H
