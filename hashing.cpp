#include <iostream>
using namespace std;

class Hashing {
    long int table[10];

public:
    Hashing() {
        for (int i = 0; i < 10; i++)
            table[i] = -1;
    }

    void display() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < 10; i++)
            cout << i << ": " << table[i] << endl;
    }

    void insert(long int key, int type) {
        int index = key % 10;
        int newIndex;

        if (table[index] == -1) {
            table[index] = key;
            cout << "Inserted at index " << index << endl;
            return;
        }

        // Collision occurred, use probing
        if (type == 1) {
            // Linear Probing
            for (int i = 1; i < 10; i++) {
                newIndex = (index + i) % 10;
                if (table[newIndex] == -1) {
                    table[newIndex] = key;
                    cout << "Inserted at index " << newIndex << " using Linear Probing\n";
                    return;
                }
            }
        } else if (type == 2) {
            // Quadratic Probing
            for (int i = 1; i < 10; i++) {
                newIndex = (index + i * i) % 10;
                if (table[newIndex] == -1) {
                    table[newIndex] = key;
                    cout << "Inserted at index " << newIndex << " using Quadratic Probing\n";
                    return;
                }
            }
        }

        cout << "Hash table is full. Cannot insert.\n";
    }

    void search(long int key) {
        for (int i = 0; i < 10; i++) {
            if (table[i] == key) {
                cout << "Found at index " << i << endl;
                return;
            }
        }
        cout << "Not found in hash table\n";
    }
};

int main() {
    Hashing h;
    int choice;
    long int num;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert\n2. Search\n3. Display\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int type;
                cout << "Enter mobile number: ";
                cin >> num;
                cout << "Choose probing method:\n1. Linear Probing\n2. Quadratic Probing\nEnter choice: ";
                cin >> type;
                h.insert(num, type);
                break;
            }
            case 2:
                cout << "Enter number to search: ";
                cin >> num;
                h.search(num);
                break;
            case 3:
                h.display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
