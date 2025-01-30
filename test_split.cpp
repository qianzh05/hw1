/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/
#include "split.h"
#include <cstddef>

int main(int argc, char* argv[])
{
    Node* head = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5, nullptr)))));

    Node* odd = NULL;
    Node* even = NULL;
    split(head, odd, even);

    print(odd);
    print(even);

    deleteList(odd);
    deleteList(even);
}
