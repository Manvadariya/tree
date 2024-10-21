#include <bits/stdc++.h>

using namespace std;

void quickSort(vector<int>& v, int start, int end) {
    if (start >= end) return;
    int pivot = v[start];
    int countSmall = 0;
    for (int i = start + 1; i <= end; i++) {
        if (v[i] < pivot) countSmall++;
    }
    swap(v[start], v[start + countSmall]);
    int pivotIndex = start + countSmall;
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        if (v[i] < pivot) i++;
        else if (v[j] >= pivot) j--;
        else swap(v[i], v[j]);
    }
    quickSort(v, start, pivotIndex - 1);
    quickSort(v, pivotIndex + 1, end);
}

int main() {
    vector<int> v = {5, 4, 3, 2, 1};
    quickSort(v, 0, v.size() - 1);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}