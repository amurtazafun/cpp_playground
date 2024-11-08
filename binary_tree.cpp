#include <iostream>
using namespace std;

#include "binary_tree.h"

int main() {
  binary_tree bt;
  bt.insert(10);
  bt.insert(5);
  bt.insert(3);
  bt.insert(7);
  bt.insert(1);
  bt.insert(9);
  bt.insert(2);
  bt.insert(8);
  bt.insert(0);
  bt.insert(6);
  bt.insert(4);
  bt.insert(15);
  bt.insert(13);
  bt.insert(17);
  bt.insert(11);
  bt.insert(19);
  bt.insert(12);
  bt.insert(18);
  bt.insert(20);
  bt.insert(16);
  bt.insert(14);
  bt.print_tree();


  BT_Node* elem = bt.search(10);
           elem = bt.search(16);
  return 0;
}
