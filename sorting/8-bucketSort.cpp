#include <bits/stdc++.h>
using namespace std;

void bucketSort(vector<float>& arr) {
    int n = arr.size();
    if (n <= 0) return;

    // Create n empty buckets
    vector<vector<float>> buckets(n);

    // Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i]; // Index in bucket
        buckets[bucketIndex].push_back(arr[i]);
    }

    // Sort individual buckets
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (size_t j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

// Function to print an array
void printArray(const vector<float>& arr) {
    for (float num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<float> arr = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};

    cout << "Original array: ";
    printArray(arr);

    bucketSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}