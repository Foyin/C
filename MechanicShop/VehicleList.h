#ifndef VEHICLELIST_H
#define VEHICLELIST_H

#include "Vehicle.h"


class VehicleList
{
  friend ostream& operator<<(ostream&, VehicleList&);

  class Node
  {
    friend class VehicleList;
    private:
      Vehicle* data;
      Node*    next;
  };

  public:
    VehicleList();
    ~VehicleList();
    //void add(Vehicle*);
    //void toString(string&);
    int getSize() const;
    
    VehicleList& operator+=(Vehicle*);
    VehicleList& operator-=(Vehicle*);
    Vehicle* operator[](int);

  private:
    Node* head;
};

#endif
