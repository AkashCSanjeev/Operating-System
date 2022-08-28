# /usr/bin/bash

echo Enter Number :
read N

num=1

for((i = 1 ; i <= $N ; i++)){
num=$((num*i))
}

echo $num
