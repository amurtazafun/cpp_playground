#include <iostream>
#include <vector>
using namespace std;



void function_impl(int val) {
  //CmInfo(0, ":C::flp_data_mem_read_impl Callback called!\n");     
  cout << "Function Implementation called val:"<< val << endl;
}


typedef void (*func_ptr_typ)(int val);



struct flp_cb_info_s
{
	func_ptr_typ  fptr;
};


int main() {
  struct flp_cb_info_s cb_info;
  cb_info.fptr = &function_impl;

  struct flp_cb_info_s *cb_info_ptr = &cb_info;
  cout << "Calling fptr" << endl;
  (*cb_info_ptr->fptr)(10);

  (*cb_info.fptr)(12);

}
