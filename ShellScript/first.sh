#! /bin/bash

# Echo for printing
echo "Hello"

# Variable
NAME="AKASH"
echo "My name is $NAME"

#User in put
read -p "Enter your name" NAMEE
echo "$NAMEE"

# if statement

if [ "$NAMEE" == "AKASH" ]
then
 echo "Matched"
elif [ "$NAMEE" == "da" ]
then
 echo "da"
else
 echo "ska"
fi


