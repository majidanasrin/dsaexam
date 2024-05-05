#include <iostream>

using namespace std;

// Node structure to represent each element in the linked list
struct Node {
    int patient_id;
    int priority;
    Node* next;
    
    Node(int id, int prio) : patient_id(id), priority(prio), next(nullptr) {}
};

class PriorityQueue {
private:
    Node* head;
    
public:
    PriorityQueue() : head(nullptr) {}
    
    // Enqueue operation to insert an element based on priority
    void enqueue(int patient_id, int priority) {
        Node* new_node = new Node(patient_id, priority);
        if (!head || priority < head->priority) {
            new_node->next = head;
            head = new_node;
        } else {
            Node* current = head;
            while (current->next && current->next->priority <= priority) {
                current = current->next;
            }
            new_node->next = current->next;
            current->next = new_node;
        }
    }
    
    // Dequeue operation to remove the element with the highest priority
    int dequeue() {
        if (!head) {
            cout << "Priority queue is empty." << endl;
            return -1; // Assuming patient_id cannot be negative
        }
        int patient_id = head->patient_id;
        Node* temp = head;
        head = head->next;
        delete temp;
        return patient_id;
    }
    
    // Display the elements of the priority queue
    void display() {
        Node* current = head;
        while (current) {
            cout << "Patient ID: " << current->patient_id << ", Priority: " << current->priority << endl;
            current = current->next;
        }
    }
    
    // Destructor to free memory
    ~PriorityQueue() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    PriorityQueue pq;
    pq.enqueue(1, 2);
    pq.enqueue(2, 1);
    pq.enqueue(3, 3);
    pq.enqueue(4, 2);

    cout << "Priority Queue:" << endl;
    pq.display();

    cout << "\nDequeueing:" << endl;
    cout << pq.dequeue() << endl;
    cout << pq.dequeue() << endl;
    cout << pq.dequeue() << endl;
    cout << pq.dequeue() << endl;

    return 0;
}