#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	struct Node* left, *right, *parent;
};

struct Node *createNode(int item)
{
	struct Node *temp =  (struct Node *)malloc(sizeof(struct Node));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

struct Node* getMin(struct Node * root) {

	while (root != NULL && root->left != NULL) {
		root = root->left ;
	}
	return root;
}

struct Node* getMax(struct Node * root) {
	while (root != NULL && root->right != NULL) {
		root = root->right ;
	}
	return root;
}


struct Node * deleteNode(struct Node * root, int k) {

	if (root == NULL)
	{
		return root;
	}
	if (root->data > k)
	{
		root-> left = deleteNode(root -> left, k);
	} else if (root->data < k) {
		root-> right = deleteNode(root -> right, k);
	} else {

		if (root-> left == NULL ) {

			struct Node* tmp = root-> right;
			free(root);
			return tmp;

		} else if (root-> right == NULL) {
			struct Node* tmp = root-> right;
			free(root);
			return tmp;
		} else {
			struct Node * tmp = getMin(root);
			root-> data = tmp-> data;
			root-> right = deleteNode(	root-> right , k);
		}
	}
	return root;
}

struct Node * insertNode(struct Node * root, int k) {
	if (root == NULL ) {
		struct Node * node = createNode(k);
		return node;

	}
	if (root->data > k)
	{
		root->left = insertt(root->left, k);
	} else {
		root->right = insertt(root->right, k);
	}
	return root;
}


struct Node * search (struct Node * root, int key) {
	if (root == NULL ||  root->data == key )
	{
		return root;
	}

	if (root -> data > key)
	{
		return search ( root -> left,  key);
	} else {
		return search ( root -> right,  key);
	}

}


int main() {
#ifndef ONLINE_JUDGE

//for getting input from input.txt
	freopen("../../../env/input.txt", "r", stdin);

//for writting output to output.txt
	freopen("../../../env/output.txt", "w", stdout);
#endif





	cout << "Hello";
	return 0;
}