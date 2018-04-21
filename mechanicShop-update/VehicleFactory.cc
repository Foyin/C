#include "VehicleFactory.h"

Vehicle* VehicleFactory::create(string ma, string mo, string col, int y, int m) {
    return new Car(ma, mo, col, y, m);
}

Vehicle* VehicleFactory::create(string ma, string mo, string col, int y, int m, int na) {
    return new Truck(ma, mo, col, y, m, na);
}

Vehicle* VehicleFactory::create(string ma, string mo, string col, int y, int m, bool s) {
    return new Motorcycle(ma, mo, col, y, m, s);
}
