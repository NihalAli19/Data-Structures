#include <iostream>
using namespace std;

class Node {
public:
    int key;
    int data;
    Node *next;
    Node *previous;

    Node() {
        key = 0;
        data = 0;
        next = NULL;
        previous = NULL;
    }

    Node(int k, int d) {
        key = k;
        data = d;
    }
};

class CircularDoublyLinkedList {
public:
    Node *head;
    Node *tail;

    CircularDoublyLinkedList() {
        head = NULL;
    }

    CircularDoublyLinkedList(int k, int d) {
        Node *newNode = new Node(k, d);
        head = newNode;
        tail = head;
        newNode->next = head;
        newNode->previous = tail;
    }

    void insertAtStart(int k, int d) {
        Node *newNode = new Node(k, d);
        newNode->next = head;
        head->previous = newNode;
        head = newNode;
        tail->next = head;
        newNode->previous = tail;
    }

    void insertAtEnd(int k, int d) {
        Node *newNode = new Node(k, d);
        Node *ptr = head;

        while (ptr->next != head) {
            ptr = ptr->next;
        }

        newNode->previous = ptr;
        ptr->next = newNode;
        tail = newNode;
        tail->next = head;
        head->previous = tail;
    }

    void insertAtGiven(int k, int d, int pos) {
        if (pos < 1) {
            cout << "Position not exist." << endl;
        } 
		else if (pos == 1) {
            Node *newNode = new Node(k, d);
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
            tail->next = head;
            newNode->previous = tail;
        } 
		else {
            Node *newNode = new Node(k, d);
            Node *ptr = head;
            bool validPos = true;

            for (int i = 1; i < pos - 1; i++) {
                if (ptr->next == head) {
                    cout << "Position not exist." << endl;
                    validPos = false;
                    break;
                }
                ptr = ptr->next;
            }

            if (validPos) {
                newNode->next = ptr->next;
                newNode->previous = ptr;
                if (ptr == tail) {
                    ptr->next = newNode;
                    tail = newNode;
                    head->previous = tail;
                } 
				else {
                    ptr->next->previous = newNode;
                    ptr->next = newNode;
                }
            }
        }
    }

    void deleteAtGiven(int pos) {
        if (pos < 1) {
            cout << "Position not exist." << endl;
        } 
		else if (pos == 1) {
            Node *ptr = head;
            head = ptr->next;
            tail->next = head;
            head->previous = tail;
            delete ptr;
        } 
		else {
            Node *ptr = head;
            Node *temp;
            bool validPos = true;

            for (int i = 1; i < pos; i++) {
                if (ptr->next == head) {
                    cout << "Position not exist." << endl;
                    validPos = false;
                    break;
                }
                temp = ptr;
                ptr = ptr->next;
            }

            if (validPos) {
                temp->next = ptr->next;
                if (ptr == tail) {
                    tail = temp;
                    head->previous = tail;
                } 
				else {
                    ptr->next->previous = temp;
                }
                delete ptr;
            }
        }
    }

    void printForward() {
        Node *ptr = head;
        cout << ptr->data;
        ptr = ptr->next;

        while (ptr != head) {
            cout << " " << ptr->data;
            ptr = ptr->next;
        }
    }

    void printBackward() {
        Node *ptr = tail;
        cout << ptr->data;
        ptr = ptr->previous;

        while (ptr != tail) {
            cout << " " << ptr->data;
            ptr = ptr->previous;
        }
    }
};

int main () {
    CircularDoublyLinkedList CDLL(3, 300);
    CDLL.insertAtStart(2, 200);
    CDLL.insertAtStart(1, 100);
    CDLL.insertAtEnd(4, 400);
    CDLL.insertAtEnd(5, 500);
    CDLL.insertAtGiven(6, 600, 6);
    CDLL.deleteAtGiven(2);

    CDLL.printForward();
    cout << endl;
    CDLL.printBackward();

    return 0;
}
