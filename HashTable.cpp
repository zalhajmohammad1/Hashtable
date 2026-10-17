#ifndef HASHTABLE_CPP
#define HASHTABLE_CPP

#include "HashTable.h"

#include <iostream>
#include <stdexcept>


template<class DataType>
HashTable<DataType>::HashTable() {
  for (int i = 0; i < CAPACITY; i++) {
    dataArr[i] = nullptr;
  }
}





template<class DataType>
HashTable<DataType>::HashTable(const HashTable<DataType> &other) {

  for (int i = 0; i < CAPACITY; i++) {dataArr[i] = nullptr;}

  *this = other;

}




template<class DataType>
HashTable<DataType>::~HashTable() {

 if (!isEmpty()) {
   makeEmpty();
 }

  else {
    std::cout << "Nothing to destruct" << std::endl;
  }
}





template<class DataType>
void HashTable<DataType>::insert(std::string key,DataType value) {

  int hashResult = hashFunction(key);

  Node<DataType>* node = new Node<DataType>;
  node->key = key;
  node->data = value;

  Node<DataType>* head = dataArr[hashResult];
  Node<DataType>* curr = head;

  while (curr != nullptr) {

    if (curr->key == node->key) { curr->data = node->data;  delete node; return; }

    curr = curr->next;

  }

  node->next = head;
  dataArr[hashResult] = node; // two totally different keys can result in the same index, this the linking that could happen here

}




template<class DataType>
bool HashTable<DataType>::isFull() {

return false;

}





template<class DataType>
bool HashTable<DataType>::isEmpty() {

  int sum;

  for (int i =0; i < CAPACITY; i++) {
    if (dataArr[i] == nullptr) sum += 1;
  }
  if (sum == CAPACITY) return true;

  return false;
}





template<class DataType>
void HashTable<DataType>::makeEmpty() {

  if (getLength() > 0) {
    for (int i = 0; i < CAPACITY; i++) {

      Node<DataType>* curr = dataArr[i];
      while (curr != nullptr){ Node<DataType>* prev = curr; curr = curr->next; delete prev;}
      dataArr[i] = nullptr;
    }
  }
else {
  std::cout << "table is already empty " << std::endl;
}
}








template<class DataType>
DataType &HashTable<DataType>::search(std::string key) {


  int hashResult = hashFunction(key);

  Node<DataType>* curr = dataArr[hashResult];

  while (curr != nullptr) { if (curr->key == key) {return curr->data;} curr = curr->next; }

  throw std::runtime_error("Key not found");


}








template<class DataType>
void HashTable<DataType>::deleteKey(std::string key) {
  int hashResult = hashFunction(key);

  Node<DataType>* curr = dataArr[hashResult];
  Node<DataType>* prev = nullptr;

  if (curr == nullptr) return; //throw std::invalid_argument("Key does not exist");


    while (curr!= nullptr) {
      if (curr->key == key) {
        if ( prev == nullptr)
        { Node<DataType>* temp = curr; curr = curr->next; temp->key = ""; delete temp; dataArr[hashResult] = curr; return; } //if item is at the beginning of the list
          Node<DataType>* temp = curr; curr = curr->next; temp->key = ""; delete temp; prev->next = curr; return; //if item is at the middle or the end of the list
      }

      prev = curr; curr = curr->next;

    }

}









template<class DataType>
int HashTable<DataType>::getLength() {

  int sum = 0;


for (int i = 0; i < CAPACITY; i++) {

  Node<DataType>* curr = dataArr[i];
  if (curr != nullptr){sum += 1;}

}
  return sum;
}








template<class DataType>
DataType &HashTable<DataType>::operator[](std::string key) {
  return search(key);
}







template<class DataType>
void HashTable<DataType>::mapTable() {


 // std::vector<std::string> amounts;
  for (int i = 0; i < CAPACITY; i++) {

    int nodeCount = 0;
    Node<DataType>* curr = dataArr[i];


    if (dataArr[i] != nullptr) {
      while (curr != nullptr) { nodeCount++; curr = curr->next;}
      std::cout << "At index " << i + 1 << " there are: " << nodeCount << " node(s)" << std::endl;
      nodeCount = 0;
    }

    else {
      std::cout << "At index " << i + 1 << " there are no nodes" << std::endl;
    }
  }
}







template<class DataType>
HashTable<DataType> &HashTable<DataType>::operator=(const HashTable<DataType> &other) {

  if (this == &other)  { return *this; }

  if (!isEmpty()) { makeEmpty(); }

  makeEmpty();
  for (int i = 0; i < CAPACITY; i++) {
    Node<DataType>* curr = other.dataArr[i];

    while (curr!= nullptr){ this->insert(curr->key, curr->data); curr = curr->next;}
  }

  return *this;

}

#endif