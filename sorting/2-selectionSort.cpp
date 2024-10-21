#include <bits/stdc++.h>

using namespace std;

void selectionSort(vector<int> &v){
    int n = v.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndx = i;
        for(int j=i+1; j<n; j++){
            if(v[minIndx]>v[j]) minIndx = j;
        }
        swap(v[minIndx], v[i]);
    }
}

int main(){
    vector<int> v = {5, 4, 3, 2, 1};
    selectionSort(v);
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
