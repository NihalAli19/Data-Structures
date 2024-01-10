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
	
	void insertAfterNode(int data, int pos) {
		if (pos < 1) {
			cout << "Invalid position entered!";
		}
		else if (pos == 1) {
			Node * newNode = new Node(data);
			newNode->next = this->head;
			this->head = newNode;
		}
		else {
			Node * ptr = head;
			Node * newNode = new Node(data);
		
			for(int i = 1; i < pos; i++) {
				ptr = ptr->next;
				if (i == (pos - 1)) {
					newNode->next = ptr->next;	
					ptr->next = newNode;
				}
			}
		}
	}
	
	void print() {
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
 	l.insertAtBeginning(99);
 	l.insertAtBeginning(45);
 	l.insertAfterNode(110, 3);
 	l.insertAfterNode(411, 4);
 	l.insertAfterNode(20,5);
 	l.print();
 	
}