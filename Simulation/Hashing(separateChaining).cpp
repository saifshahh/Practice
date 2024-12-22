#include <iostream>
#include <list>
#include <vector>
using namespace std;

// Class representing a Hash Table
class HashTable {
private:
    vector<list<int>> table; // Vector of lists
    int size;                // Number of buckets

    // Hash function
    int hashFunction(int key) {
        return key % size;
    }

public:
    HashTable(int s) : size(s) {
        table.resize(size); // Initialize buckets
    }

    // Insert a key
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    // Delete a key
    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    // Search for a key
    bool search(int key) {
        int index = hashFunction(key);
        for (int val : table[index]) {
            if (val == key) return true;
        }
        return false;
    }

    // Display the hash table
    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            for (int val : table[i]) {
                cout << val << " -> ";
            }
            cout << "nullptr" << endl;
        }
    }
};

int main() {
    HashTable ht(5);

    ht.insert(10);
    ht.insert(15);
    ht.insert(20);
    ht.insert(25);
    ht.insert(33);

    ht.display();

    cout << "Search for 15: " << (ht.search(15) ? "Found" : "Not Found") << endl;

    ht.remove(15);
    cout << "After removing 15:" << endl;
    ht.display();

    return 0;
}


with array:

#include <iostream>
#include <list>
using namespace std;

class HashTable {
private:
    int table_size;
    list<int> *table; // Array of linked lists

public:
    // Constructor
    HashTable(int size) {
        table_size = size;
        table = new list<int>[table_size];
    }

    // Hash function
    int hashFunction(int key) {
        return key % table_size;
    }

    // Insert key into hash table
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    // Delete key from hash table
    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    // Display the hash table
    void display() {
        for (int i = 0; i < table_size; i++) {
            cout << "Index " << i << ": ";
            for (int key : table[i]) {
                cout << key << " -> ";
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    HashTable ht(7);

    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(7);

    cout << "Hash Table after insertions:" << endl;
    ht.display();

    ht.remove(15);
    cout << "Hash Table after deletion of 15:" << endl;
    ht.display();

    return 0;
}
