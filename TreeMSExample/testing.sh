#!/bin/bash

# Example using a range of numbers
while true
do
	gcc main.c inorder.c ../automata/automata.c tokenizer/ta_ainit.c tokenizer/ta_actions.c organizer/oa_ainit.c organizer/oa_actions.c ../libft/libft.a && ./a.out
	sleep 2
	clear
done
