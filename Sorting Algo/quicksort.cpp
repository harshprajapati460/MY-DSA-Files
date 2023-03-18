#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i < j){
        while(arr[i] <= pivot && i <= high - 1) i++;

        while(arr[j] > pivot && j >= low + 1) j--;

        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void qs(vector<int>& arr, int low, int high){
    if(low < high){
        int pIndex = partition(arr, low, high);

        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}

int main(void){
    // vector<int> v = {4, 3, 2, 1};
    vector<int> v = {4, 3, 2, 1, 4, 7, 5, 6};
    int n = v.size();
    qs(v, 0, n-1);

    for(auto it : v) cout << it << " ";
    return 0;
}
