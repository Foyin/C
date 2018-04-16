#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;
#include <string>

#include "VehicleList.h"

VehicleList::VehicleList() : head(0) { }


VehicleList::~VehicleList()
{
  Node *currNode, *nextNode;

  currNode = head;

  while (currNode != 0) {
    nextNode = currNode->next;
    delete currNode->data;
    delete currNode;
    currNode = nextNode;
  }
}


//void VehicleList::add(Vehicle* newVeh)
VehicleList& VehicleList::operator+=(Vehicle* newVeh)
{
  Node *currNode, *prevNode;
  Node* newNode = new Node;
  newNode->data = newVeh;
  newNode->next = 0;

  currNode = head;
  prevNode = 0;

  while (currNode != 0) {
    if (*(newNode->data) > *(currNode->data))
      break;
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (prevNode == 0) {
    head = newNode;
  }
  else {
    prevNode->next = newNode;
  }

  newNode->next = currNode;
}

VehicleList& VehicleList::operator-=(Vehicle* v)
{
  Node *currNode, *prevNode;

  currNode = head;
  prevNode = 0;

  while (currNode != 0) {
    if (currNode->data == v)
      break;
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (currNode == 0) 
    return *this;

  if (prevNode == 0) {
    head = currNode->next;
  }
  else {
    prevNode->next = currNode->next;
  }

  delete currNode;

  return *this;
}


int VehicleList::getSize() const {
  Node *currNode = head;
  int size = 0;

  while (currNode != 0) {
    currNode = currNode->next;
    size++;
  }
  
  return size;
}

Vehicle* VehicleList::operator[](int i) {
    if(i < 0 || i > (getSize()-1)) {
        return 0;
    } else {

        Node *currNode = head;

        for (int j = 0; j < i; j++) {
            currNode = currNode->next;
        }

        return currNode->data;
    }
}

//void VehicleList::toString(string& outStr)
ostream& operator<<(ostream& output, VehicleList& vl)
{
  
  for (int i = 0; i < vl.getSize(); i++)  {
    output << (*(vl[i]));
  }
    
  return output;

}

