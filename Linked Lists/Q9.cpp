#include <iostream>

using namespace std;

class Node {
	public:

		int key;
		int data;
		Node *next;

		Node() {

			key = 0;
			data = 0;
			next = NULL;
		}

		Node(int k, int d) {
			key = k;
			data = d;
		}
};


class CircularLinkedList {

	public:

		Node *head;
		Node *tail;

		CircularLinkedList() {
			head = NULL;
		}

		CircularLinkedList(int k, int d) {
			Node *newNode = new Node(k, d);
			newNode->next = head;
			head = newNode;
			tail = head;
		}

		void insertAtStart(int k, int d) {
			Node *newNode = new Node(k, d);
			newNode->next = head;
			head = newNode;
			tail->next = head;
		}

		void insertAtEnd(int k, int d) {
			Node *newNode = new Node(k, d);
			Node *ptr = head;

			while (ptr->next != head) {
				ptr = ptr->next;
			}

			ptr->next = newNode;
			tail = newNode;
			tail->next = head;
		}

		void insertAtGiven(int k, int d, int nodePos) {
			if (nodePos < 1) {
				cout << "Position not exist." << endl;
			} 
			else if (nodePos == 1) {
				Node *newNode = new Node(k, d);
				newNode->next = head;
				head = newNode;
				tail->next = head;
			} 
			else {
				Node *newNode = new Node(k, d);
				Node *ptr = head;
				bool validPos = true;

				for (int i = 1 ; i < nodePos - 1 ; i++) {
					if (ptr->next == head) {
						cout << "Position not exist." << endl;
						validPos = false;
						break;
					}
					ptr = ptr->next;
				}
				if (validPos) {
					newNode->next = ptr->next;
					ptr->next = newNode;
					if (ptr == tail) {
						tail = newNode;
					}
				}
			}
		}

		void deleteAtGiven(int nodePos) {
			if (nodePos < 1) {
				cout << "Entered Position Does Not Exist." << endl;
			} 
			else if (nodePos == 1) {
				Node *ptr = head;
				head = ptr->next;
				tail->next = head;
				delete ptr;
			} 
			else {
				Node *ptr = head;
				Node *temp;
				bool validPos = true;

				for (int i = 1 ; i < nodePos ; i++) {
					if (ptr->next == head) {
						cout << "Entered Position Does Not Exist." << endl;
						validPos = false;
						break;
					}
					temp = ptr;
					ptr = ptr->next;
				}

				if (validPos) {
					temp->next = ptr->next;
					delete ptr;
				}
			}
		}

		void print() {
			Node *ptr = head;
			cout << ptr->data;
			ptr = ptr->next;

			while (ptr != head) {
				cout << " " <<ptr->data;
				ptr = ptr->next;
			}
		}
};

int main() {

	CircularLinkedList CLL1(3, 300);
	CLL1.insertAtStart(2, 200);
	CLL1.insertAtEnd(4, 400);
	CLL1.insertAtStart(1, 100);
	CLL1.insertAtEnd(5, 500);
	CLL1.insertAtGiven(6, 600, 6);

	CLL1.deleteAtGiven(2);

	CLL1.print();

}
