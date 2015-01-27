#include <iostream>
using namespace std;


template<typename T>
class BST {
  
public:
  BST(node* root) : root_m(root){}
  

  
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
