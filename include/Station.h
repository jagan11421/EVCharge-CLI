
#ifndef STATION_H
#define STATION_H

#include <string>
#include <vector>

using namespace std;

class Station {
private:
    int id;
    string name;
    string location;
    int chargingPoints;
    double pricePerKWh;
    bool available;

public:
    Station(int id, string name, string location,
            int chargingPoints, double pricePerKWh);

    int getId() const;
    double getPricePerKWh() const;
    bool isAvailable() const;

    void setAvailability(bool status);
    void display() const;
};

class StationManager {
private:
    vector<Station> stations;
    int nextId = 1;

public:
    void addStation();
    void viewStations() const;
    void searchStation() const;
    void updateAvailability();
    void deleteStation();
    bool stationExists(int id) const;
    double getStationPrice(int id) const;
    int getTotalStations() const;
    int getAvailableStations() const;
};

#endif
