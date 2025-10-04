// Count inversions in an array

// Problem Statement: Given an array of N integers, count the inversion of the array.

// What is an inversion of an array? Definition: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].

// Examples

// Example 1:
// Input Format: N = 5, array[] = {1,2,3,4,5}
// Result: 0
// Explanation: we have a sorted array and the sorted array has 0 inversions as for i < j you will never find a pair such that A[j] < A[i]. More clear example: 2 has index 1 and 5 has index 4 now 1 < 5 but 2 < 5 so this is not an inversion.

// Example 2:
// Input Format: N = 5, array[] = {5,4,3,2,1}
// Result: 10
// Explanation: we have a reverse sorted array and we will get the maximum inversions as for i < j we will always find a pair such that A[j] < A[i]. Example: 5 has index 0 and 3 has index 2 now (5,3) pair is inversion as 0 < 2 and 5 > 3 which will satisfy out conditions and for reverse sorted array we will get maximum inversions and that is (n)*(n-1) / 2.For above given array there is 4 + 3 + 2 + 1 = 10 inversions.

// Example 3:
// Input Format: N = 5, array[] = {5,3,2,1,4}
// Result: 7
// Explanation: There are 7 pairs (5,1), (5,3), (5,2), (5,4),(3,2), (3,1), (2,1) and we have left 2 pairs (2,4) and (1,4) as both are not satisfy our condition. 

#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    int countInversion1(vector<int>& arr, int n){
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]>arr[j])count++;
            }
        }
        return count;
    }
    int merge(vector<int>& arr, int low, int mid, int high){
        vector<int> temp;
        int count = 0;
        int i = low;
        int j = mid+1;
        while(i<=mid && j<=high){
            if(arr[i]<=arr[j]){
                temp.emplace_back(arr[i++]);
            }else{
                temp.emplace_back(arr[j++]);
                count += (mid-i+1);
            }
        }
        while(i<=mid){
            temp.emplace_back(arr[i++]);
        }
        while(j<=high){
            temp.emplace_back(arr[j++]);
        }
        for(i=low;i<=high;i++){
            arr[i] = temp[i-low];
        }
        return count;
    }
    int mergeSort(vector<int>& arr, int low, int high){
        int count = 0;
        if(low >= high)return count;
        int mid = low + (high - low)/2;
        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid+1, high);
        count += merge(arr, low, mid, high);
        return count;
    }
    int countInversion2(vector<int>& arr, int n){
        int count = mergeSort(arr, 0, n-1);
        return count;
    }
};

int main() {
    MySolution* obj = new MySolution;

    int n;
    cout << "Enter array size:" << endl;
    
    while (true) {
        cin >> n;
        if (n > 0) break;
        cout << "Invalid size. Re-enter array size: ";
    }

    vector<int> arr(n);
    cout << "Enter array elements:" << endl;
    for (int i = 0; i < n; i++) cin >> arr[i];

    int a = obj->countInversion1(arr, n);
    cout<<"Count of Inversions in array are: "<<a<<endl;

    int b = obj->countInversion2(arr, n);
    cout<<"Count of Inversions in array are: "<<b<<endl;

    delete obj;
    return 0;
}