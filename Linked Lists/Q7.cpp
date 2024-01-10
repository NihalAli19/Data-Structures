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
	
	void checkOddEven() {
    if (head == NULL || head->next == NULL) {
        return;  
    }

    Node* evenStart = NULL;
    Node* evenEnd = NULL;
    Node* oddStart = NULL;
    Node* oddEnd = NULL;

    Node* currentNode = head;

    while (currentNode != NULL) {
        int data = currentNode->data;

        if (data % 2 == 0) { 
            if (evenStart == NULL) {
                evenStart = currentNode;
                evenEnd = currentNode;
            }
			else {
                evenEnd->next = currentNode;
                evenEnd = currentNode;
            }
        } else { 
            if (oddStart == NULL) {
                oddStart = currentNode;
                oddEnd = currentNode;
            } 
			else {
                oddEnd->next = currentNode;
                oddEnd = currentNode;
            }
        }

        currentNode = currentNode->next;
    }

    if (evenStart == NULL) {
        head = oddStart;
    } 
	else {
        evenEnd->next = oddStart;
        head = evenStart;
    }

    if (oddEnd != NULL) {
        oddEnd->next = NULL;
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
 	SingleLinkedList l(12);
 	l.insertAtBeginning(15);
 	l.insertAtBeginning(6);
 	l.insertAtBeginning(9);
 	l.insertAtBeginning(3);
 	l.checkOddEven();
	l.print();
 	
 }
