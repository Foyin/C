#include "Truck.h"

string Truck::toString() const
{
    ostringstream output;
    ostringstream make_model;
    make_model << make << " " << model;

    output << "\t" << "TRUCK:      ";
    output << setw(7) << colour << " " << year << " " << setw(17);
    output << make_model.str() << " (" << mileage << "km), ";
    output << numAxles << " axles" << endl;

    return output.str();
}

Truck::Truck(string ma, string mo, string col, int y, int m, int na) :
            Vehicle(ma, mo, col, y, m), numAxles(na) { }

int Truck::getNumAxles() { return numAxles; } 
