#include <bits/stdc++.h>
using namespace std;

void quick_sort(int arr[], int n){
    if(n<=1){
        return;
    }
    int pivot = arr[n/2];
    int i=0, j=n-1;
    while(i<=j){
        while(arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<=j){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    quick_sort(arr, j+1);
    quick_sort(arr+i, n-i);
}


int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    quick_sort(arr, n);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}