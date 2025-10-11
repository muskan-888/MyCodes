// Quick Sort implementation in C++ (randomized pivot, Lomuto partition)
//
// This file provides a clear and commented Quick Sort implementation.
// Highlights:
//  - Uses a randomized pivot to avoid worst-case inputs (common quick hack)
//  - Implements Lomuto partition scheme for simplicity
//  - Recursive quickSort with wrapper that seeds a random engine
//  - Complexity notes and stability information
//
// Average time complexity: O(n log n)
// Worst-case time complexity: O(n^2) (mitigated by randomized pivot selection)
// Space complexity: O(log n) expected for recursion stack (worst O(n))
// Stability: Not stable (swaps can change relative order of equal elements)

#include <bits/stdc++.h>
using namespace std;

// Partition using Lomuto scheme with pivot at `r`.
// Returns the final pivot index.
static int lomutoPartition(vector<int>& a, int l, int r) {
    int pivot = a[r];
    int i = l; // place for swapping
    for (int j = l; j < r; ++j) {
        if (a[j] < pivot) {
            swap(a[i], a[j]);
            ++i;
        }
    }
    swap(a[i], a[r]);
    return i;
}

// Randomized partition: pick a pivot index uniformly at random between l and r,
// swap it with a[r], then run Lomuto partition.
static int randomizedPartition(vector<int>& a, int l, int r, mt19937& rng) {
    uniform_int_distribution<int> dist(l, r);
    int pivotIndex = dist(rng);
    swap(a[pivotIndex], a[r]);
    return lomutoPartition(a, l, r);
}

// Recursive quicksort on a[l..r]
static void quickSortRec(vector<int>& a, int l, int r, mt19937& rng) {
    if (l >= r) return; // zero or one element

    int p = randomizedPartition(a, l, r, rng);
    // Sort left and right partitions
    quickSortRec(a, l, p - 1, rng);
    quickSortRec(a, p + 1, r, rng);
}

// Public wrapper: sorts the whole vector and seeds RNG with random_device
void quickSort(vector<int>& a) {
    if (a.size() <= 1) return;
    // Use a random device to seed the mt19937 engine for randomized pivot
    random_device rd;
    mt19937 rng(rd());
    quickSortRec(a, 0, (int)a.size() - 1, rng);
}

// Helper to print a vector on one line
static void printVector(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) cout << ' ';
        cout << v[i];
    }
    cout << '\n';
}

int main() {
    // Demonstration arrays
    vector<int> a = {10, 7, 8, 9, 1, 5};
    vector<int> empty;
    vector<int> single = {42};
    vector<int> sorted = {1, 2, 3, 4, 5};
    vector<int> reverse_sorted = {5, 4, 3, 2, 1};
    vector<int> duplicates = {3, 6, 8, 3, 2, 8, 1, 3};

    cout << "Original a:\n";
    printVector(a);
    quickSort(a);
    cout << "Sorted a:\n";
    printVector(a);

    cout << "Empty array (should be blank):\n";
    quickSort(empty);
    printVector(empty);

    cout << "Single element (should be 42):\n";
    quickSort(single);
    printVector(single);

    cout << "Already sorted (should be 1 2 3 4 5):\n";
    quickSort(sorted);
    printVector(sorted);

    cout << "Reverse sorted (should be 1 2 3 4 5):\n";
    quickSort(reverse_sorted);
    printVector(reverse_sorted);

    cout << "Duplicates (should be sorted):\n";
    quickSort(duplicates);
    printVector(duplicates);

    // Quick random stress example (small)
    vector<int> rnd(15);
    mt19937 rng((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(0, 100);
    for (int &x : rnd) x = dist(rng);

    cout << "Random array:\n";
    printVector(rnd);
    quickSort(rnd);
    cout << "Sorted random array:\n";
    printVector(rnd);

    return 0;
}
