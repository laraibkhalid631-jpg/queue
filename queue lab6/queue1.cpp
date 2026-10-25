#include <iostream>
using namespace std;

// Structure to define a single node in the Linked List
struct Node {
    int data;       // To store the value of the element
    Node* next;     // Pointer to the next node in the sequence
};

// Class for the Linked List based Dynamic Queue
class DynamicQueue {
private:
    Node* front;    // Pointer tracking the front element of the queue
    Node* rear;     // Pointer tracking the last element of the queue

public:
    // Constructor: Initializes an empty queue where both pointers are NULL
    DynamicQueue() {
        front = nullptr;
        rear = nullptr;
    }

    // Utility function to check if the queue contains no elements
    bool is_empty() {
        return (front == nullptr);
    }

    // Inserts a new element at the tail (Rear) of the queue
    void Enqueue(int x) {
        // Allocate dynamic memory for the new node
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = nullptr;

        // Condition check if the queue is completely empty
        if (is_empty()) {
            front = rear = newNode; // Both pointers will target this first node
        } 
        else {
            rear->next = newNode;   // Connect the current last node to the new node
            rear = newNode;         // Advance the rear pointer to the new node
        }
        cout << x << " Enqueued to Queue.\n";
    }

    // Removes and returns the element at the head (Front) of the queue
    int Dequeue() {
        // Underflow condition handling
        if (is_empty()) {
            cout << "Queue is already empty!\n";
            return -1;
        }

        Node* temp = front;        // Temporarily store the front node to free its memory later
        int dequeuedValue = front->data; // Retrieve the data value

        front = front->next;       // Advance the front pointer to the next element

        // If the queue becomes empty after this operation, reset rear as well
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;               // Release allocated memory
        return dequeuedValue;
    }

    // Traverses and prints all current elements in the queue
    void display() {
        if (is_empty()) {
            cout << "\nQueue is empty....\n";
            return;
        }

        Node* temp = front;
        cout << "\nQueue Elements: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Destructor: Automatically cleans up remaining nodes when object goes out of scope
    ~DynamicQueue() {
        while (!is_empty()) {
            Dequeue();
        }
    }
};

// Main function to demonstrate and test the Dynamic Queue operations
int main() {
    DynamicQueue q;

    // Enqueue elements
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);

    // Print state
    q.display();

    // Dequeue elements
    cout << "Dequeued element: " << q.Dequeue() << endl;
    cout << "Dequeued element: " << q.Dequeue() << endl;

    // View remaining elements
    q.display();

    return 0;
}

