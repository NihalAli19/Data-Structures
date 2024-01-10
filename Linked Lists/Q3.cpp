#include <iostream>
using namespace std;

class Node {
	public: 
 		
 		int data;
 		Node * next;
 		
		Node() { 
 			this->data = 0;
 			this->next = NULL;
 		}
 		
 		Node( int d) {
 			this->data = d;
 			this->next = NULL;
		}
};

class SingleLinkedList {
	public: 
	Node * head;
	
	SingleLinkedList(int d) {
		head = new Node(d);  // new dynamically creates a node using a dynamic memory allocation
	}
	
	void insertAtBeginning(int data) {
		Node * newNode = new Node(data);
		newNode->next = this->head;
		this->head = newNode;
	}
	
	void print()  {
		Node * currentNode = head;
		currentNode = this->head;
		while(currentNode != NULL) {
			cout << currentNode->data <<endl<<endl; // New line after each value
			currentNode = currentNode->next;
		}
	}
};

int main() {
 	SingleLinkedList l(786);
 	l.insertAtBeginning(110);
 	l.print();
 }
