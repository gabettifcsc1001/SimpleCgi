//
// tb_testIO
//
#include <string.h>

#ifndef TBIO_H
#define TBIO_H

class TBTESTIO
{
public:
  TBTESTIO(int id, char *buf);
  void Set();
  void SetField();
  void GetField();

protected:
  int m_id;
  char m_buf[255];
  char     *sql_serv  = "localhost";
  char     *user      = "testuser";
  char     *passwd    = "";
  char     *db_name   = "db_test";
  char     *table     = "tb_test";
};

#endif // TBIO_H
