// Kadane's Algorithm : Maximum Subarray Sum in an Array Extended Version

// Problem Statement: Given an integer array arr, find the contiguous subarray (containing at least one number) which
// has the largest sum and returns its sum and prints the subarray.

// Examples
// Example 1:
// Input: arr = [-2,1,-3,4,-1,2,1,-5,4] 
// Output: [4,-1,2,1]

// Examples 2: 
// Input: arr = [1] 
// Output: [1] 
// Explanation: Array has only one element and which is giving positive sum of 1. 


// | Approach / Function             | Time Complexity (Best) | Time Complexity (Average) | Time Complexity (Worst) | Space Complexity |
// | ------------------------------- | ---------------------- | ------------------------- | ----------------------- | ---------------- |
// | **maximumSubarray (your code)** | O(n)                   | O(n)                      | O(n)                    | O(1)             |


#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    pair<int, int> maximumSubarray(vector<int>& arr, int n){
        int s = 0;
        int e = 0;
        int sum = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(sum==0)s=i;
            sum += arr[i];
            if(sum>ans){
                ans = sum;
                e = i;
            }
            if(sum<0){
                sum = 0;
            }
        }
        return {s, e};
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

    pair<int, int> ans = obj->maximumSubarray(arr,n);
    cout<<"["<<ans.first<<", "<<ans.second<<"]";

    delete obj;
    return 0;
}