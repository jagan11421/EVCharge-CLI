
#include <iostream>
#include "Menu.h"

using namespace std;

int main() {
    Menu menu;

    int choice = -1;

    cout << "\n";
    cout << "====================================\n";
    cout << "       WELCOME TO EV CHARGE HUB     \n";
    cout << "====================================\n";

    while (choice != 0) {
        menu.displayMainMenu();
        choice = menu.handleChoice();
    }

    cout << "\nThank you for using EVChargeHub!\n";

    return 0;
}
