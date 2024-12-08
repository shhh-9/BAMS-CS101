#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

// Structure to store complaint data
struct Complaint {
    int complaintID;
    string complaintType;
    string description;
    string dateSubmitted;
    string status;  // Pending, Resolved, Under Investigation, Escalated
    string response;
    string resolution;
    int priorityLevel;

    // Constructor to initialize a new complaint with the current date
    Complaint(int id, string type, string desc, int priority) {
        complaintID = id;
        complaintType = type;
        description = desc;
        priorityLevel = priority;
        status = "Pending";

        // Get the current date for submission date
        time_t now = time(0);
        char* dt = ctime(&now);
        dateSubmitted = string(dt);

        response = "";
        resolution = "";
    }
};

// Function to display the complaints menu
void displayComplaintsMenu() {
    cout << "----------------------- Complaints and Customer Support ------------------------\n";
    cout << "1. Submit a New Complaint\n";
    cout << "2. View My Complaints\n";
    cout << "3. Track Complaint Status\n";
    cout << "4. Escalate a Complaint\n";
    cout << "5. FAQ & Help Section\n";
    cout << "6. Back to Main Menu\n";
    cout << "Please choose an option: ";
}

// Function to submit a new complaint
void submitComplaint(vector<Complaint>& complaints) {
    int complaintTypeChoice, priorityChoice;
    string description;

    cout << "Please choose the type of complaint:\n";
    cout << "1. Transaction Error\n";
    cout << "2. Account Security\n";
    cout << "3. Service Issue\n";
    cout << "4. Other\n";
    cout << "Enter choice: ";
    cin >> complaintTypeChoice;
    
    cout << "Enter a brief description of the issue: ";
    cin.ignore(); // Clear input buffer
    getline(cin, description);

    cout << "Select priority level:\n";
    cout << "1. Low\n";
    cout << "2. Medium\n";
    cout << "3. High\n";
    cout << "Enter choice: ";
    cin >> priorityChoice;

    string complaintType;
    switch (complaintTypeChoice) {
        case 1: complaintType = "Transaction Error"; break;
        case 2: complaintType = "Account Security"; break;
        case 3: complaintType = "Service Issue"; break;
        case 4: complaintType = "Other"; break;
        default: complaintType = "Unknown"; break;
    }

    Complaint newComplaint(complaints.size() + 1, complaintType, description, priorityChoice);
    complaints.push_back(newComplaint);

    cout << "Complaint submitted successfully! Complaint ID: " << newComplaint.complaintID << endl;
}

// Function to view all complaints
void viewComplaints(const vector<Complaint>& complaints) {
    cout << "Your Complaints:\n";
    if (complaints.empty()) {
        cout << "You have no complaints.\n";
        return;
    }

    for (const auto& complaint : complaints) {
        cout << "Complaint ID: " << complaint.complaintID << " | Type: " << complaint.complaintType 
             << " | Status: " << complaint.status << " | Priority: " << complaint.priorityLevel << endl;
    }
}

// Function to track the status of a specific complaint
void trackComplaintStatus(const vector<Complaint>& complaints) {
    int complaintID;
    cout << "Enter your Complaint ID to track the status: ";
    cin >> complaintID;

    bool found = false;
    for (const auto& complaint : complaints) {
        if (complaint.complaintID == complaintID) {
            found = true;
            cout << "Complaint ID: " << complaint.complaintID << endl;
            cout << "Type: " << complaint.complaintType << endl;
            cout << "Description: " << complaint.description << endl;
            cout << "Date Submitted: " << complaint.dateSubmitted;
            cout << "Status: " << complaint.status << endl;
            cout << "Response: " << (complaint.response.empty() ? "No response yet" : complaint.response) << endl;
            cout << "Resolution: " << (complaint.resolution.empty() ? "Not yet resolved" : complaint.resolution) << endl;
            break;
        }
    }

    if (!found) {
        cout << "Complaint ID not found.\n";
    }
}

// Function to escalate a complaint
void escalateComplaint(vector<Complaint>& complaints) {
    int complaintID;
    cout << "Enter Complaint ID to escalate: ";
    cin >> complaintID;

    bool found = false;
    for (auto& complaint : complaints) {
        if (complaint.complaintID == complaintID) {
            found = true;
            if (complaint.status == "Resolved") {
                cout << "Complaint has already been resolved.\n";
            } else {
                complaint.status = "Escalated";
                cout << "Complaint ID " << complaintID << " has been escalated.\n";
            }
            break;
        }
    }

    if (!found) {
        cout << "Complaint ID not found.\n";
    }
}

// Function to display the FAQ & Help section
void displayFAQ() {
    cout << "FAQ & Help Section:\n";
    cout << "1. How do I reset my account password?\n";
    cout << "2. What should I do if a transaction fails?\n";
    cout << "3. How can I verify my account details?\n";
    cout << "4. General troubleshooting for account-related issues.\n";
    cout << "Please choose a FAQ option or press [0] to return: ";
    int choice;
    cin >> choice;
    if (choice == 0) {
        return;
    } else {
        cout << "You selected FAQ #" << choice << ".\n";
        cout << "Please follow the instructions for your issue.\n";
    }
}

// Main function to simulate the interaction
int main() {
    vector<Complaint> complaints;  // Vector to store all complaints
    int choice;

    while (true) {
        displayComplaintsMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                submitComplaint(complaints);  // Submit a new complaint
                break;
            case 2:
                viewComplaints(complaints);  // View all complaints
                break;
            case 3:
                trackComplaintStatus(complaints);  // Track a specific complaint
                break;
            case 4:
                escalateComplaint(complaints);  // Escalate a complaint
                break;
            case 5:
                displayFAQ();  // FAQ & Help Section
                break;
            case 6:
                cout << "Back to Main Menu\n";  // Exit from Complaints Menu
                return 0;
            default:
                cout << "Invalid option.\n";
        }
    }

    return 0;
}
