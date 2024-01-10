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
	
	SingleLinkedList() {
		this->head = NULL ;  // new dynamically creates a node using a dynamic memory allocation
	}
	
	void insertAtBeginning(int data) {
		Node * newNode = new Node(data);
		newNode->next = this->head;
		this->head = newNode;
	}

	void checkPalindromeNum() {
		int n = 0;
		cout<<"Enter the amount of digits you want to enter: ";
		cin>>n;
		
		cout<<"Enter your number:"<<endl;
		int num = 0;
		
		Node * newNode;
		for (int i = 0; i < n; i++) {
			cin>>num;
			newNode->data = num;
			newNode = newNode->next;
		}
		
		
	}
	
	void insertAtEnd(int nodeVal) {

			Node *newNode = new Node(nodeVal);

			if (head == NULL) {

				head = newNode;

			} else {

				Node *ptr = head;

				while (ptr->next != NULL) {
					ptr = ptr->next;
				}

				ptr->next = newNode;
				newNode->next = NULL;

			}

		}

		bool checkPalindrome(Node *tempHead, int n) {

			SingleLinkedList reverseList;

			for (int i = n ; i >= 1 ; i--) {
				Node *ptr = tempHead;
				for (int j = 1 ; j < i ; j++) {
					ptr = ptr->next;
				}
				reverseList.insertAtEnd(ptr->data);
			}
			
			Node *checkPtr1 = tempHead;
			Node *checkPtr2 = reverseList.head;
			
			for (int i = 1 ; i <= n ; i++) {
				if (checkPtr1->data == checkPtr2->data) {
					checkPtr1 = checkPtr1->next;
					checkPtr2 = checkPtr2->next;
				} else {
					delete checkPtr2;
					return false;
				}
				delete checkPtr2;
				return true;
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
 	SingleLinkedList l;
 	
	int n;
	cout << "Enter number of elements to be entered: ";
	cin >> n;

	for (int i = 0 ; i < n ; i++) {
		int currentElement;
		cout << "Enter element " << (i+1) << ": ";
		cin >> currentElement;
		l.insertAtEnd(currentElement);
	}

	if(l.checkPalindrome(l.head, n)) {
		cout << "List is a Palindrome.";
	} else {
		cout << "List is not a Palindrome.";
	}

 	
}
