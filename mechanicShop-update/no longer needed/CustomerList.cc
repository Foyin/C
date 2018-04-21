#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

#include "CustomerList.h"

CustomerList::CustomerList() : head(0) { }


CustomerList::~CustomerList()
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

CustomerList& CustomerList::operator+=(Customer* newCust)
{
  Node *currNode, *prevNode;
  Node* newNode = new Node;
  newNode->data = newCust;
  newNode->next = 0;

  currNode = head;
  prevNode = 0;

  while (currNode != 0) {
    if (*(newNode->data) < *(currNode->data))
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

  return *this;
}

CustomerList& CustomerList::operator-=(Customer* cust)
{
  Node *currNode, *prevNode;

  currNode = head;
  prevNode = 0;

  while (currNode != 0) {
    if (currNode->data == cust)
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

Customer* CustomerList::get(int id) 
{
  Node *currNode = head;

  while (currNode != 0) {
    if(currNode->data->getId() == id) {
      return currNode->data;
    }
    currNode = currNode->next;
  }

  return 0;
}

int CustomerList::getSize() const {
  Node *currNode = head;
  int size = 0;

  while (currNode != 0) {
    currNode = currNode->next;
    size++;
  }
  
  return size;
}

Customer* CustomerList::operator[](int i) {
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

//void CustomerList::toString(string& outStr)
ostream& operator<<(ostream& output, CustomerList& cl)
{
  
  for (int i = 0; i < cl.getSize(); i++)  {
    output << (*(cl[i]));
  }
    
  return output;

}

