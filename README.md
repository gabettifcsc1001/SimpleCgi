# CGI練習用リポジトリ

## 事前準備

### 必要なもの

- g++コンパイラ
- postgresql
- apache

### 環境構築

#### DB

DBを作成

``` shell
$ cd sql
$ sh install.sh testuser postgres dbtest
```

HomebrewでPostgreSQLをインストールした場合、動作するはず。
他の方法でインストールした場合は、いくつか修正が必要かも。

#### Make

ソースのMake方法

##### Makefileの修正

Makefileの以下を変更する必要があります。

LDFLAGS = -L/usr/local/lib -lpq # postgresのライブラリの場所

`pg_config --libdir`

で-L(表示されるPath) + -lpgを指定する

INCLUDE = -I ./include -I /usr/local/Cellar/postgresql/9.5.1/include/server # postgresのヘッダーファイルの場所

`pg_config --includedir`

で表示されるPathを指定する。

エラーになることが多いので、not found のファイルをfindコマンドで見つけてそのPathを追加で指定してください

##### Make

Makefileの修正がすんだら`make`するだけ

``` shell
$ cd ./app/server
$ make
```

`./app/server/bin`に実行ファイルが出力されます。

### Apache

インストールしてcgi-bin内で.cgiファイルが実行できればOK。

ユーザーでディレクトリでも/var/www/でもどちらでも良いです。

[Apache:CGIの利用設定をする](https://qiita.com/YasuyukiKawai/items/231821dd22a72194b3fb)

## ディレクトリ構成

```
SimpleCgi/
  ├ app/                // アプリケーションディレクトリ
  │   └ client/         // クライアント側ソース
  │   └ server/         // サーバー側ソース
  │       └ src/        // C++ cppファイルディレクトリ
  │       └ include/    // C++ Headerファイルディレクトリ
  ├ sql/                // SQLディレクトリ
  ├ doc/                // ドキュメントディレクトリ
  ├ release/            // Releaseディレクトリ
  │   └ htdocs/
  │   └ cgi-bin/

```

todo srcは(Visual Studio的に言うと)ソリューション、プロジェクト毎にディレクトリ分けしないとね。

## DB設計の方法

以下のリポジトリをcloneかDLして、index.htmlにアクセスして使用ます。

[wwwsqldesigner](https://github.com/ondras/wwwsqldesigner)

**Optionから日本語に設定しておくと以下の説明と一致します。**

### 設計書の読み取り方法

1. 「保存/読み込み」をクリックする
2. 入力欄に'./sql/db_structure.xml'の内容をコピペする
3. 「XMLを読み込み」を押下

見事読み込み完了


### 設計書の保存

1. 「保存/読み込み」をクリックする
2. 「XMLに出力」を押下し、出力された内容を'./sql/db_structure.xml'に上書き保存する

以上。ファイルをコミットすればOK.

### SQLの生成

1. 「保存/読み込み」をクリックする
2. 「SQLを生成』押下するだけ。
