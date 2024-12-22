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
            // index = (index + i * i) % size; quadratic probing

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
