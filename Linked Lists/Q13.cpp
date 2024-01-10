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

    void insertAtEnd(int k, int d) {
        Node *newNode = new Node(k ,d);
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

    void printF() {
        Node *ptr = head;
        cout << ptr->data;
        ptr = ptr->next;

        while (ptr != head) {
            cout << " " <<ptr->data;
            ptr = ptr->next;
        }
    }

    void printB() {
        Node *ptr = tail;
        cout << ptr->data;
        ptr = ptr->previous;

        while (ptr != tail) {
            cout << " " <<ptr->data;
            ptr = ptr->previous;
        }
    }

    void Swap(int pos1, int pos2) {
        if(pos1 < 1 || pos2 < 1) {
            cout << "Invalid Position.";
        } else if(pos1 == pos2) {
            cout << "Invalid Position.";
        } else {
            Node *p1 = head;
            Node *p2 = head;
            bool validPos = true;

            for(int i = 1; i < pos1 ; i++) {
                if(p1->next == head) {
                    cout << "Invalid Position.";
                    validPos = false;
                    break;
                } else {
                    p1 = p1->next;
                }
            }

            for(int i = 1; i < pos2 ; i++) {
                if(p2->next == head) {
                    cout << "Invalid Position.";
                    validPos = false;
                    break;
                } else {
                    p2 = p2->next;
                }
            }

            if (validPos) {
                if (p1 == head) {
                    head = p2;
                } else if (p2 == head) {
                    head = p1;
                }

                if (p1 == tail) {
                    tail = p2;
                } else if (p2 == tail) {
                    tail = p1;
                }
            }
        }
    }
};

int main () {
    CircularDoublyLinkedList CDLL1(1, 100);
    CDLL1.insertAtEnd(2, 200);
    CDLL1.insertAtEnd(3, 300);
    CDLL1.insertAtEnd(4, 400);
    CDLL1.insertAtEnd(5, 500);

    cout << "Before swap: ";
    CDLL1.printF();

    CDLL1.Swap(4, 2);

    cout << endl << "After swap: ";
    CDLL1.printF();
}
