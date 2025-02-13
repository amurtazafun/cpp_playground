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
};

void array_container::arr_bubble_sort(std::vector<int>* vec) {
  int tmp; 
  for (int i=0; i<vec->size()-1; i++) {
    for (int j=i+1; j<vec->size(); j++) {
      if (vec->at(i) > vec->at(j)) { //Ascending order
        tmp = vec->at(i);
        vec->at(i) = vec->at(j);
        vec->at(j) = tmp;
      }
    }
    
  }
}

void array_container::arr_print(std::vector<int>* vec, const char * msg) {
  cout << "arr_print: " << msg << " - size " << vec->size() << endl;
  for (int i=0; i<vec->size(); i++) {
      cout << vec->at(i) << "  ";
  }
  cout << endl;
}
