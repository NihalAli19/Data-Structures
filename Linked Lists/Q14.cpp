#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node() {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class SingleLinkedList {
public:
    Node *head;

    SingleLinkedList() {
        this->head = NULL;
    }

    void print() {
        Node *print = head;
        while (print != NULL) {
            cout << print->data << "  ";
            print = print->next;
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

    void func() {
        Node *len = head;
        int listLen = 0;

        while (len != NULL) {
            listLen++;
            len = len->next;
        }

        for (int i = listLen; i > 1; i -= 2) {
            Node *currentPtr = head->next;
            Node *previousPtr = head;

            for (int j = 1; j < i / 2; j++) {
                currentPtr = currentPtr->next->next;
                previousPtr = previousPtr->next->next;
            }

            previousPtr->next = currentPtr->next;

            Node *ptr = head;

            while (ptr->next != NULL) {
                ptr = ptr->next;
            }

            ptr->next = currentPtr;
            currentPtr->next = NULL;
        }
    }
};

int main() {
    SingleLinkedList List;

    List.insertAtEnd(10);
    List.insertAtEnd(4);
    List.insertAtEnd(9);
    List.insertAtEnd(1);
    List.insertAtEnd(3);
    List.insertAtEnd(5);
    List.insertAtEnd(9);
    List.insertAtEnd(4);

    cout << "Before: ";
    List.print();

    List.func();

    cout << endl << "After: ";
    List.print();
}