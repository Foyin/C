#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Vehicle.h"

using namespace std;

class Motorcycle : public Vehicle {

    friend ostream& operator<<(ostream&, Motorcycle&);

    public:
        Motorcycle(string, string, string, int, int, bool);
        bool hasSideCar() const;       

    private:
        virtual string toString() const;
        bool sideCar;
};

#endif
