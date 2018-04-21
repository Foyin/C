#ifndef TRUCK_H
#define TRUCK_H

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Vehicle.h"

using namespace std;

class Truck : public Vehicle {

    friend ostream& operator<<(ostream&, Truck&);

    public:
        Truck(string ma, string mo, string col, int y, int m, int na);
        int getNumAxles();       

    private:
        virtual string toString() const;
        int numAxles;
};

#endif
