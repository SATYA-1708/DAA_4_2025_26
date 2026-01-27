#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void deleteByValue(int val) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* prev = head;
        Node* curr = head->next;

        while (curr != NULL && curr->data != val) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == NULL) {
            cout << "Value not found\n";
            return;
        }

        prev->next = curr->next;
        delete curr;
    }

    void search(int val) {
        Node* temp = head;
        int pos = 1;

        while (temp != NULL) {
            if (temp->data == val) {
                cout << "Value " << val << " found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Value " << val << " not found\n";
    }

    int length() {
        int count = 0;
        Node* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void print() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;

    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtEnd(30);

    cout << "Original List: ";
    list.print();

    list.deleteByValue(20);
    cout << "After deleting 20: ";
    list.print();

    list.search(10);
    list.search(50);

    cout << "Length of list: " << list.length() << endl;

    return 0;
}