
#include <iostream>
#include "Vehicle.h"

using namespace std;

Vehicle::Vehicle(int id, int ownerId, string registrationNumber,
                 string model, string batteryCapacity) {
    this->id = id;
    this->ownerId = ownerId;
    this->registrationNumber = registrationNumber;
    this->model = model;
    this->batteryCapacity = batteryCapacity;
}

int Vehicle::getId() const {
    return id;
}

int Vehicle::getOwnerId() const {
    return ownerId;
}

string Vehicle::getRegistrationNumber() const {
    return registrationNumber;
}

void Vehicle::display() const {
    cout << "\nVehicle ID: " << id;
    cout << "\nOwner ID: " << ownerId;
    cout << "\nRegistration: " << registrationNumber;
    cout << "\nModel: " << model;
    cout << "\nBattery Capacity: " << batteryCapacity << " kWh\n";
}

void VehicleManager::addVehicle() {
    int ownerId;
    string registration, model, battery;

    cout << "\nEnter Owner User ID: ";
    cin >> ownerId;

    cout << "Enter Registration Number: ";
    getline(cin >> ws, registration);

    cout << "Enter Vehicle Model: ";
    getline(cin, model);

    cout << "Enter Battery Capacity (kWh): ";
    getline(cin, battery);

    for (const Vehicle& v : vehicles) {
        if (v.getRegistrationNumber() == registration) {
            cout << "\nVehicle already registered!\n";
            return;
        }
    }

    vehicles.emplace_back(
        nextId++, ownerId, registration, model, battery
    );

    cout << "\nVehicle registered successfully!\n";
}

void VehicleManager::viewVehicles() const {
    if (vehicles.empty()) {
        cout << "\nNo vehicles registered.\n";
        return;
    }

    for (const Vehicle& v : vehicles) {
        v.display();
        cout << "----------------------\n";
    }
}

void VehicleManager::searchVehicle() const {
    string registration;

    cout << "\nEnter Registration Number: ";
    getline(cin >> ws, registration);

    for (const Vehicle& v : vehicles) {
        if (v.getRegistrationNumber() == registration) {
            v.display();
            return;
        }
    }

    cout << "\nVehicle not found.\n";
}

void VehicleManager::deleteVehicle() {
    int id;

    cout << "\nEnter Vehicle ID to delete: ";
    cin >> id;

    for (auto it = vehicles.begin(); it != vehicles.end(); ++it) {
        if (it->getId() == id) {
            vehicles.erase(it);
            cout << "\nVehicle deleted successfully!\n";
            return;
        }
    }

    cout << "\nVehicle not found.\n";
}

void VehicleManager::viewUserVehicles() const {
    int ownerId;
    bool found = false;

    cout << "\nEnter User ID: ";
    cin >> ownerId;

    for (const Vehicle& v : vehicles) {
        if (v.getOwnerId() == ownerId) {
            v.display();
            found = true;
        }
    }

    if (!found) {
        cout << "\nNo vehicles found for this user.\n";
    }
}


bool VehicleManager::vehicleExists(int id) const {
    for (const Vehicle& vehicle : vehicles) {
        if (vehicle.getId() == id) {
            return true;
        }
    }
    return false;
}

bool VehicleManager::vehicleBelongsToUser(int vehicleId, int userId) const {
    for (const Vehicle& vehicle : vehicles) {
        if (vehicle.getId() == vehicleId &&
            vehicle.getOwnerId() == userId) {
            return true;
        }
    }
    return false;
}

int VehicleManager::getTotalVehicles() const {
    return vehicles.size();
}