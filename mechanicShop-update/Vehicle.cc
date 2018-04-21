#include "Vehicle.h"

Vehicle::Vehicle(string ma, string mo, string col, int y, int m) { 
    make = ma;
    model = mo;
    colour = col;
    year = y;
    mileage = m;
}

string  Vehicle::getMake() const     { return make; }
string  Vehicle::getModel() const    { return model; }
string  Vehicle::getColour() const   { return colour; }
int     Vehicle::getYear() const     { return year; }
int     Vehicle::getMilage() const   { return mileage; }
/*
string Vehicle::toString() const
{
    ostringstream output;
    ostringstream make_model;
    make_model << make << " " << model;

    output << "\t" << setw(7) << colour << " " << year << " " << setw(17);
    output << make_model.str() << " (" << mileage << "km)" << endl;
  
    return output.str();
}*/


ostream& operator<<(ostream& output, Vehicle& v)
{
    /*    
    ostringstream make_model;
    make_model << v.make << " " << v.model;

    output << "\t" << setw(7) << v.colour << " " << v.year << " " << setw(17);
    output << make_model.str() << " (" << v.mileage << "km)" << endl;
    */
    return output << v.toString();
}

bool Vehicle::operator<(Vehicle& v)
{
    return year < v.year;
}

bool Vehicle::operator>(Vehicle& v)
{
    return year > v.year;
}
