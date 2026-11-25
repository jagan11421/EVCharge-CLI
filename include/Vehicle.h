
#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <vector>

using namespace std;

class Vehicle {
private:
    int id;
    int ownerId;
    string registrationNumber;
    string model;
    string batteryCapacity;

public:
    Vehicle(int id, int ownerId, string registrationNumber,
            string model, string batteryCapacity);

    int getId() const;
    int getOwnerId() const;
    string getRegistrationNumber() const;

    void display() const;
};

class VehicleManager {
private:
    vector<Vehicle> vehicles;
    int nextId = 1;

public:
    void addVehicle();
    void viewVehicles() const;
    void searchVehicle() const;
    void deleteVehicle();
    void viewUserVehicles() const;
    bool vehicleExists(int id) const;
    bool vehicleBelongsToUser(int vehicleId, int userId) const;
    int getTotalVehicles() const;
};

#endif
