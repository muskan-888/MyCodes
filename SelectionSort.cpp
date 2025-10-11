// Selection Sort implementation in C++
//
// This file includes a clear and commented implementation of Selection Sort.
// Features:
//  - `selectionSort` sorts a vector<int> in ascending order in-place
//  - explanatory comments, time/space complexity and stability notes
//  - a `main` demonstrating the algorithm on several test cases
//
// Time complexity:
//  - Best/Average/Worst: O(n^2)
// Space complexity: O(1) auxiliary (in-place)
// Stability: Selection sort is NOT stable by default because it swaps
//            the minimum element with the first unsorted element which
//            can change the relative order of equal elements.

#include <bits/stdc++.h>
using namespace std;

// Perform selection sort on the first `n` elements of `a` (or whole vector
// if n == -1). The algorithm repeatedly selects the minimum element from
// the unsorted prefix and swaps it into place.
void selectionSort(vector<int>& a, int n = -1) {
    if (n == -1) n = (int)a.size();
    if (n <= 1) return; // already sorted

    for (int i = 0; i < n - 1; ++i) {
        // Find index of the minimum element in a[i..n-1]
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[minIdx]) {
                minIdx = j;
            }
        }
        // Swap the found minimum element with the first element of the
        // unsorted region. If minIdx == i, this is a no-op.
        if (minIdx != i) swap(a[i], a[minIdx]);
    }
}

// Pretty-print a vector to stdout
static void printVector(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) cout << ' ';
        cout << v[i];
    }
    cout << '\n';
}

int main() {
    vector<int> a = {64, 25, 12, 22, 11};
    vector<int> empty;
    vector<int> single = {7};
    vector<int> sorted = {1, 2, 3, 4, 5};
    vector<int> reverse_sorted = {5, 4, 3, 2, 1};
    vector<int> duplicates = {4, 2, 4, 2, 1, 1};

    cout << "Original a:\n";
    printVector(a);
    selectionSort(a);
    cout << "Sorted a:\n";
    printVector(a);

    cout << "Empty array (should print blank line):\n";
    selectionSort(empty);
    printVector(empty);

    cout << "Single element (should be 7):\n";
    selectionSort(single);
    printVector(single);

    cout << "Already sorted (should be 1 2 3 4 5):\n";
    selectionSort(sorted);
    printVector(sorted);

    cout << "Reverse sorted (should be 1 2 3 4 5):\n";
    selectionSort(reverse_sorted);
    printVector(reverse_sorted);

    cout << "Duplicates (note: selection sort is not stable) (expected sorted):\n";
    selectionSort(duplicates);
    printVector(duplicates);

    return 0;
}
