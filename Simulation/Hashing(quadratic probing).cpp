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

    // Insert key using quadratic probing
    void insert(int key) {
        int index = hashFunction(key);
        int i = 0;

        // Quadratic probing: (index + i^2) % table_size
        while (table[(index + i * i) % table_size] != -1) {
            i++;
        }
        table[(index + i * i) % table_size] = key;
    }

    // Delete key
    void remove(int key) {
        int index = hashFunction(key);
        int i = 0;

        while (table[(index + i * i) % table_size] != -1) {
            if (table[(index + i * i) % table_size] == key) {
                table[(index + i * i) % table_size] = -2; // Mark as deleted
                return;
            }
            i++;
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
