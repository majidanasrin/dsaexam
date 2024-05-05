#include <iostream>
#include <string>

using namespace std;

// Parcel structure representing a parcel
struct Parcel {
    string trackingNumber;
    string recipient;
    string deliveryStatus;
    Parcel* next;

    Parcel(string trackingNumber, string recipient, string deliveryStatus) : 
        trackingNumber(trackingNumber), recipient(recipient), deliveryStatus(deliveryStatus), next(nullptr) {}
};

// Linked list class for managing parcels
class ParcelList {
private:
    Parcel* head;

public:
    ParcelList() : head(nullptr) {}

    // Function to add a parcel to the parcel list
    void addParcel(string trackingNumber, string recipient, string deliveryStatus) {
        Parcel* newParcel = new Parcel(trackingNumber, recipient, deliveryStatus);
        if (head == nullptr) {
            head = newParcel;
        } else {
            Parcel* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newParcel;
        }
        cout << "Parcel with tracking number " << trackingNumber << " added to parcel list." << endl;
    }

    // Function to search for a parcel by tracking number
    void searchParcel(string trackingNumber) {
        Parcel* temp = head;
        while (temp != nullptr) {
            if (temp->trackingNumber == trackingNumber) {
                cout << "Parcel with tracking number " << trackingNumber << " found. Recipient: " 
                     << temp->recipient << ", Delivery Status: " << temp->deliveryStatus << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Parcel with tracking number " << trackingNumber << " not found in parcel list." << endl;
    }

    // Function to display the parcel list
    void displayParcelList() {
        cout << "Parcel List:" << endl;
        Parcel* temp = head;
        while (temp != nullptr) {
            cout << "Tracking Number: " << temp->trackingNumber << ", Recipient: " 
                 << temp->recipient << ", Delivery Status: " << temp->deliveryStatus << endl;
            temp = temp->next;
        }
    }
};

// Node structure representing a status change
struct StatusChange {
    string newStatus;
    StatusChange* next;

    StatusChange(string newStatus) : newStatus(newStatus), next(nullptr) {}
};

// Stack class for managing status changes
class StatusChangeStack {
private:
    StatusChange* top;

public:
    StatusChangeStack() : top(nullptr) {}

    // Function to update delivery status and push the status change onto the stack
    void updateStatus(string newStatus) {
        StatusChange* newChange = new StatusChange(newStatus);
        newChange->next = top;
        top = newChange;
        cout << "Delivery status updated to: " << newStatus << endl;
    }

    // Function to display the stack of status changes
    void displayStatusChanges() {
        cout << "Status Change Stack:" << endl;
        StatusChange* temp = top;
        while (temp != nullptr) {
            cout << temp->newStatus << endl;
            temp = temp->next;
        }
    }
};

int main() {
    ParcelList parcelList;
    StatusChangeStack statusStack;

    // Adding parcels to the parcel list
    parcelList.addParcel("123456", "Alice", "In transit");
    parcelList.addParcel("789012", "Bob", "Delivered");
    parcelList.addParcel("345678", "Charlie", "Out for delivery");

    // Displaying parcel list
    parcelList.displayParcelList();

    // Searching for a parcel by tracking number
    parcelList.searchParcel("789012");

    // Updating delivery status and displaying status changes
    statusStack.updateStatus("Arrived at sorting facility");
    statusStack.updateStatus("Out for delivery");
    statusStack.displayStatusChanges();

    return 0;
}