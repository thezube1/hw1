/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

int main(int argc, char* argv[])
{
  Node* in = new Node(1, nullptr);
  in->next = new Node(2, nullptr);
  in->next->next = new Node(3, nullptr);
  in->next->next = new Node(4, nullptr);

  Node* odds = nullptr;
  Node* evens = nullptr;

  split(in, odds, evens);

  std::cout << "Odds: ";
  for (Node* o = odds; o != nullptr; o = o->next) {
    std::cout << o->value << " ";
  }

  std::cout << "Evens: ";
  for (Node* e = evens; e != nullptr; e = e->next) {
    std::cout << e->value << " ";
  }

  std::cout << "\n";

  return 0;
}
