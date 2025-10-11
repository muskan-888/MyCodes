// Bubble Sort implementation in C++
//
// This file contains a clear and commented implementation of the Bubble Sort
// algorithm. It includes:
//  - a `bubbleSort` function that sorts a vector<int> in ascending order
//  - optimization: stop early if the array becomes sorted before finishing
//  - complexity notes and stability information
//  - a `main` demonstrating the algorithm on several test cases
//
// Time complexity:
//  - Worst/Average: O(n^2)
//  - Best (already sorted): O(n) when using the early-exit optimization
// Space complexity: O(1) auxiliary (in-place)
// Stability: Bubble sort is stable because it only swaps adjacent elements
//
#include <bits/stdc++.h>
using namespace std;

// Performs bubble sort on the vector `a` in-place.
// If `n` is provided, it sorts the first `n` elements; otherwise sorts all.
// The function uses an early-exit optimization: if no swaps occur in a pass,
// the array is already sorted and the algorithm stops early.
void bubbleSort(vector<int>& a, int n = -1) {
    if (n == -1) n = (int)a.size();
    if (n <= 1) return; // trivially sorted

    for (int pass = 0; pass < n - 1; ++pass) {
        bool swapped = false;
        // After each pass, the largest element in the unsorted prefix
        // bubbles to its correct position at the end.
        for (int j = 0; j < n - 1 - pass; ++j) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        // If no elements were swapped in this pass, the array is sorted.
        if (!swapped) break;
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
    // Sample arrays to demonstrate behaviour and edge-cases
    vector<int> a = {64, 34, 25, 12, 22, 11, 90};
    vector<int> empty;
    vector<int> single = {42};
    vector<int> sorted = {1, 2, 3, 4, 5};
    vector<int> reverse_sorted = {5, 4, 3, 2, 1};
    vector<int> duplicates = {3, 1, 2, 3, 1, 2, 3};

    cout << "Original a:\n";
    printVector(a);
    bubbleSort(a);
    cout << "Sorted a:\n";
    printVector(a);

    cout << "Empty array (should print blank line):\n";
    bubbleSort(empty);
    printVector(empty);

    cout << "Single element (should be 42):\n";
    bubbleSort(single);
    printVector(single);

    cout << "Already sorted (should be 1 2 3 4 5):\n";
    bubbleSort(sorted);
    printVector(sorted);

    cout << "Reverse sorted (should be 1 2 3 4 5):\n";
    bubbleSort(reverse_sorted);
    printVector(reverse_sorted);

    cout << "Duplicates (should be 1 1 2 2 3 3 3):\n";
    bubbleSort(duplicates);
    printVector(duplicates);

    return 0;
}
