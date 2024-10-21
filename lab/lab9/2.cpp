#include <iostream>
#include <vector>

using namespace std;

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << "  ";
    }
    cout << endl;
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
        printArray(arr);
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    printArray(arr);
    insertionSort(arr);
    return 0;
}