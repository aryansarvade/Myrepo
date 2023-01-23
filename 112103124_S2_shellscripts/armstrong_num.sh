#!/bin/bash

#Getting the number from command line argument
num=$1

#Original number
originalNum=$num

#Initializing sum
sum=0

#Get the number of digits in the number
no_of_digits=${#num}

#Checking whether the number is Armstrong number or
while [ $num -gt 0 ]
do
  digit=$((num % 10))
  digit=$((digit ** no_of_digits))
  sum=$((sum + digit))
  num=$((num / 10))
done

if [ $sum -eq $originalNum ]
then
  echo "$originalNum is an Armstrong number"
else
  echo "$originalNum is not an Armstrong number"
fi

