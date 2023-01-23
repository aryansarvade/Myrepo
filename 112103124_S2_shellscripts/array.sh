#!/bin/bash

#Declaration of an array
array=( "A" "B" "C" )

#Print the entire array
echo "Entire Array:"
echo ${array[@]}

#Print the first element
echo "First element:"
echo ${array[0]}

#Print the second element
echo "Second element:"
echo ${array[1]}

#Print the third element
echo "Third element:"
echo ${array[2]}

#Print the number of elements in the array
echo "Number of elements in the array:"
echo ${#array[@]}

#Adding an element to the array
array+=( "date" )

#Printing the entire array
echo "Array after adding an element:"
echo ${array[@]}

