//Linear Probing
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class HashTable {
private:
    vector<int> table;
    vector<bool> occupied;
    int size;
    int hashFunction(int key) {
        return key % size;
    }

public:
    HashTable(int s) : size(s) {
        table.resize(size, -1);
        occupied.resize(size, false);
    }

    // Insert a key
    void insert(int key) {
        int index = hashFunction(key);
        int start = index;
        while (occupied[index]) {
            index = (index + 1) % size; // Linear probing

            if (index == start) throw runtime_error("Hash table is full!");
        }
        table[index] = key;
        occupied[index] = true;
    }

    // Search for a key
    bool search(int key) {
        int index = hashFunction(key);
        int start = index;
        while (occupied[index]) {
            if (table[index] == key) return true;
            index = (index + 1) % size;
            if (index == start) break;
        }
        return false;
    }

    // Delete a key
    void remove(int key) {
        int index = hashFunction(key);
        int start = index;
        while (occupied[index]) {
            if (table[index] == key) {
                table[index] = -1;
                occupied[index] = false;
                return;
            }
            index = (index + 1) % size;
            if (index == start) break;
        }
        throw runtime_error("Key not found!");
    }

    // Display the hash table
    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << ": " << (occupied[i] ? to_string(table[i]) : "empty") << endl;
        }
    }
};

int main() {
    HashTable ht(7);

    ht.insert(10);
    ht.insert(20);
    ht.insert(15);

    ht.display();

    cout << "Search for 15: " << (ht.search(15) ? "Found" : "Not Found") << endl;

    ht.remove(15);
    cout << "After removing 15:" << endl;
    ht.display();

    return 0;
}


//Quadratic probing
#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    vector<int> table;
    vector<bool> occupied; // To track if a slot is occupied
    int size;

    // Primary hash function
    int hashFunction(int key) {
        return key % size;
    }

public:
    // Constructor
    HashTable(int s) : size(s) {
        table.resize(size, -1);  // Initialize table with -1 (empty slots)
        occupied.resize(size, false); // Mark all slots as unoccupied
    }

    // Insert a key
    void insert(int key) {
        for (int i = 0; i < size; i++) {
            int index = (hashFunction(key) + i * i) % size; // Quadratic probing
            if (!occupied[index]) { // Found an empty slot
                table[index] = key;
                occupied[index] = true;
                cout << "Inserted " << key << " at index " << index << endl;
                return;
            }
        }
        cout << "Hash table is full. Cannot insert " << key << endl;
    }

    // Search for a key
    bool search(int key) {
        for (int i = 0; i < size; i++) {
            int index = (hashFunction(key) + i * i) % size; // Quadratic probing
            if (!occupied[index]) return false; // Empty slot found, key not present
            if (table[index] == key) return true; // Key found
        }
        return false; // Searched all slots, key not found
    }

    // Delete a key
    void remove(int key) {
        for (int i = 0; i < size; i++) {
            int index = (hashFunction(key) + i * i) % size; // Quadratic probing
            if (!occupied[index]) break; // Empty slot, key not present
            if (table[index] == key) {
                table[index] = -1;       // Mark slot as empty
                occupied[index] = false; // Mark as unoccupied
                cout << "Removed " << key << " from index " << index << endl;
                return;
            }
        }
        cout << "Key " << key << " not found in hash table" << endl;
    }

    // Display the hash table
    void display() {
        cout << "Hash Table:" << endl;
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            if (occupied[i])
                cout << table[i] << endl;
            else
                cout << "NULL" << endl;
        }
    }
};

int main() {
    int tableSize = 7;
    HashTable ht(tableSize);

    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(30);
    ht.insert(40);

    ht.display();

    cout << "Searching for 15: " << (ht.search(15) ? "Found" : "Not Found") << endl;
    cout << "Searching for 25: " << (ht.search(25) ? "Found" : "Not Found") << endl;

    ht.remove(15);
    ht.display();

    return 0;
}


//Double Hashing
#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    vector<int> table;
    vector<bool> occupied; // To track if a slot is occupied
    int size;

    // Primary hash function
    int primaryHash(int key) {
        return key % size;
    }

    // Secondary hash function for step size
    int secondaryHash(int key) {
        return 1 + (key % (size - 1)); // Step size must not be zero
    }

public:
    // Constructor
    HashTable(int s) : size(s) {
        table.resize(size, -1);  // Initialize table with -1 (empty slots)
        occupied.resize(size, false); // Mark all slots as unoccupied
    }

    // Insert a key
    void insert(int key) {
        for (int i = 0; i < size; i++) {
            int index = (primaryHash(key) + i * secondaryHash(key)) % size; // Double hashing
            if (!occupied[index]) { // Found an empty slot
                table[index] = key;
                occupied[index] = true;
                cout << "Inserted " << key << " at index " << index << endl;
                return;
            }
        }
        cout << "Hash table is full. Cannot insert " << key << endl;
    }

    // Search for a key
    bool search(int key) {
        for (int i = 0; i < size; i++) {
            int index = (primaryHash(key) + i * secondaryHash(key)) % size; // Double hashing
            if (!occupied[index]) return false; // Empty slot found, key not present
            if (table[index] == key) return true; // Key found
        }
        return false; // Searched all slots, key not found
    }

    // Delete a key
    void remove(int key) {
        for (int i = 0; i < size; i++) {
            int index = (primaryHash(key) + i * secondaryHash(key)) % size; // Double hashing
            if (!occupied[index]) break; // Empty slot, key not present
            if (table[index] == key) {
                table[index] = -1;       // Mark slot as empty
                occupied[index] = false; // Mark as unoccupied
                cout << "Removed " << key << " from index " << index << endl;
                return;
            }
        }
        cout << "Key " << key << " not found in hash table" << endl;
    }

    // Display the hash table
    void display() {
        cout << "Hash Table:" << endl;
        for (int i = 0; i < size; i++) {
            cout << i << ": " << (occupied[i] ? to_string(table[i]) : "empty") << endl;
        }
    }
};

int main() {
    int tableSize = 7;
    HashTable ht(tableSize);

    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(30);
    ht.insert(40);

    ht.display();

    cout << "Searching for 15: " << (ht.search(15) ? "Found" : "Not Found") << endl;
    cout << "Searching for 25: " << (ht.search(25) ? "Found" : "Not Found") << endl;

    ht.remove(15);
    ht.display();

    return 0;
}
