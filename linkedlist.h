#include <iostream>
#include <iomanip>
using namespace std;


struct Node {
  Node* next;
  int data;
};

class linkedlist {
  public:
    Node* head;

    linkedlist() {
      head = NULL;
    }
    ~linkedlist() {
      destroy_ll();
    }
    void destroy_ll();

    void print_ll();
    void push_back(int data);
    void push_front(int data);
    Node* make_new_node(int data);
};


void linkedlist::print_ll() {
  cout << "Printing ll" << endl;
  Node* n = head;
  while (n != NULL) {
    cout << n->data << "\t"; 
    n=n->next;
  }
  cout << endl;
}


void linkedlist::destroy_ll() {
  cout << "Destroying ll" << endl;
  Node* n = head;
  Node* p; //Previous pointer
  if (n != NULL) {
    p = n;
    n = n->next;
    delete p;
  }
}


Node* linkedlist::make_new_node(int data) {
  Node* n = new Node;
  n->data = data;
  n->next=NULL;
  return (n);
}


void linkedlist::push_back(int data) {
  Node* e = make_new_node(data);
  if (head == NULL) {
    head = e;
  } else {
    Node *n = head;
    while (n->next != NULL) {
      n = n->next;
    }
    n->next = e;
  }
}


void linkedlist::push_front(int data) {
  Node* e = make_new_node(data);
  e->next = head;
  head = e;
}
