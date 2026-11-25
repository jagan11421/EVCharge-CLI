
#include <iostream>
#include "Booking.h"

using namespace std;

Booking::Booking(int id, int userId, int vehicleId, int stationId) {
    this->id = id;
    this->userId = userId;
    this->vehicleId = vehicleId;
    this->stationId = stationId;
    this->status = "Confirmed";
}

int Booking::getId() const {
    return id;
}

int Booking::getUserId() const {
    return userId;
}

void Booking::cancel() {
    status = "Cancelled";
}

void Booking::display() const {
    cout << "\nBooking ID: " << id;
    cout << "\nUser ID: " << userId;
    cout << "\nVehicle ID: " << vehicleId;
    cout << "\nStation ID: " << stationId;
    cout << "\nStatus: " << status << "\n";
}

BookingManager::BookingManager(
    UserManager& users,
    VehicleManager& vehicles,
    StationManager& stations
) : users(users), vehicles(vehicles), stations(stations) {}

void BookingManager::createBooking() {
    int userId, vehicleId, stationId;

    cout << "\nEnter User ID: ";
    cin >> userId;

    if (!users.userExists(userId)) {
        cout << "User does not exist.\n";
        return;
    }

    cout << "Enter Vehicle ID: ";
    cin >> vehicleId;

    if (!vehicles.vehicleBelongsToUser(vehicleId, userId)) {
        cout << "Vehicle does not belong to this user.\n";
        return;
    }

    cout << "Enter Station ID: ";
    cin >> stationId;

    if (!stations.stationExists(stationId)) {
        cout << "Station does not exist or is unavailable.\n";
        return;
    }

    bookings.emplace_back(nextId++, userId, vehicleId, stationId);

    cout << "\nBooking created successfully!\n";
}

void BookingManager::viewBookings() const {
    if (bookings.empty()) {
        cout << "\nNo bookings found.\n";
        return;
    }

    for (const Booking& booking : bookings) {
        booking.display();
        cout << "----------------------\n";
    }
}

void BookingManager::searchBooking() const {
    int id;

    cout << "\nEnter Booking ID: ";
    cin >> id;

    for (const Booking& booking : bookings) {
        if (booking.getId() == id) {
            booking.display();
            return;
        }
    }

    cout << "\nBooking not found.\n";
}

void BookingManager::cancelBooking() {
    int id;

    cout << "\nEnter Booking ID: ";
    cin >> id;

    for (Booking& booking : bookings) {
        if (booking.getId() == id) {
            booking.cancel();
            cout << "\nBooking cancelled successfully!\n";
            return;
        }
    }

    cout << "\nBooking not found.\n";
}

void BookingManager::viewUserBookings() const {
    int userId;
    bool found = false;

    cout << "\nEnter User ID: ";
    cin >> userId;

    for (const Booking& booking : bookings) {
        if (booking.getUserId() == userId) {
            booking.display();
            found = true;
        }
    }

    if (!found) {
        cout << "\nNo bookings found for this user.\n";
    }
}

int BookingManager::getTotalBookings() const {
    return bookings.size();
}

int BookingManager::getCancelledBookings() const {
    int count = 0;

    // Add a status getter to Booking first.
    for (const Booking& booking : bookings) {
        if (booking.getStatus() == "Cancelled") {
            count++;
        }
    }

    return count;
}

string Booking::getStatus() const {
    return status;
}