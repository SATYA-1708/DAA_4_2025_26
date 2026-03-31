#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = NULL;
Node* tail = NULL;

void insertAtBeginning(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtEnd(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void insertAtMid(int data) {
    if (head == NULL) {
        insertAtBeginning(data);
        return;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = slow->next;
    newNode->prev = slow;

    if (slow->next != NULL)
        slow->next->prev = newNode;
    else
        tail = newNode;

    slow->next = newNode;
}

void deleteNode(int data) {
    Node* temp = head;

    while (temp != NULL && temp->data != data)
        temp = temp->next;

    if (temp == NULL) return;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        tail = temp->prev;

    delete temp;
}

bool search(int data) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data)
            return true;
        temp = temp->next;
    }
    return false;
}

void printList() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverseList() {
    Node* current = head;
    Node* temp = NULL;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        tail = head;
        head = temp->prev;
    }
}

int main() {
    cout << "Insert End: ";
    insertAtEnd(11);
    insertAtEnd(22);
    insertAtEnd(33);
    printList();

    cout << "Insert Beginning: ";
    insertAtBeginning(5);
    printList();

    cout << "Insert Middle: ";
    insertAtMid(18);
    printList();

    cout << "Delete 22: ";
    deleteNode(22);
    printList();

    cout << "Search 18: " << search(18) << endl;
    cout << "Search 99: " << search(99) << endl;

    cout << "Reverse List: ";
    reverseList();
    printList();

    return 0;
}