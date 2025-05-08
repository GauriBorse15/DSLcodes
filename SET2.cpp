#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

void displaySet(const set<int>& s) {
    cout << "{ ";
    for (int val : s) {
        cout << val << " ";
    }
    cout << "}" << endl;
}

int main() {
    set<int> A = {1, 2, 3};
    set<int> B = {2, 3, 4};

    cout << "Set A: ";
    displaySet(A);
    cout << "Set B: ";
    displaySet(B);

    // Add element
    A.insert(5);
    cout << "A after inserting 5: ";
    displaySet(A);

    // Remove element
    A.erase(2);
    cout << "A after removing 2: ";
    displaySet(A);

    // Contains
    cout << "A contains 3? " << (A.count(3) ? "Yes" : "No") << endl;

    // Size
    cout << "Size of A: " << A.size() << endl;

    // Union
    set<int> unionSet;
    set_union(A.begin(), A.end(), B.begin(), B.end(), inserter(unionSet, unionSet.begin()));
    cout << "Union of A and B: ";
    displaySet(unionSet);

    // Intersection
    set<int> interSet;
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), inserter(interSet, interSet.begin()));
    cout << "Intersection of A and B: ";
    displaySet(interSet);

    // Difference A - B
    set<int> diffSet;
    set_difference(A.begin(), A.end(), B.begin(), B.end(), inserter(diffSet, diffSet.begin()));
    cout << "Difference A - B: ";
    displaySet(diffSet);

    // Subset
    bool isSubset = includes(B.begin(), B.end(), interSet.begin(), interSet.end());
    cout << "Is Intersection a subset of B? " << (isSubset ? "Yes" : "No") << endl;

    return 0;
}
