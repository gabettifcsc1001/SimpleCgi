/**
 * 課題ステップ2
 * tb_testテーブルへの索引クラス
 */

// #ifndef TBTESTINDEX_H
// #define TBTESTINDEX_H
//
// class tbTestIndex
// {
// public:
//   /**
//    * [tbTestIndex description]
//    */
//   tbTestIndex();
//
//   /**
//    * [tbTestIo description]
//    */
//   ~tbTestIndex();
//
//   /**
//    * tbTestIoをnewする
//    * @return newしたtbTestIoのPointer
//    */
//   tbTestIo *Alloc();
//
//   /**
//    * tbTestIoの解放
//    * @param obj 解放するtbTestIoのPointer
//    */
//   void Free(tbTestIo *obj);
//
//   /**
//    * DBから全データを取得し、1行分のデータをAlloc()したtbTestIoのメンバ変数に格納し、
//    * mListに追加していく。追加した数 = mSizeになるようにmSizeの値も変更する
//    *
//    * Getすると、Select文で取得した行数 = mListに追加された数 = mSize となる。
//    */
//   int Get(); // -> SELECT  FROM tb_test;
//
//   /**
//    * リストのindex番目のデータを取得する
//    *
//    * mListのindex番目のデータを返す
//    *
//    * @param  index 要素数
//    * @return       tbTestIo
//    */
//   tbTestIo *Item(int index);
//
//   /**
//    * メンバ変数のIDを取得する
//    * @return {int} id
//    */
//   int getSize() { return mSize; }
//
// protected:
//   tbTestIo  *mList[100];  // 一覧データ
//   int       mSize;        // データ数
// };
//
// #endif
