
#include <iostream>
#include <iomanip>
#include "ChargingSession.h"

using namespace std;

ChargingSession::ChargingSession(
    int id, int userId, int vehicleId,
    int stationId, double power
) {
    this->id = id;
    this->userId = userId;
    this->vehicleId = vehicleId;
    this->stationId = stationId;
    this->power = power;

    duration = 0;
    energy = 0;
    cost = 0;
    active = true;
}

int ChargingSession::getId() const {
    return id;
}

bool ChargingSession::isActive() const {
    return active;
}

void ChargingSession::stop(double duration, double price) {
    this->duration = duration;

    energy = power * duration;
    cost = energy * price;

    active = false;
}

void ChargingSession::display() const {
    cout << fixed << setprecision(2);

    cout << "\nSession ID: " << id;
    cout << "\nUser ID: " << userId;
    cout << "\nVehicle ID: " << vehicleId;
    cout << "\nStation ID: " << stationId;
    cout << "\nCharging Power: " << power << " kW";
    cout << "\nStatus: " << (active ? "Active" : "Completed");

    if (!active) {
        cout << "\nDuration: " << duration << " hours";
        cout << "\nEnergy Consumed: " << energy << " kWh";
        cout << "\nTotal Cost: Rs. " << cost;
    }

    cout << "\n";
}

ChargingManager::ChargingManager(
    UserManager& users,
    VehicleManager& vehicles,
    StationManager& stations
) : users(users), vehicles(vehicles), stations(stations) {}

void ChargingManager::startSession() {
    int userId, vehicleId, stationId;
    double power;

    cout << "\nEnter User ID: ";
    cin >> userId;

    if (!users.userExists(userId)) {
        cout << "User not found.\n";
        return;
    }

    cout << "Enter Vehicle ID: ";
    cin >> vehicleId;

    if (!vehicles.vehicleBelongsToUser(vehicleId, userId)) {
        cout << "Invalid vehicle for this user.\n";
        return;
    }

    cout << "Enter Station ID: ";
    cin >> stationId;

    if (!stations.stationExists(stationId)) {
        cout << "Station unavailable or not found.\n";
        return;
    }

    cout << "Enter Charging Power (kW): ";
    cin >> power;

    if (power <= 0) {
        cout << "Invalid charging power.\n";
        return;
    }

    sessions.emplace_back(
        nextId++, userId, vehicleId, stationId, power
    );

    cout << "\nCharging session started successfully!\n";
}


void ChargingManager::stopSession() {
    int id;
    double duration;

    cout << "\nEnter Session ID: ";
    cin >> id;

    for (ChargingSession& session : sessions) {
        if (session.getId() == id && session.isActive()) {

            cout << "Enter Charging Duration (hours): ";
            cin >> duration;

            if (duration <= 0) {
                cout << "Invalid duration.\n";
                return;
            }

            double price = stations.getStationPrice(
                session.getStationId()
            );

            if (price < 0) {
                cout << "Station not found.\n";
                return;
            }

            session.stop(duration, price);

            cout << "\nCharging completed successfully!\n";
            session.display();

            return;
        }
    }

    cout << "\nActive session not found.\n";
}


void ChargingManager::viewSessions() const {
    if (sessions.empty()) {
        cout << "\nNo charging sessions found.\n";
        return;
    }

    for (const ChargingSession& session : sessions) {
        session.display();
        cout << "----------------------\n";
    }
}

int ChargingSession::getStationId() const {
    return stationId;
}

double ChargingSession::getCost() const {
    return cost;
}

bool ChargingSession::isCompleted() const {
    return !active;
}

double ChargingManager::getCompletedSessionCost(int id) const {
    for (const ChargingSession& session : sessions) {
        if (session.getId() == id && session.isCompleted()) {
            return session.getCost();
        }
    }

    return -1;
}

double ChargingSession::getEnergy() const {
    return energy;
}

int ChargingManager::getTotalSessions() const {
    return sessions.size();
}

int ChargingManager::getActiveSessions() const {
    int count = 0;

    for (const ChargingSession& session : sessions) {
        if (session.isActive()) {
            count++;
        }
    }

    return count;
}

double ChargingManager::getTotalEnergy() const {
    double total = 0;

    for (const ChargingSession& session : sessions) {
        if (session.isCompleted()) {
            total += session.getEnergy();
        }
    }

    return total;
}