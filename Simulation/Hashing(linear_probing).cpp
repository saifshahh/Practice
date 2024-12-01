#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    vector<int> table;
    int table_size;

public:
    // Constructor
    HashTable(int size) : table(size, -1), table_size(size) {}

    // Hash function
    int hashFunction(int key) {
        return key % table_size;
    }

    // Insert key using linear probing
    void insert(int key) {
        int index = hashFunction(key);

        // Find next empty slot
        while (table[index] != -1 && table[index] != -2) {
            index = (index + 1) % table_size;
        }
        table[index] = key;
    }

    // Delete key
    void remove(int key) {
        int index = hashFunction(key);

        while (table[index] != -1) {
            if (table[index] == key) {
                table[index] = -2; // Mark as deleted
                return;
            }
            index = (index + 1) % table_size;
        }
        cout << "Key " << key << " not found!" << endl;
    }

    // Display hash table
    void display() {
        for (int i = 0; i < table_size; i++) {
            cout << "Index " << i << ": " << table[i] << endl;
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
