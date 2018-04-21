#include "Shop.h"
#include "defs.h"

//Shop::Shop() { }

/*Shop::~Shop() {
    for (int i=0; i < numMechanics; i++) 
        delete mechanics[i];
}*/

//void Shop::addCustomer(Customer* c) { customers += c; }
Shop& Shop::operator+=(Customer* c) { 
    customers += c; 
    return *this;
}

Shop& Shop::operator-=(Customer* c) { 
    customers -= c; 
    return *this;
}

Customer* Shop::getCustomer(int id)  { 
    //return customers.get(i); } 
    for (int i = 0; i < customers.getSize(); i++)  {
        if (customers[i]->getId() == id)
            return customers[i];
    }
    return 0;
}

LinkedList<Customer>& Shop::getCustomers() { return customers; }

Shop& Shop::operator+=(Mechanic* m) {    
    /*if(numMechanics < MAX_MECHANICS) {
        mechanics[numMechanics] = m;
        numMechanics++;
    }*/
    mechanics += m;
    return *this;
}

//int Shop::getNumMechanics()     { return numMechanics; }
LinkedList<Mechanic>& Shop::getMechanics()  { return mechanics; }
