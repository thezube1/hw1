/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{

  // base case, 'in' is null (no more items)
  if (in == nullptr) {
    return;
  }

  // get the next node and then continue recursive step
  Node* curr_node = in;
  in = in->next;
  curr_node->next = nullptr;

  split(in, odds, evens);  

  // check if the current value is even or odd with modulo
  if (curr_node->value % 2 == 0) {
    // add to evens linked list
    curr_node->next = evens;
    evens = curr_node;
  } else {
    // add to odds linked list
    curr_node->next = odds;
    odds = curr_node;
  }
  
}

/* If you needed a helper function, write it here */
