#!/usr/bin/env bash

if [ $# -le 2 ]; then
  echo 'usage: install.sh username postgres dbname'
  exit
fi

username=$1
postgres=$2
dbname=$3

# postgresユーザーでログイン
# がべくんは必要かも↓
# echo $postgres | su - postgres

# 既存のテーブルを削除
dropdb $dbname

# testuserの作成
dropuser $username
createuser -s $username

# データベース作成
createdb -O $username $dbname -E 'UTF8'

# testuserのパスワード変更
psql $dbname -c "ALTER USER $username WITH PASSWORD '$username'";

# 初期処理
psql -f ./init.sql -U $username -d $dbname -h localhost

# テーブル作成
psql -f ./create.sql -U $username -d $dbname -h localhost
