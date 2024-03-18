#include<bits/stdc++.h>
using namespace std;

int pivot(vector<int> &arr, int l, int r){
    int i = l;
    int p = arr[r];
    for(int j=l; j<r; j++){
        if (arr[j] <= p){
            swap(arr[i], arr[j]);
            i++;
        }
    }swap(arr[r], arr[i]);
    return i;
}

void quickSort(vector<int> &arr, int l, int r){
    if (l>=r) return;
    int i = pivot(arr, l, r);
    quickSort(arr, l, i-1);
    quickSort(arr, i+1, r);
}

int main(){
    int n; cout<<"Enter number of elements: "; cin>>n;
    vector<int> arr(n);
    cout<<"Enter array elements: ";
    for(int i=0; i<n; i++) cin>>arr[i];
    // sort(arr.begin(), arr.end());
    quickSort(arr, 0, arr.size()-1);
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
}

/*
5
5 2 10 5 6
*/