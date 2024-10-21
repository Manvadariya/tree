#include <bits/stdc++.h>

using namespace std;

int getMax(vector<int>& v) {
    int maxElement = v[0];
    for (int i = 1; i < v.size(); i++)
        if (v[i] > maxElement)
            maxElement = v[i];
    return maxElement;
}

void countSortByDigit(vector<int>& v, int exp) {
    int n = v.size();
    vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(v[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(v[i] / exp) % 10] - 1] = v[i];
        count[(v[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        v[i] = output[i];
}

void radixSort(vector<int>& v) {
    int maxElement = getMax(v);
    for (int exp = 1; maxElement / exp > 0; exp *= 10)
        countSortByDigit(v, exp);
}

int main() {
    vector<int> v = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(v);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}