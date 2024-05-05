#include <iostream>
#include <string>

using namespace std;

// Node structure representing a student
struct Student {
    int studentID;
    string name;
    Student* next;

    Student(int id, string name) : studentID(id), name(name), next(nullptr) {}
};

// Linked list class for managing student enrollment
class EnrollmentList {
private:
    Student* head;

public:
    EnrollmentList() : head(nullptr) {}

    // Function to add a student to the enrollment list
    void addStudent(int studentID, string name) {
        Student* newStudent = new Student(studentID, name);
        if (head == nullptr) {
            head = newStudent;
        } else {
            Student* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newStudent;
        }
        cout << "Student with ID " << studentID << " added to enrollment list." << endl;
    }

    // Function to search for a student by their student ID
    void searchStudent(int studentID) {
        Student* temp = head;
        while (temp != nullptr) {
            if (temp->studentID == studentID) {
                cout << "Student with ID " << studentID << " found. Name: " << temp->name << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Student with ID " << studentID << " not found in enrollment list." << endl;
    }

    // Function to display the enrollment list
    void displayEnrollmentList() {
        cout << "Enrollment List:" << endl;
        Student* temp = head;
        while (temp != nullptr) {
            cout << "ID: " << temp->studentID << ", Name: " << temp->name << endl;
            temp = temp->next;
        }
    }
};

// Node structure representing a student in the waitlist
struct WaitlistStudent {
    int studentID;
    string name;
    WaitlistStudent* next;

    WaitlistStudent(int id, string name) : studentID(id), name(name), next(nullptr) {}
};

// Queue class for managing the waitlist
class WaitlistQueue {
private:
    WaitlistStudent* front;
    WaitlistStudent* rear;

public:
    WaitlistQueue() : front(nullptr), rear(nullptr) {}

    // Function to add a student to the waitlist
    void addToWaitlist(int studentID, string name) {
        WaitlistStudent* newStudent = new WaitlistStudent(studentID, name);
        if (front == nullptr) {
            front = rear = newStudent;
        } else {
            rear->next = newStudent;
            rear = newStudent;
        }
        cout << "Student with ID " << studentID << " added to waitlist." << endl;
    }

    // Function to display the waitlist
    void displayWaitlist() {
        cout << "Waitlist:" << endl;
        WaitlistStudent* temp = front;
        while (temp != nullptr) {
            cout << "ID: " << temp->studentID << ", Name: " << temp->name << endl;
            temp = temp->next;
        }
    }

  
   // Function to enroll students from the waitlist when spots become available
void enrollFromWaitlist(EnrollmentList& enrollmentList) {
    if (front == nullptr) {
        cout << "Waitlist is empty. No students to enroll." << endl;
        return;
    }
    WaitlistStudent* temp = front;
    front = front->next;
    cout << "Student with ID " << temp->studentID << " (" << temp->name << ") enrolled from waitlist." << endl;
    enrollmentList.addStudent(temp->studentID, temp->name); // Enroll the student in the enrollment list
    delete temp;
}
};

int main() {
    EnrollmentList enrollmentList;
    WaitlistQueue waitlistQueue;

    // Adding students to enrollment list
    enrollmentList.addStudent(1001, "Alice");
    enrollmentList.addStudent(1002, "Bob");
    enrollmentList.addStudent(1003, "Charlie");

    // Displaying enrollment list
    enrollmentList.displayEnrollmentList();

    // Searching for a student by ID
    enrollmentList.searchStudent(1002);

    // Adding students to waitlist
    waitlistQueue.addToWaitlist(1004, "David");
    waitlistQueue.addToWaitlist(1005, "Eve");

    // Displaying waitlist
    waitlistQueue.displayWaitlist();

    // Enrolling students from waitlist
    waitlistQueue.enrollFromWaitlist(enrollmentList);
    waitlistQueue.enrollFromWaitlist(enrollmentList);
    

    return 0;
}