
#ifndef BOOKING_H
#define BOOKING_H

#include <string>
#include <vector>

#include "User.h"
#include "Vehicle.h"
#include "Station.h"

using namespace std;

class Booking {
private:
    int id;
    int userId;
    int vehicleId;
    int stationId;
    string status;

public:
    Booking(int id, int userId, int vehicleId, int stationId);
    int getId() const;
    int getUserId() const;
    string getStatus() const; 
    void cancel();
    void display() const;
};

class BookingManager {
private:
    vector<Booking> bookings;
    int nextId = 1;

    UserManager& users;
    VehicleManager& vehicles;
    StationManager& stations;

public:
    BookingManager(UserManager& users,
                   VehicleManager& vehicles,
                   StationManager& stations);

    void createBooking();
    void viewBookings() const;
    void searchBooking() const;
    void cancelBooking();
    void viewUserBookings() const;
    int getTotalBookings() const;
    int getCancelledBookings() const;
};

#endif
