
#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

using namespace std;

class User {
private:
    int id;
    string name;
    string phone;
    string email;

public:
    User(int id, string name, string phone, string email);

    int getId() const;
    void display() const;

    void updateDetails(string name, string phone, string email);
};

class UserManager {
private:
    vector<User> users;
    int nextId = 1;

public:
    void addUser();
    void viewUsers() const;
    void searchUser() const;
    void updateUser();
    void deleteUser();
    bool userExists(int id) const;
    int getTotalUsers() const;
};

#endif
