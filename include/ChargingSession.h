
#ifndef CHARGING_SESSION_H
#define CHARGING_SESSION_H

#include <vector>
#include "User.h"
#include "Vehicle.h"
#include "Station.h"

using namespace std;

class ChargingSession {
private:
    int id;
    int userId;
    int vehicleId;
    int stationId;

    double power;
    double duration;
    double energy;
    double cost;

    bool active;

public:
    ChargingSession(int id, int userId, int vehicleId,
                    int stationId, double power);

    int getId() const;
    bool isActive() const;

    void stop(double duration, double price);
    void display() const;
    int getStationId() const;
    double getCost() const;
    bool isCompleted() const;
    double getEnergy() const;
};

class ChargingManager {
private:
    vector<ChargingSession> sessions;
    int nextId = 1;

    UserManager& users;
    VehicleManager& vehicles;
    StationManager& stations;
    

public:
    ChargingManager(UserManager& users,VehicleManager& vehicles,StationManager& stations);
    void startSession();
    void stopSession();
    void viewSessions() const;
    double getCompletedSessionCost(int id) const;
    int getTotalSessions() const;
    int getActiveSessions() const;
    double getTotalEnergy() const;
};

#endif
