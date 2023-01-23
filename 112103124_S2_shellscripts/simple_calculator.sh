#!/bin/bash

#Function for addition
addition() {
  local result=$(( $1 + $2 ))
  echo "The result of $1 + $2 is $result"
}

#Function for subtraction
subtraction() {
  local result=$(( $1 - $2 ))
  echo "The result of $1 - $2 is $result"
}

#Function for multiplication
multiplication() {
  local result=$(( $1 * $2 ))
  echo "The result of $1 * $2 is $result"
}

#Function for division
division() {
  local result=$(( $1 / $2 ))
  echo "The result of $1 / $2 is $result"
}

#Calculator Interface
echo -e "Simple Calculator\n"
echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"
echo "5. Exit"

#reading the input
read -p "Enter your choice: " choice

#reading the first number
read -p "Enter the first number: " n1

#reading the second number
read -p "Enter the second number: " n2

# Perform the corresponding operation based on the user's choice
case $choice in
  1) addition $n1 $n2;;
  2) subtraction $n1 $n2;;
  3) multiplication $n1 $n2;;
  4) division $n1 $n2;;
  5) exit;;
  *) echo "Invalid choice";;
esac

