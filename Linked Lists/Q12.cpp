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

class DoublyLinkedList {
public:
    Node *head;
    Node *tail;

    DoublyLinkedList() {
        head = NULL;
    }

    DoublyLinkedList(int k, int d) {
        Node *newNode = new Node(k, d);
        newNode->next = NULL;
        newNode->previous = NULL;
        head = newNode;
        tail = head;
    }

    void insertAtEnd(int k, int d) {
        Node *newNode = new Node(k ,d);
        Node *ptr = head;

        while (ptr->next != NULL) {
            ptr = ptr->next;
        }

        newNode->previous = ptr;
        ptr->next = newNode;
        newNode->next = NULL;
        tail = newNode;
    }

    void printForward() {
        Node *ptr = head;

        while (ptr != NULL) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }

    void printBackward() {
        Node *ptr = tail;

        while (ptr != NULL) {
            cout << ptr->data << " ";
            ptr = ptr->previous;
        }
    }
};

void concatenate(DoublyLinkedList DLL1, DoublyLinkedList DLL2) {
    DLL1.tail->next = DLL2.head;
    DLL2.head->previous = DLL1.tail;
    
    cout << "\nAfter concatenation: ";
    DLL1.printForward(); 
}

int main () {
    DoublyLinkedList DLL1(1, 100);
    DLL1.insertAtEnd(2, 200);
    DLL1.insertAtEnd(3, 300);

    DoublyLinkedList DLL2(4, 400);
    DLL2.insertAtEnd(5, 500);
    DLL2.insertAtEnd(6, 600);

    cout << "First Doubly Linked List: ";
    DLL1.printForward();
    cout << "\nSecond Doubly Linked List: ";
    DLL2.printForward(); 

    concatenate(DLL1, DLL2);

    return 0;
}
