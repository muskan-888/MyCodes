// Insertion Sort implementation in C++
//
// This file demonstrates a clear, well-documented implementation of
// insertion sort suitable for learning, interviews, and competitive
// programming practice. It contains:
//  - `insertionSort` which sorts a vector<int> in-place
//  - complexity notes and stability information
//  - a small `main` demonstrating usage and covering edge cases
//
// Time complexity: O(n^2) worst and average, O(n) best (already sorted)
// Space complexity: O(1) auxiliary (in-place)
// Stability: Stable (equal elements keep original relative order)

#include <bits/stdc++.h>
using namespace std;

class Sorts {
public:
    // Perform insertion sort on vector `a` in ascending order.
    // This sorts the array in-place.
    //
    // Parameters:
    //  - a: reference to vector<int> to sort
    //
    // Behavior:
    //  - Iterates from the second element to the end and inserts each
    //    element into the sorted prefix to its left.
    static void insertionSort(vector<int>& a) {
        const int n = (int)a.size();
        for (int i = 1; i < n; ++i) {
            int key = a[i];
            int j = i - 1;

            // Move elements of a[0..i-1], that are greater than key,
            // to one position ahead of their current position.
            while (j >= 0 && a[j] > key) {
                a[j + 1] = a[j];
                --j;
            }
            // Place key after the element just smaller than it (or at 0)
            a[j + 1] = key;
        }
    }
};

// Helper to print vector contents on a single line separated by spaces
static void printVector(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) cout << ' ';
        cout << v[i];
    }
    cout << '\n';
}

int main() {
    // Example arrays covering several edge cases
    vector<int> a = {12, 11, 13, 5, 6};             // random order
    vector<int> b = {};                             // empty array
    vector<int> c = {1};                            // single element
    vector<int> d = {2, 2, 2, 2};                   // duplicates
    vector<int> e = {5, 4, 3, 2, 1};                // reverse-sorted

    cout << "Insertion Sort examples:\n";

    cout << "Original a: "; printVector(a);
    Sorts::insertionSort(a);
    cout << "Sorted a:   "; printVector(a);
    cout << "\n";

    cout << "Original b (empty): "; printVector(b);
    Sorts::insertionSort(b);
    cout << "Sorted b (empty):   "; printVector(b);
    cout << "\n";

    cout << "Original c (single): "; printVector(c);
    Sorts::insertionSort(c);
    cout << "Sorted c (single):   "; printVector(c);
    cout << "\n";

    cout << "Original d (dups): "; printVector(d);
    Sorts::insertionSort(d);
    cout << "Sorted d (dups):   "; printVector(d);
    cout << "\n";

    cout << "Original e (reverse): "; printVector(e);
    Sorts::insertionSort(e);
    cout << "Sorted e (reverse):   "; printVector(e);

    return 0;
}
