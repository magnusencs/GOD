#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registerUser() {
    string user, pass;
    cout << "Choose a username: ";
    cin >> user;
    cout << "Choose a password: ";
    cin >> pass;

    ofstream file("user.txt", ios::app);
    file << user << " " << pass << endl;
    file.close();

    cout << "Registration successful!\n";
}

bool loginUser() {
    string user, pass, u, p;
    cout << "Username: ";
    cin >> user;
   cout << "Password: ";
    cin >> pass;

    ifstream file("users.txt");
    while (file >> u >> p) {
        if (u == user && p == pass) {
            cout << "Login successful!\n";
            return true;
        }
    }
    cout << "Invalid login!\n";
    return false;
}

int main() {
    int choice;
    cout << "1. Register\n2. Login\nChoose: ";
    cin >> choice;
    if (!)

    if (choice == 1) registerUser();
    else if (choice == 2) loginUser();

return 0;
}