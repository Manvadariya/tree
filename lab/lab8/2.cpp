#include <bits/stdc++.h>
using namespace std;

int BinarySearch(const vector<int>& arr, int key) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) return mid + 1;
        else if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    int n, m;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> m;
    vector<int> searchList(m);
    for (int i = 0; i < m; i++) cin >> searchList[i];
    for (int i = 0; i < m; i++) cout << BinarySearch(arr, searchList[i]) << " ";
    return 0;
}