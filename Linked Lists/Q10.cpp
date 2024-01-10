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

    void insertAtStart(int k, int d) {
        Node *newNode = new Node(k, d);
        newNode->next = head;
        newNode->previous = NULL;
        head->previous = newNode;
        head = newNode;
    }

    void insertAtEnd(int k, int d) {
        Node *newNode = new Node(k, d);
        Node *ptr = head;

        while (ptr->next != NULL) {
            ptr = ptr->next;
        }

        newNode->previous = ptr;
        ptr->next = newNode;
        newNode->next = NULL;
        tail = newNode;
    }

    void insertAtGiven(int k, int d, int pos) {
        if (pos < 1) {
            cout << "Entered Position Does Not Exist." << endl;
        } else if (pos == 1) {
            Node *newNode = new Node(k, d);
            newNode->next = head;
            newNode->previous = NULL;
            head->previous = newNode;
            head = newNode;
        } else {
            Node *newNode = new Node(k, d);
            Node *ptr = head;
            bool validPos = true;

            for (int i = 1; i < pos - 1; i++) {
                if (ptr->next == NULL) {
                    cout << "Entered Position Does Not Exist." << endl;
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
                } else {
                    ptr->next->previous = newNode;
                    ptr->next = newNode;
                }
            }
        }
    }

    void deleteAtGiven(int pos) {
        if (pos < 1) {
            cout << "Entered Position Does Not Exist." << endl;
        } 
		else if (pos == 1) {
            Node *ptr = head;
            head = ptr->next;
            head->previous = NULL;
            delete ptr;
        }
		else {
            Node *ptr = head;
            Node *temp;
            bool validPos = true;

            for (int i = 1; i < pos; i++) {
                if (ptr->next == NULL) {
                    cout << "Entered Position Does Not Exist." << endl;
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
                } else {
                    ptr->next->previous = temp;
                }
                delete ptr;
            }
        }
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

int main() {
    DoublyLinkedList DLL(3, 300);
    DLL.insertAtStart(2, 200);
    DLL.insertAtStart(1, 100);
    DLL.insertAtEnd(4, 400);
    DLL.insertAtEnd(5, 500);
    DLL.insertAtGiven(6, 600, 6);
    DLL.deleteAtGiven(2);

    DLL.printForward();
    cout << endl;
    DLL.printBackward();

    return 0;
}
