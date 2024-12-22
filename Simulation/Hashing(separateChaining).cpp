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
