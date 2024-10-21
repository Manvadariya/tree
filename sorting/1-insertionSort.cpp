#include <bits/stdc++.h>

using namespace std;

void insertionSort(vector<int> &v){
    int n = v.size();
    for(int i=1; i<n; i++){
        int current = v[i];
        int j = i-1;
        while(j>=0 && v[j]>current){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = current;
    }
}

int main(){
    vector<int> v = {5, 4, 3, 2, 1};
    insertionSort(v);
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}