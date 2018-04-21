#include "LinkedList.h"

template <class T>
LinkedList<T>::LinkedList() : head(0) { }

template <class T>
LinkedList<T>::~LinkedList()
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

template <class T>
LinkedList<T>& LinkedList<T>::operator+=(T* newData)
{
  Node *currNode, *prevNode;
  Node* newNode = new Node;
  newNode->data = newData;
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

template <class T>
LinkedList<T>& LinkedList<T>::operator-=(T* data)
{
  Node *currNode, *prevNode;

  currNode = head;
  prevNode = 0;

  while (currNode != 0) {
    if (currNode->data == data)
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

template <class T>
int LinkedList<T>::getSize() const {
  Node *currNode = head;
  int size = 0;

  while (currNode != 0) {
    currNode = currNode->next;
    size++;
  }
  
  return size;
}

template <class T>
T* LinkedList<T>::operator[](int i) {
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

template <class T>
ostream& operator<<(ostream& output, LinkedList<T>& l)
{
  
  for (int i = 0; i < l.getSize(); i++)  {
    output << (*(l[i]));
  }
    
  return output;

}

