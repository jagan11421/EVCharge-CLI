
#include <iostream>
#include "Menu.h"
#include <iomanip>
using namespace std;
Menu::Menu()
    : bookingManager(userManager, vehicleManager, stationManager),
      chargingManager(userManager, vehicleManager, stationManager),
      paymentManager(chargingManager) {}

void Menu::displayMainMenu() {
    cout << "\n========== EV CHARGE HUB ==========\n";
    cout << "1. User Management\n";
    cout << "2. Vehicle Management\n";
    cout << "3. Station Management\n";
    cout << "4. Booking Management\n";
    cout << "5. Charging Management\n";
    cout << "6. Payment Management\n";
    cout << "7. Generate Reports\n";
    cout << "0. Exit\n";
    cout << "==================================\n";
}
int Menu::handleChoice() {
    int choice;

    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            userMenu();
            break;
        case 2:
            vehicleMenu();
            break;
        case 3:
            stationMenu();
            break;
        case 4:
            bookingMenu();
            break;
        case 5:
            chargingMenu();
            break;
        case 6:
            paymentMenu();
            break;
        case 7:
            dashboard();
            break;
        case 0:
            cout << "Exiting EVChargeHub...\n";
            break;
        default:
            cout << "Invalid choice.\n";
    }

    return choice;
}










void Menu::userMenu() {
    int choice;

    do {
        cout << "\n========== USER MANAGEMENT ==========\n";
        cout << "1. Register User\n";
        cout << "2. View Users\n";
        cout << "3. Search User\n";
        cout << "4. Update User\n";
        cout << "5. Delete User\n";
        cout << "0. Back to Main Menu\n";
        cout << "=====================================\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: userManager.addUser(); break;
            case 2: userManager.viewUsers(); break;
            case 3: userManager.searchUser(); break;
            case 4: userManager.updateUser(); break;
            case 5: userManager.deleteUser(); break;
            case 0: break;
            default: cout << "Invalid choice.\n";
        }

    } while (choice != 0);
}

void Menu::vehicleMenu() {
    int choice;

    do {
        cout << "\n========== VEHICLE MANAGEMENT ==========\n";
        cout << "1. Add Vehicle\n";
        cout << "2. View All Vehicles\n";
        cout << "3. Search Vehicle\n";
        cout << "4. Delete Vehicle\n";
        cout << "5. View User Vehicles\n";
        cout << "0. Back to Main Menu\n";
        cout << "========================================\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                vehicleManager.addVehicle();
                break;

            case 2:
                vehicleManager.viewVehicles();
                break;

            case 3:
                vehicleManager.searchVehicle();
                break;

            case 4:
                vehicleManager.deleteVehicle();
                break;

            case 5:
                vehicleManager.viewUserVehicles();
                break;

            case 0:
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 0);
}


void Menu::stationMenu() {
    int choice;

    do {
        cout << "\n========== STATION MANAGEMENT ==========\n";
        cout << "1. Add Station\n";
        cout << "2. View All Stations\n";
        cout << "3. Search Station\n";
        cout << "4. Update Availability\n";
        cout << "5. Delete Station\n";
        cout << "0. Back to Main Menu\n";
        cout << "========================================\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                stationManager.addStation();
                break;

            case 2:
                stationManager.viewStations();
                break;

            case 3:
                stationManager.searchStation();
                break;

            case 4:
                stationManager.updateAvailability();
                break;

            case 5:
                stationManager.deleteStation();
                break;

            case 0:
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 0);
}



void Menu::bookingMenu() {
    int choice;

    do {
        cout << "\n========== BOOKING MANAGEMENT ==========\n";
        cout << "1. Create Booking\n";
        cout << "2. View All Bookings\n";
        cout << "3. Search Booking\n";
        cout << "4. Cancel Booking\n";
        cout << "5. View User Bookings\n";
        cout << "0. Back to Main Menu\n";
        cout << "========================================\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bookingManager.createBooking();
                break;

            case 2:
                bookingManager.viewBookings();
                break;

            case 3:
                bookingManager.searchBooking();
                break;

            case 4:
                bookingManager.cancelBooking();
                break;

            case 5:
                bookingManager.viewUserBookings();
                break;

            case 0:
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 0);
}



void Menu::chargingMenu() {
    int choice;

    do {
        cout << "\n========== CHARGING MANAGEMENT ==========\n";
        cout << "1. Start Charging Session\n";
        cout << "2. Stop Charging Session\n";
        cout << "3. View Charging History\n";
        cout << "0. Back to Main Menu\n";
        cout << "=========================================\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                chargingManager.startSession();
                break;

            case 2:
                chargingManager.stopSession();
                break;

            case 3:
                chargingManager.viewSessions();
                break;

            case 0:
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 0);
}



void Menu::paymentMenu() {
    int choice;

    do {
        cout << "\n========== PAYMENT MANAGEMENT ==========\n";
        cout << "1. Process Payment\n";
        cout << "2. View Payment History\n";
        cout << "3. Search Payment\n";
        cout << "0. Back to Main Menu\n";
        cout << "========================================\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                paymentManager.processPayment();
                break;

            case 2:
                paymentManager.viewPayments();
                break;

            case 3:
                paymentManager.searchPayment();
                break;

            case 0:
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 0);
}

void Menu::dashboard() {

    cout << fixed << setprecision(2);

    cout << "\n";
    cout << "================================================\n";
    cout << "             EV CHARGE HUB REPORT               \n";
    cout << "================================================\n";

    cout << "\n              GENERAL STATISTICS                \n";
    cout << "------------------------------------------------\n";

    cout << "Total Registered Users     : "
         << userManager.getTotalUsers() << "\n";

    cout << "Total Registered Vehicles  : "
         << vehicleManager.getTotalVehicles() << "\n";

    cout << "Total Charging Stations    : "
         << stationManager.getTotalStations() << "\n";

    cout << "Available Stations         : "
         << stationManager.getAvailableStations() << "\n";

    cout << "\n               BOOKING REPORT                   \n";
    cout << "------------------------------------------------\n";

    cout << "Total Bookings             : "
         << bookingManager.getTotalBookings() << "\n";

    cout << "Cancelled Bookings         : "
         << bookingManager.getCancelledBookings() << "\n";

    cout << "\n              CHARGING REPORT                   \n";
    cout << "------------------------------------------------\n";

    cout << "Total Sessions             : "
         << chargingManager.getTotalSessions() << "\n";

    cout << "Active Sessions            : "
         << chargingManager.getActiveSessions() << "\n";

    cout << "Energy Consumed            : "
         << chargingManager.getTotalEnergy() << " kWh\n";

    cout << "\n               PAYMENT REPORT                   \n";
    cout << "------------------------------------------------\n";

    cout << "Total Payments             : "
         << paymentManager.getTotalPayments() << "\n";

    cout << "Total Revenue              : Rs. "
         << paymentManager.getTotalRevenue() << "\n";

    cout << "\n================================================\n";
}
