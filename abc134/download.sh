#!/bin/sh

echo contestname: 
read name

# https://atcoder.jp/contests/abc171

echo file:
read FILES

echo $FILES | xargs -n 1 sh -c 'cd $1 && oj d $0_$1 && cd ..' $name