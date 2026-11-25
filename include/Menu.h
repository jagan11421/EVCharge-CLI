
#ifndef MENU_H
#define MENU_H

#include "User.h"
#include "Vehicle.h"
#include "Station.h"
#include "Booking.h"
#include "ChargingSession.h"
#include "Payment.h"

class Menu {
private:
    UserManager userManager;
    VehicleManager vehicleManager;
    StationManager stationManager;
    BookingManager bookingManager;
    ChargingManager chargingManager;
    PaymentManager paymentManager;
public:
    Menu();

    void displayMainMenu();
    int handleChoice();

    void userMenu();
    void vehicleMenu();
    void stationMenu();
    void bookingMenu();
    void chargingMenu();
    void paymentMenu();
    void dashboard();
};

#endif
