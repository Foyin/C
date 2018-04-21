#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;

#include <string>
#include "View.h"
#include "Vehicle.h"


void View::mainMenu(int& choice) {
    string str;

    choice = -1;

    cout<< "\n\n\n         **** Toby's Auto Mechanic Information Management System ****\n\n";
    cout<< "                                 MAIN MENU\n\n";
    cout<< "        1. Print Customer Database\n\n";
    cout<< "        2. Add Customer\n\n";
    cout<< "        3. Add Vehicle\n\n";
    cout<< "        4. Remove Customer\n\n";
    cout<< "        5. Remove Vehicle\n\n";
    cout<< "        6. Print Mechanics\n\n";
    cout<< "        0. Exit\n\n";

    while (choice < 0 || choice > 6) {
        cout << "Enter your selection:  ";
        choice = readInt();
    }

    if (choice == 0) { cout << endl; }
}

void View::displayInvalid() { cout << "Invalid choice." << endl << endl; }

void View::promptUserInfo(string &fname, string &lname, string &address, string &phone) {
    cout << "\nFirst name: ";
    getline(cin, fname);
    cout << "Last name: ";
    getline(cin, lname);
    cout << "Address: ";
    getline(cin, address);
    cout << "Phone number: ";
    getline(cin, phone);
    cout<<endl;
}

void View::promptVehicleInfo(string &make, string &model, string &colour, 
                                int &year, int &mileage) {
    cout << "\nMake: ";
    getline(cin, make);
    cout << "Model: ";
    getline(cin, model);
    cout << "Colour: ";
    getline(cin, colour);
    cout << "Year: ";
    year = readInt();
    cout << "Mileage: ";
    mileage = readInt();
    cout<<endl;
}

void View::promptNumAxles(int& na) {
    cout << "Number of axles: ";
    na = readInt();
    cout<<endl;
}

void View::promptSideCar(bool& c) {
    string choice("");

    while (choice != "y" && choice != "n") {  
        cout << "Has sidecar (y/n): ";
        getline(cin, choice);
    }
    cout<<endl;
    c = (choice == "y");
}

void View::promptVehicleChoice(int &choice) {
    choice = -1;

    while (choice < 0 || choice > 3) {
        cout << "Vehicle Type (1: Car, 2: Truck, 3: Motorcycle): ";
        choice = readInt();
    }
}

void View::promptUserId(int &id) {
    cout << "Customer ID: ";
    id = readInt();
    cout<<endl;
}

void View::printCustomers(LinkedList<Customer>& arr) const {
    cout << endl << "CUSTOMERS: " << endl << endl << arr << endl;
}

void View::printMechanics(LinkedList<Mechanic>& arr) const {
    /*cout << endl << "MECHANICS: " << endl << endl;
    for (int i = 0; i < n; i++) {
        cout << *(m[i]) << endl;
    }
    cout << endl;*/
    cout << endl << "MECHANICS: " << endl << endl << arr << endl;
}

void View::pause() const {
    string str;

    cout << "Press enter to continue...";
    getline(cin, str);
}

int View::readInt() const {
    string str;
    int    num;

    getline(cin, str);
    stringstream ss(str);
    ss >> num;

    return num;
}

void View::promptVehicle(int numVehicles, int &choice) {
    cout << "Vehicle (0 - " << numVehicles-1 << "): ";
    choice = readInt();
    cout << endl;
}
