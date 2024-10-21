#include <bits/stdc++.h>

using namespace std;

void shellSort(vector<int>& arr) {
    int n = arr.size();

    // Start with a big gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Do a gapped insertion sort for this gap size.
        for (int i = gap; i < n; i += 1) {
            // add arr[i] to the elements that have been gap sorted
            // save arr[i] in temp and make a hole at position i
            int temp = arr[i];

            // shift earlier gap-sorted elements up until the correct location for arr[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            // put temp (the original arr[i]) in its correct location
            arr[j] = temp;
        }
    }
}

void printArray(const vector<int>& arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {12, 34, 54, 2, 3};
    cout << "Array before sorting: ";
    printArray(arr);

    shellSort(arr);

    cout << "Array after sorting: ";
    printArray(arr);

    return 0;
}