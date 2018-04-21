#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

using namespace std;

class Car : public Vehicle {

    friend ostream& operator<<(ostream&, Car&);

    public:
        Car(string ma, string mo, string col, int y, int m);
    
    private:
        virtual string toString() const;
};

#endif
