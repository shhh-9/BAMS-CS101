#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Customer class to represent each customer and their loan details
class Customer {
public:
    string name;
    string accountNumber;
    double balance;
    double loanAmount;
    double interestRate;
    double loanTerm;
    double taxRate;

    // Constructor to initialize customer with basic info
    Customer(string name, string accountNumber) : name(name), accountNumber(accountNumber), balance(0), loanAmount(0), interestRate(0), loanTerm(0), taxRate(0) {}

    // Method to apply loan and store its details
    void applyLoan(double amount, double rate, double term) {
        loanAmount = amount;
        interestRate = rate;
        loanTerm = term;
        balance += amount;  // Assuming loan is added to balance for simplicity
    }

    // Method to calculate interest on the loan
    double calculateInterest() const {
        return loanAmount * (interestRate / 100) * loanTerm;
    }

    // Method to calculate tax on the loan
    double calculateTax() const {
        return (loanAmount + calculateInterest()) * (taxRate / 100);
    }

    // Method to calculate the total loan including interest and tax
    double getTotalLoan() const {
        return loanAmount + calculateInterest() + calculateTax();
    }

    // Method to display the account details including loan and tax information
    void displayAccountDetails() const {
        cout << "\nCustomer Name: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
        cout << "Loan Amount: " << loanAmount << endl;
        cout << "Interest: " << calculateInterest() << endl;
        cout << "Tax: " << calculateTax() << endl;
        cout << "Total Loan (including interest and tax): " << getTotalLoan() << endl;
    }
};

// Function to apply for a loan
void applyLoan(Customer &customer) {
    double loanAmount, interestRate, loanTerm, taxRate;

    cout << "Enter loan amount: ";
    cin >> loanAmount;
    cout << "Enter interest rate (in percentage): ";
    cin >> interestRate;
    cout << "Enter loan term (in years): ";
    cin >> loanTerm;
    cout << "Enter tax rate (in percentage): ";
    cin >> taxRate;

    // Apply the loan to the customer
    customer.applyLoan(loanAmount, interestRate, loanTerm);
    customer.taxRate = taxRate;  // Set the tax rate for the customer

    cout << "Loan applied successfully!" << endl;
}

// Main function to run the menu-driven system
int main() {
    string name, accountNumber;
    
    cout << "Enter customer name: ";
    cin >> name;
    cout << "Enter account number: ";
    cin >> accountNumber;
    
    // Create a Customer object
    Customer customer(name, accountNumber);

    int choice;
    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Apply for a loan\n";
        cout << "2. View account details\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                applyLoan(customer);
                break;
            case 2:
                customer.displayAccountDetails();
                break;
            case 3:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
