#include <iostream>
#include <vector>
using namespace std;

#include "array_container.h"

int main() {
  array_container a_c;
  std::vector <int> vec = {5, 4, 3, 2, 1, 0};

  a_c.arr_print(&vec, "Before");
  a_c.arr_bubble_sort(&vec);

  a_c.arr_print(&vec, "After");
}
