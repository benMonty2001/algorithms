//BINARY-TREE (bfs)

#pragma once

using namespace std;

#include <queue>
#include <iostream>

#include "car_utils.hpp"

class Node {
	public:
		Car data;
		Node *left;
		Node *right;
};

Node* add_node(Car data){
	Node *new_node = new Node;
	new_node->data = data;
	new_node->left = new_node->right = NULL;

	return new_node;
}

void insert_node(Node **rootptr, Car data){
	Node *root = *rootptr;

	//terminating instance

	if(!root){
		*rootptr = add_node(data);
		return;
	}

	//recursive instances

	if(data.year < root->data.year){
		return insert_node(&(root->left), data);
	}
	if(data.year > root->data.year){
		return insert_node(&(root->right), data);
	}

	return;
}

Node search_tree(Node *root, int data){
	
	//terminating instances

	Node FAIL;
	FAIL.data = { 0 };
	FAIL.left = FAIL.right = NULL;

	if(!root){
		return FAIL;
	}
	if(root->data.year == data){
		return *root;
	}

	//recursive instances

	if(data < root->data.year){
		return search_tree(root->left, data);
	}
	if(data > root->data.year){
		return search_tree(root->right, data);
	}

	return FAIL;
}

void bft(Node *root){
	if(!root){
		return;
	}

	queue <Node> c_queue;
	c_queue.push(*root);

	while(!c_queue.empty()){

		Node temp = c_queue.front();

		c_queue.pop();

		cout << temp.data << endl;
		
		if(temp.left){	
			c_queue.push(*(temp.left));
		}
		if(temp.right){
			c_queue.push(*(temp.right));
		}
	}
}
void deallocate_tree(Node *root){
	if(root){
		Node *temp_left = root->left;
		Node *temp_right = root->right;

		delete(root);

		deallocate_tree(temp_left);
		deallocate_tree(temp_right);
	}
}
