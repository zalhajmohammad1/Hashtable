#include <unordered_map>
#include <string>
#include <vector>
#include <fstream>
#include "HashTable.h"
#include "Customer.h"

int main() {


    std::cout << "A brand new hashtable has been created " << std::endl;
    HashTable<int> myHashTable = HashTable<int>();


    myHashTable.insert("test 1", 3);
    myHashTable.insert("test 2", 4);

    std::cout << "The first item in the map is: ";
  std::cout << myHashTable["test 1"]; std::cout << std::endl;

    std::cout << "The first item in the map has been modified to: ";
    myHashTable["test 1"] = 9;

   // std::cout << std::endl;
    std::cout << myHashTable["test 1"];






    std::vector<std::string> keys;
    std::ifstream file1("randomCodes.txt");

    if (file1.is_open()) {
        std::string line;
        while (std::getline(file1, line)) {
            keys.push_back(line);
        }
        file1.close();
    } else {
        throw std::invalid_argument("File could not be opened");
    }







    HashTable<Customer> myHashTable2 = HashTable<Customer>();

    std::ifstream file2("customer_data/Customer.txt");

    if (!file2.is_open()) {
        throw std::runtime_error("Could not open file");
    }


        std::string line;

        std::getline(file2, line);


        for (int i = 0; i < CAPACITY ; i++) {

            std::getline(file2, line);

            Customer* customer = new Customer(line);

            myHashTable2.insert(keys[i] , *customer );



        }

    std::cout << "Processing customers: ..." << std::endl;
     myHashTable2.mapTable();


    return 0;

}
