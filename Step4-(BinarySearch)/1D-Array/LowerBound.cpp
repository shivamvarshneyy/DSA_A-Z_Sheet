// Implement Lower Bound

// Problem Statement: Given a sorted array of N integers and an integer x, write a program to find the lower bound of x.

// Examples

// Example 1:
// Input Format: N = 4, arr[] = {1,2,2,3}, x = 2
// Result: 1
// Explanation: Index 1 is the smallest index such that arr[1] >= x.

// Example 2:
// Input Format: N = 5, arr[] = {3,5,8,15,19}, x = 9
// Result: 3
// Explanation: Index 3 is the smallest index such that arr[3] >= x.
 
/************************************************************************************************************************************************************************** */
// | **Method**                 | **What it Returns**                | **Time Complexity** | **Space Complexity** | **Notes**                                                |
// | -------------------------- | ---------------------------------- | ------------------- | -------------------- | -------------------------------------------------------- |
// | **Brute Force**            | Index of first element `>= target` | O(N)                | O(1)                 | Simple but slow for large N                              |
// | **Binary Search (Manual)** | Index of first element `>= target` | O(log N)            | O(1)                 | Efficient and correct                                    |
// | **STL `lower_bound`**      | Index of first element `>= target` | O(log N)            | O(1)                 | Short and neat, returns iterator → must convert to index |
/*************************************************************************************************************************************************************************** */ 


#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    int lowerBound1(vector<int>& arr, int target, int n){
        int ans = n;
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;
        while(s<=e){
            if(arr[mid] >= target){
                ans = mid;
                e = mid-1;
            }else{
                s = mid+1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
    int lowerBound2(vector<int>& arr, int target, int n){
        return lower_bound(arr.begin(), arr.end(), target) - arr.begin();
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

    int a = obj->lowerBound1(arr, target, n);
    cout<<"Lower Bound of array is : "<<a<<endl;

    int b = obj->lowerBound2(arr, target, n);
    cout<<"Lower Bound of array is : "<<b<<endl;

    delete obj;
    return 0;
}