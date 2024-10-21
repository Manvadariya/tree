#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &a, vector<int>&b, vector<int>& v){
    int i = 0, j = 0, k = 0;
    while(i<a.size() && j<b.size()){
        if(a[i] < b[j]){
            v[k] = a[i];
            i++;
        }
        else{
            v[k] = b[j];
            j++;
        }
        k++;
    }
    while(i<a.size()){
        v[k] = a[i];
        i++;
        k++;
    }
    while(j<b.size()){
        v[k] = b[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& v){
    int n = v.size();
    if(n==1) return;
    int n1 = n/2;
    int n2 = n - n/2;
    vector<int> a(n1),b(n2);
    for(int i=0; i<n1; i++)
        a[i] = v[i];
    for(int i=0; i<n2; i++)
        b[i] = v[n1+i];
    
    mergeSort(a);
    mergeSort(b);

    merge(a,b,v);
}

int main(){
    vector<int> v = {5, 4, 3, 2, 1};
    mergeSort(v);
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}