// Find out how many times the array has been rotated

// Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated between 1 to N times which is unknown. Find how many times the array has been rotated. 

// Pre-requisites: Find minimum in Rotated Sorted Array,  Search in Rotated Sorted Array II & Binary Search algorithm

// Examples

// Example 1:
// Input Format: arr = [4,5,6,7,0,1,2,3]
// Result: 4
// Explanation: The original array should be [0,1,2,3,4,5,6,7]. So, we can notice that the array has been rotated 4 times.

// Example 2:
// Input Format: arr = [3,4,5,1,2]
// Result: 3
// Explanation: The original array should be [1,2,3,4,5]. So, we can notice that the array has been rotated 3 times.

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// | **Case**         | **Time Complexity** | **Reason**                                                                                         | **Space Complexity** | **Reason**                                        |
// | ---------------- | ------------------- | -------------------------------------------------------------------------------------------------- | -------------------- | ------------------------------------------------- |
// | **Best Case**    | O(1)                | If the subarray `[s,e]` is already sorted (`arr[s] <= arr[e]`), the rotation count is `s`.         | O(1)                 | Only constant variables (`s,e,mid,ans,res`) used. |
// | **Average Case** | O(log N)            | Binary search halves the array each iteration until the minimum element (rotation point) is found. | O(1)                 | No extra data structures used.                    |
// | **Worst Case**   | O(log N)            | Even with rotation, each iteration halves the search space, so still logarithmic.                  | O(1)                 | Constant space for pointers.                      |
// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    int countOfRotation(vector<int>& arr, int n){
        int s = 0;
        int e = n-1;
        int ans = INT_MAX;
        int res = -1;
        int mid = s + (e-s)/2;
        while(s<=e){
            if(arr[s]<=arr[e])return s;
            else if(arr[s]<=arr[mid]){
                if(ans>arr[s]){
                    ans = arr[s];
                    res = s;
                }
                s = mid + 1;
            }else{
                if(ans>arr[mid]){
                    ans = arr[mid];
                    res = mid;
                }
                e = mid - 1;
            }
            mid = s + (e-s)/2;
        }
        return res;
    }
    int countOfRotation2(vector<int>& arr, int n){
        int s = 0;
        int e = n-1;
        while(s <= e){
            if(arr[s] <= arr[e]) return s; // already sorted, minimum at start
            int mid = s + (e-s)/2;
            if(arr[s] <= arr[mid]){
                // left half sorted, so min is in right half
                s = mid + 1;
            } else {
                // right half unsorted, min is in left half including mid
                e = mid;
            }
        }
        return 0; // fallback, though we should have returned inside loop
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

    int a = obj->countOfRotation(arr, n);
    cout<<"The number of times array is rotated is : "<<a<<endl;

    delete obj;
    return 0;
}