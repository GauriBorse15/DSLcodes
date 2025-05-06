#include <iostream>
using namespace std;

class Set {
    int set[10];
    int cnt = 0;

public:
    void insert();
    void display();
    int search(int key);
    void size();
    void remove();
    void Union(Set A, Set B);
    void intersection(Set A, Set B);
    void difference(Set A, Set B);
    void subset(Set A, Set B);

    // For resetting set before each operation
    void reset() {
        cnt = 0;
    }
};

void Set::insert() {
    int n;
    cout << "Enter the number of elements in set: ";
    cin >> n;
    cout << "Enter elements of set: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        if (search(val) == -1) {
            set[cnt++] = val;
        } else {
            cout << "Duplicate " << val << " not inserted.\n";
        }
    }
}

void Set::display() {
    cout << "SET = { ";
    for (int i = 0; i < cnt; i++) {
        cout << set[i] << " ";
    }
    cout << "}\n";
}

int Set::search(int x) {
    for (int i = 0; i < cnt; i++) {
        if (x == set[i]) {
            return i;
        }
    }
    return -1;
}

void Set::size() {
    cout << "Size of set is: " << cnt << endl;
}

void Set::remove() {
    int key, temp;
    cout << "Enter key to be removed: ";
    cin >> key;
    temp = search(key);
    if (temp != -1) {
        for (int i = temp; i < cnt - 1; i++) {
            set[i] = set[i + 1];
        }
        cnt--;
        cout << "Key " << key << " removed successfully.\n";
    } else {
        cout << "Key not found\n";
    }
}

void Set::Union(Set A, Set B) {
    reset();
    for (int i = 0; i < A.cnt; i++) {
        set[cnt++] = A.set[i];
    }
    for (int i = 0; i < B.cnt; i++) {
        if (search(B.set[i]) == -1) {
            set[cnt++] = B.set[i];
        }
    }
}

void Set::intersection(Set A, Set B) {
    reset();
    for (int i = 0; i < A.cnt; i++) {
        if (B.search(A.set[i]) != -1) {
            if (search(A.set[i]) == -1) {
                set[cnt++] = A.set[i];
            }
        }
    }
}

// Difference shows elements in A not in B.
void Set::difference(Set A, Set B) { 
    reset();
    for (int i = 0; i < A.cnt; i++) {
        if (B.search(A.set[i]) == -1) {
            set[cnt++] = A.set[i];
        }
    }
}

// Subset check correctly evaluates whether all A elements are in B.
void Set::subset(Set A, Set B) {
    for (int i = 0; i < A.cnt; i++) {
        if (B.search(A.set[i]) == -1) {
            cout << "Set A is not a subset of Set B.\n";
            return;
        }
    }
    cout << "Set A is a subset of Set B.\n";
}

int main() {
    int choice, num;
    Set A, B, C;

    do {
        cout << "\nMENU";
        cout << "\n1. Insert into Set A";
        cout << "\n2. Display Set A";
        cout << "\n3. Search an element from Set A";
        cout << "\n4. Remove an element from Set A";
        cout << "\n5. Size of Set A";
        cout << "\n6. Union of Set A and Set B";
        cout << "\n7. Intersection of Set A and Set B";
        cout << "\n8. Difference of Set A and Set B (A - B)";
        cout << "\n9. Check if Set A is a subset of Set B";
        cout << "\n10. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            A.insert();
            break;
        case 2:
            A.display();
            break;
        case 3:
            cout << "Enter element to be searched: ";
            cin >> num;
            {
                int res = A.search(num);
                if (res != -1)
                    cout << "Number " << num << " is at position " << res << endl;
                else
                    cout << "Number not found in the set\n";
            }
            break;
        case 4:
            A.remove();
            break;
        case 5:
            A.size();
            break;
        case 6:
            cout << "Insert elements into Set B:\n";
            B.insert();
            C.Union(A, B);
            cout << "Union of Set A and Set B:\n";
            C.display();
            break;
        case 7:
            cout << "Insert elements into Set B:\n";
            B.insert();
            C.intersection(A, B);
            cout << "Intersection of Set A and Set B:\n";
            C.display();
            break;
        case 8:
            cout << "Insert elements into Set B:\n";
            B.insert();
            C.difference(A, B);
            cout << "Difference of Set A and Set B (A - B):\n";
            C.display();
            break;
        case 9:
            cout << "Insert elements into Set B:\n";
            B.insert();
            C.subset(A, B);
            break;
        case 10:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 10);

    return 0;
}
