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
	
	void deleteLastNode() {
		Node * p = head;
		Node * last;
		
		while (p->next != NULL) {
			last = p;
			p = p->next;
		}
		last->next = p->next;
		delete p;
	}
	
	void deleteAnyNode(int pos) {
		if (pos < 1) {
			cout << "Invalid position entered!";
		}
		else if (pos == 1) {
			if (head == NULL) {
				cout<<"List is empty!";	
			}
			Node * ptr = head;
			head = head->next;
			delete ptr;
		}
		else {
			Node * ptr = head;
			Node * str;
		
			for(int i = 1; i < pos && ptr!= NULL; i++) {
				str = ptr;
				ptr = ptr->next;
			}
			
			if (ptr == NULL) {
				cout<<"Position is out of list range!";
			}
			
			str->next = ptr->next;
			delete ptr;
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
 	l.insertAtBeginning(55);
 	l.insertAtBeginning(66);
 	l.deleteAnyNode(4);
 	l.deleteLastNode();
 	l.print();
 	
 }
