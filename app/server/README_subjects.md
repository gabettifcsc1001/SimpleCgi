<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Table of Contents**  *generated with [DocToc](https://github.com/thlorenz/doctoc)*

- [サーバー側 課題](#%E3%82%B5%E3%83%BC%E3%83%90%E3%83%BC%E5%81%B4-%E8%AA%B2%E9%A1%8C)
  - [ステップ1](#%E3%82%B9%E3%83%86%E3%83%83%E3%83%971)
  - [ステップ2](#%E3%82%B9%E3%83%86%E3%83%83%E3%83%972)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# サーバー側 課題

## ステップ1

*簡単なIOを作ろう*

次のようなテーブルが一つ作成する。

``` sql
create table tb_test(id int,name varchar(256));
```

*課題:*

このテーブルへのIOを作成しなさい。

IOとは、DBから値を取得、値を登録、更新、削除できるクラスのこと

*前提：*

クラスtbTestIoを完成させること。(./include/tbTestIo.hにあります)

tbTextIo内のメソッド説明は以下である。

- Setメソッドで、メンバ変数に値をセットすることができること
- Addメソッドで、DBのtb_testテーブルに１データ登録する。登録する値は、メンバ変数の価を使用すること
- Modメソッドで、DBのtb_testテーブルのIDが一致するデータを更新する。更新するデータはメンバ変数の値を使用すること
  - IDは引数で渡しても良い
- Delメソッドで、DBのtb_testテーブルのIDが一致するデータを削除する。
- Getメソッドで、DBのtb_testテーブルのIDが一致するデータを取得し、メンバ変数に値をセットすること


## ステップ2

*簡単な一覧クラスを作ろう*

*課題:*

ステップ1のtb_testテーブルの値を一覧で取得できるクラスを作成しなさい。

索引クラスとしばしば呼びれる物です。

*前提:*

クラスtbTestIndexを完成させること(./include/tbTestIndex.hにあります)

tbTestIndexのメソッド説明は以下になります。

- Allocメソッドで、tbTestIoをnewしたPointerを返す
- Freeメソッドで、引数のPointerをdeleteする
- Getメソッドで、SQLを発行し、１行データ分をAllocメソッドで作成したtbTestIoのメンバ変数に保存する。
AllocしたtbTestIoは、メンバ変数のmListに追加する。追加したtbTestIo分 = メンバ変数のmSizeにしておくこと。
- Item(int index)メソッドは、mListに保存されているindex番目のtbTestIoを返す。
