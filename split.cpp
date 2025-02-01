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
  /* Add code here */
// WRITE YOUR CODE HERE
  if (in == nullptr){//check if empty
    return;
  }
  split(in->next, odds, evens);//head recursion to operate from the last node to the first node
  if (in->value % 2 == 0){
    in->next = evens;//this ensures odds and evens are from smallest to biggest
    evens = in;//connect in to evens then update evens to the previous node so we can add to the front
  }
  else{
    in->next = odds;
    odds = in;
  }
  in = nullptr;
}

/* If you needed a helper function, write it here */

void print(Node*& head){//for debug to display the list
  if (head == nullptr){
    return;
  }
  //std::cout << head->value << std::endl;
  print(head->next);
}

void destruct(Node*& head){//for debug to free memory
  if (head == nullptr){
    return;
  }
  Node *temp = head->next;
  delete head;
  destruct(temp);
}