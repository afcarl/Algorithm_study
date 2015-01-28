// Author: Oh2

#include <iostream>
using namespace std;


template<typename T>
class BST {
  
public:
  BST(node* root) : root_m(root){}
  node* search(T x) {
    
  }
  node* insert(T x) {
    
  }
  node* delete(T x) {

  }
  node* pred(node* x) {

  }
  node* succ(node* x) {

  }
  
  
  
private:
  struct node {
    node* left_m;
    node* right_m;
    T value_m;
  };
  node* root_m;
};


int main() {

  return 0;
}
