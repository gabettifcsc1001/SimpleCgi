#ifndef SQL_H
#define SQL_H

#include <postgres.h>
#include <stdio.h>
#include <string.h>
#include <libpq-fe.h>
#include <errorno.h>

class PUT_SQL
{
public:
    PUT_SQL(const char argaction);
    ~PUT_SQL();
    void Put();


protected:
    PGconn   *conn      = NULL;
    PGresult *resp      = NULL;
    char      sql_str[255];
    char      aciton[255];
};
#endif // SQL_H
