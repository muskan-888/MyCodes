// Heap Sort implementation in C++ (in-place, max-heap)
//
// This file shows a clean, commented implementation of Heap Sort.
// Key points:
//  - Builds a max-heap from the array, then repeatedly extracts the max
//    to the end of the array producing a sorted (ascending) result.
//  - In-place algorithm with O(1) auxiliary space (beyond recursion/stack,
//    but this implementation is iterative so no recursion stack is used).
//  - Time complexity: O(n log n) worst/average/best (heapify build is O(n)).
//  - Stability: Not stable (swaps change relative order of equal elements).

#include <bits/stdc++.h>
using namespace std;

// Helper: sift-down operation to maintain max-heap property for node i
// in array `a` for heap size `n` (n is number of elements in heap).
// This implementation is iterative to avoid recursion overhead.
static void siftDown(vector<int>& a, int n, int i) {
    while (true) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && a[left] > a[largest]) largest = left;
        if (right < n && a[right] > a[largest]) largest = right;

        if (largest == i) break; // heap property satisfied
        swap(a[i], a[largest]);
        i = largest; // continue sifting down the swapped child
    }
}

// Build a max-heap from the array `a` in O(n) time by sifting down
// all non-leaf nodes starting from the last parent.
static void buildMaxHeap(vector<int>& a) {
    int n = (int)a.size();
    // last parent index = floor((n-2)/2)
    for (int i = (n - 2) / 2; i >= 0; --i) {
        siftDown(a, n, i);
    }
}

// In-place heap sort (ascending order)
void heapSort(vector<int>& a) {
    int n = (int)a.size();
    if (n <= 1) return;

    // 1) Build max-heap
    buildMaxHeap(a);

    // 2) Repeatedly extract the maximum (a[0]) to the end and
    //    restore the heap on the reduced range [0..i-1]
    for (int i = n - 1; i > 0; --i) {
        swap(a[0], a[i]);       // move current max to its final position
        siftDown(a, i, 0);      // restore heap for heap size i
    }
}

// Pretty-print a vector on one line
static void printVector(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) cout << ' ';
        cout << v[i];
    }
    cout << '\n';
}

int main() {
    vector<int> a = {12, 11, 13, 5, 6, 7};
    vector<int> empty;
    vector<int> single = {99};
    vector<int> sorted = {1, 2, 3, 4, 5};
    vector<int> reverse_sorted = {5, 4, 3, 2, 1};
    vector<int> duplicates = {4, 10, 4, 3, 10, 1};

    cout << "Original a:\n";
    printVector(a);
    heapSort(a);
    cout << "Sorted a:\n";
    printVector(a);

    cout << "Empty array (should print blank line):\n";
    heapSort(empty);
    printVector(empty);

    cout << "Single element (should be 99):\n";
    heapSort(single);
    printVector(single);

    cout << "Already sorted (should be 1 2 3 4 5):\n";
    heapSort(sorted);
    printVector(sorted);

    cout << "Reverse sorted (should be 1 2 3 4 5):\n";
    heapSort(reverse_sorted);
    printVector(reverse_sorted);

    cout << "Duplicates (should be sorted; note not stable):\n";
    heapSort(duplicates);
    printVector(duplicates);

    // Small random test
    vector<int> rnd(12);
    mt19937 rng((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(0, 50);
    for (int &x : rnd) x = dist(rng);

    cout << "Random array:\n";
    printVector(rnd);
    heapSort(rnd);
    cout << "Sorted random array:\n";
    printVector(rnd);

    return 0;
}
