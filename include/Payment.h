
#ifndef PAYMENT_H
#define PAYMENT_H

#include <vector>
#include "ChargingSession.h"

using namespace std;

class Payment {
private:
    int id;
    int sessionId;
    double amount;
    string status;

public:
    Payment(int id, int sessionId, double amount);

    int getId() const;
    int getSessionId() const;
    double getAmount() const;
    void display() const;
};

class PaymentManager {
private:
    vector<Payment> payments;
    int nextId = 1;

    ChargingManager& chargingManager;

public:
    PaymentManager(ChargingManager& chargingManager);

    void processPayment();
    void viewPayments() const;
    void searchPayment() const;
    int getTotalPayments() const;
    double getTotalRevenue() const;
};

#endif
