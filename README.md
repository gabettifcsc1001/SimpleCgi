<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Table of Contents**  *generated with [DocToc](https://github.com/thlorenz/doctoc)*

- [CGI練習用リポジトリ](#cgi%E7%B7%B4%E7%BF%92%E7%94%A8%E3%83%AA%E3%83%9D%E3%82%B8%E3%83%88%E3%83%AA)
  - [事前準備](#%E4%BA%8B%E5%89%8D%E6%BA%96%E5%82%99)
    - [必要なもの](#%E5%BF%85%E8%A6%81%E3%81%AA%E3%82%82%E3%81%AE)
    - [環境構築](#%E7%92%B0%E5%A2%83%E6%A7%8B%E7%AF%89)
      - [DB](#db)
      - [Make](#make)
        - [Makefileの修正](#makefile%E3%81%AE%E4%BF%AE%E6%AD%A3)
        - [Make](#make-1)
      - [Apache](#apache)
        - [ApacheでCGIを実行する方法(Mac)](#apache%E3%81%A7cgi%E3%82%92%E5%AE%9F%E8%A1%8C%E3%81%99%E3%82%8B%E6%96%B9%E6%B3%95mac)
  - [ディレクトリ構成](#%E3%83%87%E3%82%A3%E3%83%AC%E3%82%AF%E3%83%88%E3%83%AA%E6%A7%8B%E6%88%90)
  - [DB設計の方法](#db%E8%A8%AD%E8%A8%88%E3%81%AE%E6%96%B9%E6%B3%95)
    - [設計書の読み取り方法](#%E8%A8%AD%E8%A8%88%E6%9B%B8%E3%81%AE%E8%AA%AD%E3%81%BF%E5%8F%96%E3%82%8A%E6%96%B9%E6%B3%95)
    - [設計書の保存](#%E8%A8%AD%E8%A8%88%E6%9B%B8%E3%81%AE%E4%BF%9D%E5%AD%98)
    - [SQLの生成](#sql%E3%81%AE%E7%94%9F%E6%88%90)
  - [参考](#%E5%8F%82%E8%80%83)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

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

#### Apache

インストールしてcgi-bin内で.cgiファイルが実行できればOK。

ユーザーでディレクトリでも/var/www/でもどちらでも良いです。

[Apache:CGIの利用設定をする](https://qiita.com/YasuyukiKawai/items/231821dd22a72194b3fb)

##### ApacheでCGIを実行する方法(Mac)

Apacheの設定ファイル内を編集する

``` shell
$ vim /etc/apache2/httpd.conf
```

1: httpd.confファイル内の以下のコメントアウトを外す

``` txt
LoadModule cgi_module libexec/apache2/mod_cgi.so
```

2: < Directory "/Library/WebServer/CGI-Executables" >を以下に修正する

``` txt
<Directory "/Library/WebServer/CGI-Executables">
    AllowOverride None
    Require all granted
    Options +ExecCGI
    AddHandler cgi-script .cgi
</Directory>
```

3: Apacheの再起動

``` shell
$ sudo apachectl restart
```

4: /Library/WebServer/CGI_excutables/内にモジュール(text.cgiとする)を置く

5: ブラウザで'localhost/cgi-bin/text.cgi'にアクセスする

---

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

---

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
3. 出力した内容を`./sql/create.sql`にコピペして保存する

## 参考

- [wwwsqldesigner](https://github.com/ondras/wwwsqldesigner)
- [ディレクトリ構成図を書くときに便利な記号](https://qiita.com/paty-fakename/items/c82ed27b4070feeceff6)
