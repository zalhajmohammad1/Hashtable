#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>

const int CAPACITY = 100000;


/**
 * this is thr structure for each node. Each node will hold the key, data, and a next pointer to the next node in case of
 * a collision 
 * @tparam DataType // should be able to hold and point to any data type
 */
template<class DataType>
 struct Node {

    Node<DataType>* next;
    DataType data;
    std::string key;

};


/**
 * @class HashTable
 * @brief represents a hash table
 * @tparam DataType // templated items should be able to hold any data type
 */
template <class DataType>
class HashTable {

private:
 /**
  * helper private method that generates as much unique index as possible for every new key in an item pair
  * @param key // a key of a string format that turns into an index
  * @return returns the index created from the key
  */
 int hashFunction(std::string key) {

        int hash = 0;

        for (char curr : key) {

             hash = ((hash * 53 + curr) % CAPACITY);

        }
            return hash;
    }

    Node<DataType>* dataArr[CAPACITY];



public:
    /**
     * default constructor that sets each bucket to nullptr by default
     */
    HashTable();


    /**
     * parameterized copy constructor
     * @param other the rhs object to be copied into the brand new object
     */
    HashTable(const HashTable<DataType>& other);

    /**
     * destructor that deletes the hashtable
     */
    ~HashTable();

    /**
     * public method that inserts items into the hashtable
     * @param key // each unique key to a new element
     * @param value // the type of element to be inserted into the hashtable
     */
    void insert(std::string key, DataType value);

    /**
     * public method that searches for a particular item from the hashtable
     * @param key // the key for the item to be searched
     * @return returns the item if its found. Throws an error if not
     */
    DataType& search(std::string key);

    /**
     * public method that deletes a particular element from the hashtable
     * @param key the key for that element to be deleted
     */
    void deleteKey(std::string key);

    /**
     * getter accessor method that returns the length of the hashtable array
     * @return returns the sum of the array size
     */
    int getLength();

    /**
     * checks for if the hashtable is full
     * @return returns false
     */
    bool isFull();

    /**
     *  checks for if the hashtable is empty or not
     * @return returns true or false
     */
    bool isEmpty();

    /**
     * public method that empties all elements in the hashtable
     */
    void makeEmpty();

    /**
     * overloaded [] operator that returns a value thats associated with a given key
     * @param key // the key to find a particular item in the hashtable
     * @return returns the item
     */
    DataType& operator[](std::string key);

    /**
     *  prints the size of every linked list in the hashtable
     */
    void mapTable();

    /**
     * overloaded assignment operator that sets a hashtable equal to another
     * @param other // the desired hashtable to be copied into the other one
     * @return returns the newly copied hashtable
     */
    HashTable<DataType>& operator=(const HashTable<DataType>& other);






};





#include "HashTable.cpp"  // Include implementation for template class
#endif
