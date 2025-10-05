// Minimum in Rotated Sorted Array

// Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated between 1 to N times which is unknown. Find the minimum element in the array. 

// Pre-requisites: Search in Rotated Sorted Array I,  Search in Rotated Sorted Array II & Binary Search algorithm

// Examples

// Example 1:
// Input Format: arr = [4,5,6,7,0,1,2,3]
// Result: 0
// Explanation: Here, the element 0 is the minimum element in the array.

// Example 2:
// Input Format: arr = [3,4,5,1,2]
// Result: 1
// Explanation: Here, the element 1 is the minimum element in the array.


// | **Case**         | **Time Complexity** | **Reason**                                                                            | **Space Complexity** | **Reason**                                    |
// | ---------------- | ------------------- | ------------------------------------------------------------------------------------- | -------------------- | --------------------------------------------- |
// | **Best Case**    | O(1)                | Array segment `[s,e]` is already sorted (`arr[s] <= arr[e]`) → we break immediately.  | O(1)                 | Only constant variables (`s,e,mid,ans`) used. |
// | **Average Case** | O(log N)            | Binary search divides the array in half each iteration until minimum is found.        | O(1)                 | No extra data structures used.                |
// | **Worst Case**   | O(log N)            | Array is rotated such that we always check both halves, but still halves reduce by 2. | O(1)                 | Constant space for pointers.                  |


#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    int minInRotatedArray(vector<int>& arr, int n){
        int ans = INT_MAX;
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;
        while(s<=e){
            if(arr[s] <= arr[e]){
                ans = arr[s];
                break;
            }else if(arr[s] <= arr[mid]){
                ans = min(ans, arr[s]);
                s = mid+1;
            }else{
                ans = min(ans, arr[mid]);
                e = mid-1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
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

    int a = obj->minInRotatedArray(arr, n);
    cout<<"Minimum In Rotated Array is : "<<a<<endl;

    delete obj;
    return 0;
}