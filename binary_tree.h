#include <iostream>
#include <iomanip>
using namespace std;


struct BT_Node {
  BT_Node* left;
  BT_Node* right;
  int data;
};

class binary_tree {
  public:
    binary_tree() {
      root = NULL;
    }
    ~binary_tree() {
      destroy_tree();
    }
    void print_tree();
    void destroy_tree();
    void insert (int data);
    BT_Node* search(int data);

  private:
    BT_Node* make_new_node(int data);
    void print_tree(BT_Node* leaf, int indent);
    void destroy_tree(BT_Node* leaf);
    void insert(int key, BT_Node* leaf);
    BT_Node* search(int data, BT_Node* leaf, int level);

    BT_Node* root;
};

void binary_tree::print_tree() {
  cout << "Printing Tree" << endl;
  print_tree(root, 0); 
}

void binary_tree::print_tree(BT_Node* leaf, int indent) {
  if (leaf != NULL) {
    print_tree(leaf->right, indent+4); 
    cout << setw(indent) << leaf->data << endl;
    print_tree(leaf->left, indent+4); 
  }
}

void binary_tree::destroy_tree() {
  cout << "Destroying tree" << endl;
  destroy_tree(root); 
}

void binary_tree::destroy_tree(BT_Node* leaf) {
  if (leaf != NULL) {
    destroy_tree(leaf->left); 
    destroy_tree(leaf->right);
    delete leaf;
  }
}


BT_Node* binary_tree::make_new_node(int data) {
  BT_Node* n = new BT_Node;
  n->data = data;
  n->left=n->right=NULL;
  return (n);
}

void binary_tree::insert(int data, BT_Node* leaf) {
  //Case where root is null is taken care of in the wrapper 
  //public function
  if (data < leaf->data) { //New element goes on the left
    if (leaf->left == NULL) {
      leaf->left = make_new_node(data);
    } else {
      insert(data, leaf->left);
    }
  } else { //New node goes on the right
    if (leaf->right == NULL) {
      leaf->right = make_new_node(data);
    } else {
      insert(data, leaf->right);
    }
  }
}

void binary_tree::insert(int data) {
  if (root==NULL) {
    root = make_new_node(data);
  } else {
    insert(data, root);
  }
}

BT_Node* binary_tree::search(int data) {
  return (search(data, root, 0));

}

BT_Node* binary_tree::search(int data, BT_Node* leaf, int level) {
  if (leaf == NULL) {
    cout << "Element " << data << " Not found in tree" << endl;
    return (NULL);
  } else if (data < leaf->data) {
    return (search(data, leaf->left, level+1));
  } else if (data > leaf->data) {
    return (search(data, leaf->right, level+1));
  } else { //leaf is the matching element
    cout << "Found " << data << " In tree at level " << level << endl;
    return (leaf);
  }

}

