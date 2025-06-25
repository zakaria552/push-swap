#!/bin/bash
generator="./RaNGer"
push_swap="./push_swap"
checker="./checker"
moves="./moves"
result="./result"

rm -rf $moves $result

nums=$($generator $1)
$push_swap $nums > $moves
< $moves $checker $nums > $result

num_of_moves=$(cat $moves | wc -l)
r=$(cat $result)

echo "Test: $1 numbers"
#echo " $nums"
echo "Moves: $num_of_moves"
echo "Result: $r" 
#cat $moves

rm -rf $moves $result