#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class array_container {
  public:
    array_container() {
    }

    void arr_print(std::vector<int>* vec, const char * msg);
    void arr_bubble_sort(std::vector<int>* vec);
    void arr_move_0s(std::vector<int>* vec);
};

void array_container::arr_bubble_sort(std::vector<int>* vec) {
  int tmp; 
  for (size_t i=0; i<vec->size()-1; i++) {
    for (size_t j=i+1; j<vec->size(); j++) {
      if (vec->at(i) > vec->at(j)) { //Ascending order
        tmp = vec->at(i);
        vec->at(i) = vec->at(j);
        vec->at(j) = tmp;
      }
    }
    
  }
  arr_print(vec, "After arr_bubble_sort ");
}

//Move 0s to the top of the array keeping the order the same
void array_container::arr_move_0s(std::vector<int>* vec) {
  size_t last_0_idx = vec->size();
  for (size_t i=0; i<last_0_idx; i++) {
    if (vec->at(i)==0) {
      last_0_idx--;
      for (size_t j=i; j<last_0_idx; j++) {
        vec->at(j) = vec->at(j+1);
      }
      vec->at(last_0_idx) = 0;
      if (vec->at(i)==0) {
          i--;
      }

    }
  }
  arr_print(vec, "After arr_move_0s ");
}


void array_container::arr_print(std::vector<int>* vec, const char * msg) {
  cout << "arr_print: " << msg << " - size " << vec->size() << endl;
  for (size_t i=0; i<vec->size(); i++) {
      cout << vec->at(i) << "  ";
  }
  cout << endl;
}
