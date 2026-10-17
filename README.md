# Custom Template Hash Table

This is a C++ project where I built a fully templated Hash Table data structure from scratch. Instead of using standard library containers, I handled the low-level memory tracking, indexing, and collision resolution manually. 

To test its performance at scale, the driver code streams 100,000 custom Customer profile objects directly into the table.

## Key Features
* **Chaining Collision Resolution:** Uses a custom `Node` structure acting as a linked list head at each array slot. If two keys hash to the same index, it seamlessly links them to handle collisions.
* **Fully Templated Class:** Designed with `template<class DataType>` so the table can map strings to any data type—whether it's a primitive `int` or a heavy, complex `Customer` object.
* **Custom Hashing Algorithm:** Features a polynomial rolling hash function that processes string keys using a prime multiplier (53) and wraps them around a fixed 100,000 capacity array to ensure clean distribution.
* **Operator Overloading:** Overloaded the standard `[]` brackets operator to allow clean, intuitive lookups and real-time value updates (e.g., `myHashTable["key"] = newValue`).

## Code Highlights
* **Memory Management:** Includes explicit destructor (`~HashTable`) routines to walk through individual chains and wipe memory cleanly, avoiding dangerous leaks.
* **Data Diagnostics:** Built a mapping utility (`mapTable`) that loops through the array buckets and prints out chain sizes to analyze collision density and algorithm efficiency.

## Tech Used
* C++
* CMake (for CLion configuration)

## How to Run
1. Clone this repo to your machine.
2. Ensure you have your tracking data (`randomCodes.txt`) and your database file (`customer_data/Customer.txt`) set up in the expected local directories.
3. Open the folder in CLion, let CMake sync, and run the main driver file.
