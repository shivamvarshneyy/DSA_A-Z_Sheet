// first occurrence in a sorted array

// Given a sorted array of N integers, write a program to find the index of the first occurrence of the target key. If the target is not found then return -1.

// Examples:

// Example 1:
// Input: N = 7, target=13, array[] = {3,4,13,13,13,20,40}
// Output: 2
// Explanation: As the target value is 13 , it appears for the first time at index number 2.

// Example 2:
// Input: N = 7, target=60, array[] = {3,4,13,13,13,20,40}
// Output: -1
// Explanation: Target value 60 is not present in the array 

/****************************************************************************************************************************************************************************************** */
// | **Method**                 | **What it Returns**                  | **Time Complexity** | **Space Complexity** | **Notes**                                                              |
// | -------------------------- | ---------------------------------- | ------------------ | ------------------- | -------------------------------------------------------------------------  |
// | **Brute Force**            | Index of first occurrence of target | O(N)               | O(1)                | Simple linear scan, returns -1 if target not found                        |
// | **Binary Search (Manual)** | Index of first occurrence of target | O(log N)           | O(1)                | Efficient for sorted arrays, updates answer when mid == target            |
/******************************************************************************************************************************************************************************************* */



#include <bits/stdc++.h>
#include "../../Header_File/FirstOccurrence.h"
using namespace std;

class MySolution {
public:
    int firstOccurance(vector<int>& arr, int target, int n){
        int ans = -1;
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;
        while(s<=e){
            if(arr[mid]==target){
                ans = mid;
                e = mid-1;
            }else if(arr[mid] > target){
                e = mid-1;
            }else{
                s = mid+1;
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

    cout << "Enter target elements:" << endl;
    int target;
    cin >> target;

    int a = obj->firstOccurance(arr, target, n);
    cout<<"first Occurance of element is : "<<a<<endl;

    int b = FirstOccurrence<int>::firstOccurrence(arr, target);
    cout<<"first Occurance of element is : "<<b<<endl;

    delete obj;
    return 0;
}