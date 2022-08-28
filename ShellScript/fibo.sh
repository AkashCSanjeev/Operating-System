#! /usr/bin/bash

echo Enter number
read N

first=0
second=1

if [ $N == 1 ]
then
third=0
else
for((i = 0 ; i < $N ; i++)){
third=$((first+second))
first=second
second=third
}
fi

echo $third

