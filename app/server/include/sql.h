//
// SQL発行クラス
//

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
    // コンストラクタ
    PUT_SQL(const char argaction);
    PUT_SQL(const char argaction int id, char *buf);
    // SQLの発行
    void Put();
    // デストラクタ
    ~PUT_SQL();


protected:
  　 // メンバ変数宣言
    PGconn   *conn      = NULL;
    PGresult *resp      = NULL;
    char      sql_str[255];　　　// SQL文格納
    char      aciton[255];      // パラメータ格納
    int       m_id;
    char      m_buf[255];
};
#endif // SQL_H
