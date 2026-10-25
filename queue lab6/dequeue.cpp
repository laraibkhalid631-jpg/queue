#include <iostream>
using namespace std;

// Structure to define a node containing bi-directional pointers
struct Node {
    int data;       // Data value of the node
    Node* next;     // Address link to the succeeding node
    Node* prev;     // Address link to the preceding node
};

// Class for the Doubly Linked List based Double-Ended Queue (Deque)
class Deque {
private:
    Node* front;    // Pointer pointing to the front edge of the Deque
    Node* rear;     // Pointer pointing to the rear edge of the Deque

public:
    // Constructor: Instantiates an empty Deque setting boundaries to NULL
    Deque() {
        front = nullptr;
        rear = nullptr;
    }

    // Utility function checking if the Deque is completely clear of nodes
    bool isEmpty() {
        return (front == nullptr);
    }

    // Pushes a new node right at the Front boundary
    void insertFront(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (isEmpty()) {
            front = rear = newNode;
        } 
        else {
            newNode->next = front;  // Connect new node's next link to current front
            front->prev = newNode;  // Backlink current front to new node
            front = newNode;        // Move front marker back onto new node
        }
        cout << x << " inserted at Front.\n";
    }

    // Pushes a new node right at the Rear boundary
    void insertRear(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (isEmpty()) {
            front = rear = newNode;
        } 
        else {
            newNode->prev = rear;   // Connect new node's prev link to current rear
            rear->next = newNode;   // Forward link current rear to new node
            rear = newNode;         // Move rear marker forward onto new node
        }
        cout << x << " inserted at Rear.\n";
    }

    // Extracts and returns the data node located at the Front edge
    int deleteFront() {
        if (isEmpty()) {
            cout << "Deque Underflow! Already empty.\n";
            return -1;
        }

        Node* temp = front;
        int value = front->data;

        front = front->next; // Advance front pointer forward

        if (front == nullptr) {
            rear = nullptr;  // If collection becomes empty, set rear to NULL
        } else {
            front->prev = nullptr; // Isolate new front node by breaking its backlink
        }

        delete temp;
        return value;
    }

    // Extracts and returns the data node located at the Rear edge
    int deleteRear() {
        if (isEmpty()) {
            cout << "Deque Underflow! Already empty.\n";
            return -1;
        }

        Node* temp = rear;
        int value = rear->data;

        rear = rear->prev; // Retreat rear pointer backward

        if (rear == nullptr) {
            front = nullptr;  // If collection becomes empty, set front to NULL
        } else {
            rear->next = nullptr; // Isolate new rear node by breaking its forward link
        }

        delete temp;
        return value;
    }

    // Prints the linear chain sequence from Front to Rear layout
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty.\n";
            return;
        }

        Node* temp = front;
        cout << "Deque Elements (Front to Rear): ";
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Destructor: Safely deallocates all existing memory when Deque is terminated
    ~Deque() {
        while (!isEmpty()) {
            deleteFront();
        }
    }
};

// Main function testing execution paths for the Deque instance
int main() {
    Deque dq;

    // Execute insertion scenarios
    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertFront(1);

    // Render sequence state
    dq.display(); // Output tracking: 1 <-> 5 <-> 10 <-> 20 <-> NULL

    // Execute elimination scenarios
    cout << "Deleted from Front: " << dq.deleteFront() << endl;
    cout << "Deleted from Rear: " << dq.deleteRear() << endl;

    // Render absolute final state output
    dq.display(); // Output tracking: 5 <-> 10 <-> NULL

    return 0;
}

