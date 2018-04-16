#include "Shop.h"
#include "defs.h"

Shop::Shop() : numMechanics(0) { }

Shop::~Shop() {
    for (int i=0; i < numMechanics; i++) 
        delete mechanics[i];
}

//void Shop::addCustomer(Customer* c) { customers += c; }
Shop& Shop::operator+=(Customer* c) { 
    customers += c; 
    return *this;
}

Shop& Shop::operator-=(Customer* c) { 
    customers -= c; 
    return *this;
}

Customer* Shop::getCustomer(int i)  { return customers.get(i); } 

CustomerList& Shop::getCustomers() { return customers; }

Shop& Shop::operator+=(Mechanic* m) {    
    if(numMechanics < MAX_MECHANICS) {
        mechanics[numMechanics] = m;
        numMechanics++;
    }

    return *this;
}

int Shop::getNumMechanics()     { return numMechanics; }
Mechanic** Shop::getMechanics()  { return mechanics; }
