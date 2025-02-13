#include <iostream>
#include <vector>
using namespace std;

#include "array_container.h"

int main() {
  array_container a_c;
  std::vector <int> vec = {0, 3, 0, 5, 4, 3, 2, 1, 0};

  //Bibble Sort
  a_c.arr_print(&vec, "Before");
  a_c.arr_bubble_sort(&vec);

  //Move 0s to the top keeping the order the same
  a_c.arr_move_0s(&vec);
}
