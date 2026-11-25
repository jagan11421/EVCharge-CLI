
#include <iostream>
#include <iomanip>
#include "Payment.h"

using namespace std;

Payment::Payment(int id, int sessionId, double amount) {
    this->id = id;
    this->sessionId = sessionId;
    this->amount = amount;
    this->status = "Paid";
}

int Payment::getId() const {
    return id;
}

int Payment::getSessionId() const {
    return sessionId;
}

void Payment::display() const {
    cout << fixed << setprecision(2);

    cout << "\nPayment ID: " << id;
    cout << "\nSession ID: " << sessionId;
    cout << "\nAmount: Rs. " << amount;
    cout << "\nStatus: " << status << "\n";
}

PaymentManager::PaymentManager(ChargingManager& chargingManager)
    : chargingManager(chargingManager) {}

void PaymentManager::processPayment() {
    int sessionId;

    cout << "\nEnter Completed Session ID: ";
    cin >> sessionId;

    // Prevent duplicate payments
    for (const Payment& payment : payments) {
        if (payment.getSessionId() == sessionId) {
            cout << "\nPayment already processed!\n";
            return;
        }
    }

    double amount = chargingManager.getCompletedSessionCost(sessionId);

    if (amount < 0) {
        cout << "\nInvalid or incomplete charging session.\n";
        return;
    }

    payments.emplace_back(nextId++, sessionId, amount);

    cout << "\nPayment processed successfully!\n";
    cout << "Amount Paid: Rs. " << amount << "\n";
}

void PaymentManager::viewPayments() const {
    if (payments.empty()) {
        cout << "\nNo payment records found.\n";
        return;
    }

    for (const Payment& payment : payments) {
        payment.display();
        cout << "----------------------\n";
    }
}

void PaymentManager::searchPayment() const {
    int id;

    cout << "\nEnter Payment ID: ";
    cin >> id;

    for (const Payment& payment : payments) {
        if (payment.getId() == id) {
            payment.display();
            return;
        }
    }

    cout << "\nPayment not found.\n";
}
double Payment::getAmount() const {
    return amount;
}

int PaymentManager::getTotalPayments() const {
    return payments.size();
}

double PaymentManager::getTotalRevenue() const {
    double total = 0;

    for (const Payment& payment : payments) {
        total += payment.getAmount();
    }

    return total;
}