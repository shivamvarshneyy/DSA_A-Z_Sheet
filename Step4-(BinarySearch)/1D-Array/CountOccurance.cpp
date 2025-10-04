// Count Occurrences in Sorted Array

// Problem Statement: You are given a sorted array containing N integers and a number X, you have to find the occurrences of X in the given array.

// Examples

// Example 1:
// Input: N = 7,  X = 3 , array[] = {2, 2 , 3 , 3 , 3 , 3 , 4}
// Output: 4
// Explanation: 3 is occurring 4 times in 
// the given array so it is our answer.

// Example 2:
// Input: N = 8,  X = 2 , array[] = {1, 1, 2, 2, 2, 2, 2, 3}
// Output: 5
// Explanation: 2 is occurring 5 times in the given array so it is our answer.


// | Method                       | What it Returns                   | Time Complexity | Space Complexity | Notes                                                                      |
// |----------------------------- |-----------------------------------|---------------- |----------------- |--------------------------------------------------------------------------- |
// | Binary Search (Manual)       | Count of occurrences of target    | O(log N)        | O(1)             | Finds first and last occurrence using binary search, then calculates count |


#include <bits/stdc++.h>
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
    int lastOccurance(vector<int>& arr, int target, int n){
        int ans = -1;
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;
        while(s<=e){
            if(arr[mid]==target){
                ans = mid;
                s = mid+1;
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
    int b = obj->lastOccurance(arr, target, n);
    if(a == -1) cout << "Occurrence of element is : 0" << endl;
    else cout << "Occurrence of element is : " << b - a + 1 << endl;

        delete obj;
    return 0;
}