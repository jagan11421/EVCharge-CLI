
#include <iostream>
#include "User.h"

using namespace std;

User::User(int id, string name, string phone, string email) {
    this->id = id;
    this->name = name;
    this->phone = phone;
    this->email = email;
}

int User::getId() const {
    return id;
}

void User::display() const {
    cout << "\nUser ID: " << id;
    cout << "\nName: " << name;
    cout << "\nPhone: " << phone;
    cout << "\nEmail: " << email << "\n";
}

void User::updateDetails(string name, string phone, string email) {
    this->name = name;
    this->phone = phone;
    this->email = email;
}

void UserManager::addUser() {
    string name, phone, email;

    cout << "\nEnter name: ";
    getline(cin >> ws, name);

    cout << "Enter phone: ";
    getline(cin, phone);

    cout << "Enter email: ";
    getline(cin, email);

    users.emplace_back(nextId++, name, phone, email);

    cout << "\nUser registered successfully!\n";
}

void UserManager::viewUsers() const {
    if (users.empty()) {
        cout << "\nNo users registered.\n";
        return;
    }

    for (const User& user : users) {
        user.display();
        cout << "----------------------\n";
    }
}

void UserManager::searchUser() const {
    int id;

    cout << "Enter User ID: ";
    cin >> id;

    for (const User& user : users) {
        if (user.getId() == id) {
            user.display();
            return;
        }
    }

    cout << "\nUser not found.\n";
}

void UserManager::updateUser() {
    int id;
    string name, phone, email;

    cout << "Enter User ID to update: ";
    cin >> id;

    for (User& user : users) {
        if (user.getId() == id) {
            cout << "Enter new name: ";
            getline(cin >> ws, name);

            cout << "Enter new phone: ";
            getline(cin, phone);

            cout << "Enter new email: ";
            getline(cin, email);

            user.updateDetails(name, phone, email);

            cout << "\nUser updated successfully!\n";
            return;
        }
    }

    cout << "\nUser not found.\n";
}

void UserManager::deleteUser() {
    int id;

    cout << "Enter User ID to delete: ";
    cin >> id;

    for (auto it = users.begin(); it != users.end(); ++it) {
        if (it->getId() == id) {
            users.erase(it);
            cout << "\nUser deleted successfully!\n";
            return;
        }
    }

    cout << "\nUser not found.\n";
}
bool UserManager::userExists(int id) const {
    for (const User& user : users) {
        if (user.getId() == id) {
            return true;
        }
    }
    return false;
}

int UserManager::getTotalUsers() const {
    return users.size();
}