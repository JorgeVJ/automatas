# automatas

This program implements an automaton using a finite state machine (FSM). The main
file, `automata.c`, contains functions for evaluating a string based on the FSM,
and `automata.h` defines the structures and functions related to the automaton.

### Usage

To use the automaton, follow these steps:

1. Include the required header file:

      ```c
      #include "automata.h"

2.  Initialize:
      ```c
      t_automata a;

      automata_init(&a, data);
      alphabet_init(&a);
      errors_init(&a);
      sactions_init(&a);
      tactions_init(&a);
      a.str = "your_input_string";

3.  Use the evaluate function:
      ```c
      int final_state = evaluate(&a);


### Examples

There are some examples inspired on 42 projects.

**So_Long:** A map parsing where each line must start and finish with '1' and only a few allowed characters are permitted.

**PushSwap:** A program designed to sort given numbers, therefore, the parser should only accept digits, spaces and the minus sign.

**MiniShell:** Usually uses two automatons to parse the input, this example shows demonstrates a naive approach to real parsing,
  it needs improvement.


### Links

The [presentation]([URL](https://docs.google.com/presentation/d/1ufalJ-XsxPrYjmpsoG6mrgfZn7XBrcOB6rXR-9xw56w/edit#slide=id.g1ec4f24304a_0_235)https://docs.google.com/presentation/d/1ufalJ-XsxPrYjmpsoG6mrgfZn7XBrcOB6rXR-9xw56w/edit#slide=id.g1ec4f24304a_0_235) given in 42 where these examples where shown and eplained.

Some [videos](https://www.youtube.com/watch?v=0x_dbHi7dEY&list=PLrsxkaDs20ZTCxLHHe66YHhuOxkwJnSMH&index=1) with theoretical content.

A [file](https://holub.com/goodies/compiler/compilerDesignInC.pdf) about Compiler Design in C, useful for those working on the MiniShell project.
      
