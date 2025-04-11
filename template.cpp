#include <iostream>
#include <vector>
using namespace std;


class base_class {
  public:
      virtual size_t W_val() {return 0;}
      virtual size_t W_Wlst_siz() {return 0;}
      virtual void print_W() {}


};

template <size_t L>
class sub_type {
  public:
    sub_type() {
    }

    static size_t L_val() {return L;}

};




template <size_t W>
class template_type : public base_class {
  public:
    sub_type <((W+63)>>6)> s;

    template_type() {
    }

    void print_W() {
        cout << "W=" << W << endl;
        cout << "L=" << s.L_val() << endl;
    }
    virtual size_t W_val() {return W;}
    virtual size_t W_Wlst_siz() {return ((W+63) >> 6);}

};


int main() {
  base_class * b;

  template_type<132> * t;
  t = new template_type<132>;

  b = t;


  b->print_W();
  cout << "W_val W=" << b->W_val() << endl;

  int ARR[b->W_Wlst_siz()];
  for (int i=0; i<(int)b->W_Wlst_siz(); i++) {
      ARR[i] = i+10;
  cout << "ARR[" << i << "]=" << ARR[i] << endl;
  }


  template_type<10> t2;
  t2.print_W();


}
