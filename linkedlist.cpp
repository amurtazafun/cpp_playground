//Linkedlist problem 1
//2 linkedlists (node by node) and store in a third linkedlist. Handle carry
//
#include <iostream>
using namespace std;

#include "linkedlist.h"

int main() {
  linkedlist l1, l2, lsum;
  Node* l1_ptr;
  Node* l2_ptr;
  Node* lsum_ptr;

  l1.push_back(9);
  l1.push_back(9);
  l1.push_back(9);
  l1.push_back(9);
  l1.push_back(9);
  l1.push_back(9);
  l1.push_back(9);
  l1.push_back(9);
  l1.push_back(9);
  l1.print_ll();

  l2.push_back(1);
  l2.push_back(1);
  l2.push_back(1);
  l2.push_back(1);
  l2.push_back(1);
  l2.push_back(1);
  l2.push_back(1);
  l2.push_back(1);
  l2.push_back(1);
  l2.print_ll();

  //Linkedlist problem 1
  //2 linkedlists (node by node) and store in a third linkedlist. Handle carry
  lsum.head = lsum.make_new_node(0); //Init linkedlist with data 0
  l1_ptr = l1.head;
  l2_ptr = l2.head;
  lsum_ptr = lsum.head;
  int carry=0;
  int sum;

  while ((l1_ptr != NULL) && (l2_ptr != NULL)) {
    //do while both l1 and l2 have elments
    sum = (l1_ptr->data + l2_ptr->data + carry) % 10;
    carry = (int)((l1_ptr->data + l2_ptr->data + carry)/10);
    lsum_ptr->data=sum;
    lsum_ptr->next = lsum.make_new_node(0);
  
    l1_ptr = l1_ptr->next;
    l2_ptr = l2_ptr->next;
    lsum_ptr = lsum_ptr->next;
  }

  while (l1_ptr != NULL) {
    //l1 has more elements
    sum = (l1_ptr->data + carry) % 10;
    carry = (int)((l1_ptr->data + carry)/10);
    lsum_ptr->data=sum;
    lsum_ptr->next = lsum.make_new_node(0);
  
    l1_ptr = l1_ptr->next;
    lsum_ptr = lsum_ptr->next;

  } 
  
  while (l2_ptr != NULL) {
    //l2 has more elements
    sum = (l2_ptr->data + carry) % 10;
    carry = (int)((l2_ptr->data + carry)/10);
    lsum_ptr->data=sum;
    lsum_ptr->next = lsum.make_new_node(0);
  
    l2_ptr = l2_ptr->next;
    lsum_ptr = lsum_ptr->next;

  } 
  
  if (carry != 0) {
    //Neither l1 and l2 have remaining elements, but there is a remaining carry
    lsum_ptr->data = carry;

  }

  lsum.print_ll();

}
