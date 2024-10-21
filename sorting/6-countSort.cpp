#include <bits/stdc++.h>

using namespace std;

void countSort(vector<int>& v){
    int n = v.size();
    int maxElement = v[0];
    for(int i=1; i<n; i++){
        maxElement = max(maxElement, v[i]);
    }
    vector<int> count(maxElement+1, 0);
    for(int i=0; i<n; i++){
        count[v[i]]++;
    }
    for(int i=1; i<=maxElement; i++){
        count[i] = count[i] + count[i-1]; 
    }
    vector<int> output(n,0);
    for(int i=n-1; i>=0; i--){
        output[count[v[i]]-1] = v[i];
        count[v[i]]--;
    }
    for(int i=0; i<n; i++){
        v[i] = output[i];
    }
}

int main(){
    vector<int> v = {5, 4, 3, 2, 1};
    countSort(v);
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}