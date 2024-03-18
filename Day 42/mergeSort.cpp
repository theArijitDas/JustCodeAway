#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int l, int m, int r){
    int i=l, j=m+1;
    vector<int> temp;
    while((i<=m) && (j<=r)){
        if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }
    while(i <= m) temp.push_back(arr[i++]);
    while(j <= r) temp.push_back(arr[j++]);

    for(int i=0; i<temp.size(); i++){
        arr[l+i] = temp[i];
    }

}

void mergeSort(vector<int> &arr, int l, int r){
    if (l >= r) return;
    int m = l + (r-l)/2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    merge(arr, l, m, r);
    return;
}

int main(){
    int n; cout<<"Enter number of elements: "; cin>>n;
    vector<int> arr(n);
    cout<<"Enter array elements: ";
    for(int i=0; i<n; i++) cin>>arr[i];
    // sort(arr.begin(), arr.end());
    mergeSort(arr, 0, arr.size()-1);
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
}

/*
5
5 2 10 5 6
*/