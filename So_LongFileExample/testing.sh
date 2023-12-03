#!/bin/bash

# Example using a range of numbers
while true
do
	gcc main.c ../automata/automata.c ainit.c print_actions.c actions.c ../libft/libft.a && ./a.out
	sleep 2
	clear
done
