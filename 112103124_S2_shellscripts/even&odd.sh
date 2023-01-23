#!/bin/bash

#Get the number from command line argument
num=$1
#Check if the number is even or odd
if [ $((num % 2)) -eq 0 ]
then
  echo "$num is an even number"
else
  echo "$num is an odd number"
fi

