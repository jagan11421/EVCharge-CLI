
#include <iostream>
#include "Station.h"

using namespace std;

Station::Station(int id, string name, string location,
                 int chargingPoints, double pricePerKWh) {
    this->id = id;
    this->name = name;
    this->location = location;
    this->chargingPoints = chargingPoints;
    this->pricePerKWh = pricePerKWh;
    this->available = true;
}

int Station::getId() const {
    return id;
}

double Station::getPricePerKWh() const {
    return pricePerKWh;
}

bool Station::isAvailable() const {
    return available;
}

void Station::setAvailability(bool status) {
    available = status;
}

void Station::display() const {
    cout << "\nStation ID: " << id;
    cout << "\nName: " << name;
    cout << "\nLocation: " << location;
    cout << "\nCharging Points: " << chargingPoints;
    cout << "\nPrice per kWh: Rs. " << pricePerKWh;
    cout << "\nAvailability: "
         << (available ? "Available" : "Unavailable") << "\n";
}

void StationManager::addStation() {
    string name, location;
    int points;
    double price;

    cout << "\nEnter Station Name: ";
    getline(cin >> ws, name);

    cout << "Enter Location: ";
    getline(cin, location);

    cout << "Enter Number of Charging Points: ";
    cin >> points;

    cout << "Enter Price per kWh: ";
    cin >> price;

    if (points <= 0 || price < 0) {
        cout << "Invalid station details.\n";
        return;
    }

    stations.emplace_back(nextId++, name, location, points, price);

    cout << "\nStation added successfully!\n";
}

void StationManager::viewStations() const {
    if (stations.empty()) {
        cout << "\nNo stations available.\n";
        return;
    }

    for (const Station& station : stations) {
        station.display();
        cout << "----------------------\n";
    }
}

void StationManager::searchStation() const {
    int id;

    cout << "\nEnter Station ID: ";
    cin >> id;

    for (const Station& station : stations) {
        if (station.getId() == id) {
            station.display();
            return;
        }
    }

    cout << "\nStation not found.\n";
}

void StationManager::updateAvailability() {
    int id, status;

    cout << "\nEnter Station ID: ";
    cin >> id;

    for (Station& station : stations) {
        if (station.getId() == id) {
            cout << "1. Available\n";
            cout << "0. Unavailable\n";
            cout << "Enter status: ";
            cin >> status;

            if (status != 0 && status != 1) {
                cout << "Invalid status.\n";
                return;
            }

            station.setAvailability(status == 1);
            cout << "\nAvailability updated!\n";
            return;
        }
    }

    cout << "\nStation not found.\n";
}

void StationManager::deleteStation() {
    int id;

    cout << "\nEnter Station ID to delete: ";
    cin >> id;

    for (auto it = stations.begin(); it != stations.end(); ++it) {
        if (it->getId() == id) {
            stations.erase(it);
            cout << "\nStation deleted successfully!\n";
            return;
        }
    }

    cout << "\nStation not found.\n";
}


bool StationManager::stationExists(int id) const {
    for (const Station& station : stations) {
        if (station.getId() == id && station.isAvailable()) {
            return true;
        }
    }
    return false;
}

double StationManager::getStationPrice(int id) const {
    for (const Station& station : stations) {
        if (station.getId() == id) {
            return station.getPricePerKWh();
        }
    }

    return -1;
}

int StationManager::getTotalStations() const {
    return stations.size();
}

int StationManager::getAvailableStations() const {
    int count = 0;

    for (const Station& station : stations) {
        if (station.isAvailable()) {
            count++;
        }
    }

    return count;
}