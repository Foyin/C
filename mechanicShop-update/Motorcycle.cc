#include "Motorcycle.h"

string Motorcycle::toString() const
{
    ostringstream output;
    ostringstream make_model;
    make_model << make << " " << model;

    output << "\t" << "MOTORCYCLE: ";
    output << setw(7) << colour << " " << year << " " << setw(17);
    output << make_model.str() << " (" << mileage << "km)";
    if (hasSideCar()) {
        output << ", has sidecar" << endl;
    } else {
        output << ", doesn't have sidecar" << endl;
    }

    return output.str();
}

Motorcycle::Motorcycle(string ma, string mo, string col, int y, int m, bool s) :
            Vehicle(ma, mo, col, y, m), sideCar(s) { }

bool Motorcycle::hasSideCar() const { return sideCar; } 
