#!/bin/bash

#Getting the number from command line argument
num=$1

#Initializing the variable 'factorial' to 1
factorial=1

#Calculate the factorial
for ((i = 1; i <= num; i++))
do
  factorial=$((factorial * i))
done

#Print the result
echo "The factorial of $num is $factorial"

