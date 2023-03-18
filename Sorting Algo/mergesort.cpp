/*
 There are major two function 1.MergeSort() & 2. Merge
 1.MergeSort() Divides the array into two halfs or simply divides until single elenets remain in list
 2. Merge() It merges the two parts of arrays accordingly
*/

#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low,int mid, int high){
   vector<int>temp;    //Temparary array to sort the elements
    
   int left = low;
   int right = mid+1;

   while(left <= mid && right <= high){
      if(arr[left] <= arr[right]){
        temp.push_back(arr[left]);
        left++;
      }
      else {
        temp.push_back(arr[right]);
        right++;
      }
    
   } 
   while(left <= mid){
    temp.push_back(arr[left]);
    left++;
   }
   while(right <= high){
    temp.push_back(arr[right]);
   right++;

   }
   for(int i=low;i <= high ; i++){
    arr[i] = temp[i - low]; 
       }


}

void MergeSort(vector<int>& arr, int low, int high){
    
    if(low >= high) return ;

    int mid = (low+high)/2;

    MergeSort(arr,low,mid);
    MergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);

}

int main(void){
    // vector<int> v = {4, 3, 2, 1};
    vector<int> v = {4, 3, 2, 1, 4, 7, 5, 6};
    int n = v.size();
    MergeSort(v, 0, n-1);

    for(auto it : v) cout << it << " ";
    return 0;
}
