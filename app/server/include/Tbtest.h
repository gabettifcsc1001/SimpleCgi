#include <string.h>
#include <stdlib.h>
#include <libpq-fe.h>
#include <postgres.h>

class tbTestIo
{
public:
  /**
   * [tbTestIo description]
   */
  tbTestIo();

  /**
   * [tbTestIo description]
   */
  ~tbTestIo();

  /**
   * メンバ変数に値をセットする
   *
   * filedName = "id" -> メンバ変数のmIdに値をセットする
   * fieldName = "name" -> メンバ変数のmNameに値をセットする
   *
   * @param fieldName [description]
   * @param value     [description]
   */
  int Set(const char *fieldName, const char *value);

  /**
   * DBに1データ追加する
   */
  int Add(); // -> INSERT INTO tb_test VALUES id, name (1, "tachibana");

  /**
   * DB内のIDが一致するデータを更新する
   */
  int Mod(); // -> UPDATE tb_test

  /**
   * DB内のIDが一致するデータを削除する
   */
　int Del(); // -> DELETE FROM tb_test WHERE id="";

  /**
   * DBからIDが一致するデータを取得し、メンバ変数に値をセットする
   * @param id [description]
   */
  int Get(const char *id); // -> SELECT  FROM tb_test WHERE id="";

  /**
   * メンバ変数のIDを取得する
   * @return {int} id
   */
  int getId() { return mId; }

  /**
   * メンバ変数のNameを取得する
   * @return
   */
  char *getName() { return mName; }

protected:
  int     mId;          // ID
  char    mName[255];   // Name
};
