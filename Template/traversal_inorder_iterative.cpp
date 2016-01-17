#include <iostream>
#include <stack>

struct node {
	node(int value) : m_value(value), left_child(NULL), right_child(NULL) {}
	int m_value;
	node* left_child;
	node* right_child;
};

class BST {

public:
	BST() {
		node* a = new node(4);
		node* b = new node(2);
		node* c = new node(6);
		node* b_left = new node(1);
		node* b_right = new node(3);
		node* c_left = new node(5);
		node* c_right = new node(7);
		a->left_child = b;
		a->right_child = c;
		b->left_child = b_left;
		b->right_child = b_right;
		c->left_child = c_left;
		c->right_child = c_right;
		root = a;
		cur = root;
	}

	void init() {
		while (cur) {
			history.push(cur);
			cur = cur->left_child;
		}
	}

	int get_next() {
		if (cur != NULL) {
			while (cur) {
				history.push(cur);
				cur = cur->left_child;
			}
		}
			
		cur = history.top();
		history.pop();
		int res = cur->m_value;
		cur = cur->right_child;
	
		return res;
	}

	bool has_next() {
		if (history.empty() && cur == NULL) return false;
		return true;
	}
	
private:
	node* root;
	node* cur;
	std::stack<node*> history;
};

int main() {
	BST* bst = new BST();
	bst->init();
	while (bst->has_next()) {
		std::cout << bst->get_next() << std::endl;
	}
	return 0;
}

