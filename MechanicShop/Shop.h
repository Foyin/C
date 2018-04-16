#ifndef SHOP_H
#define SHOP_H

#define MAX_MECHANICS    5

#include "Mechanic.h"
#include "Customer.h"
#include "CustomerList.h"

class Shop{

    public:
        Shop();
        ~Shop();
        //void addCustomer(Customer*);
        Shop& operator+=(Customer*);  
		Shop& operator-=(Customer*);      
        Customer* getCustomer(int);
        CustomerList& getCustomers();
        Shop& operator+=(Mechanic*);
        int getNumMechanics();
        Mechanic** getMechanics();

    private:
        CustomerList customers;
        int numMechanics;
        Mechanic* mechanics[MAX_MECHANICS];
};

#endif
