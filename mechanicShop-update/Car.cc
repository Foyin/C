#include "Car.h"

Car::Car(string ma, string mo, string col, int y, int m) :
        Vehicle(ma, mo, col, y, m) { }

string Car::toString() const
{
    ostringstream output;
    ostringstream make_model;
    make_model << make << " " << model;
    
    output << "\t" << "CAR:        ";
    output << setw(7) << colour << " " << year << " " << setw(17);
    output << make_model.str() << " (" << mileage << "km)" << endl;
  
    return output.str();
}

/*
ostream& operator<<(ostream& output, Car& c)
{
    /*
    ostringstream make_model;
    make_model << c.make << " " << c.model;
    
    output << "\t" << "CAR:        ";
    output << setw(7) << c.colour << " " << c.year << " " << setw(17);
    output << make_model.str() << " (" << c.mileage << "km)" << endl;
    //
    return output << c.toString();
}*/
