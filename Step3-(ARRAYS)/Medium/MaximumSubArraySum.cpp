// Kadane's Algorithm : Maximum Subarray Sum in an Array

// Problem Statement: Given an integer array arr, find the contiguous subarray (containing at least one number) which
// has the largest sum and returns its sum and prints the subarray.

// Examples -> 

// Example 1:
// Input: arr = [-2,1,-3,4,-1,2,1,-5,4] 
// Output: 6 
// Explanation: [4,-1,2,1] has the largest sum = 6. 

// Examples 2: 
// Input: arr = [1] 
// Output: 1 
// Explanation: Array has only one element and which is giving positive sum of 1. 


// | Method         | Approach                       | Time Complexity | Space Complexity |
// | -------------- | ------------------------------ | --------------- | ---------------- |
// | `subarraySum1` | Brute Force (3 loops)          | **O(N³)**       | **O(1)**         |
// | `subarraySum2` | Improved Brute Force (2 loops) | **O(N²)**       | **O(1)**         |
// | `subarraySum3` | Kadane’s Algorithm             | **O(N)**        | **O(1)**         |

#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    int subarraySum1(vector<int>& arr, int n){
        int ans = INT_MIN;
        int sum = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                sum = 0;
                for(int k=i;k<=j;k++)
                sum+=arr[k];
                ans = max(ans, sum);
            }
        }
        return ans;
    }
    int subarraySum2(vector<int>& arr, int n){
        int ans = INT_MIN;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum = 0;
            for(int j=i;j<n;j++){
                sum+=arr[j];
                ans = max(ans, sum);
            }
        }
        return ans;
    }
    int subarraySum3(vector<int>& arr, int n){
        //Kadane's Algorithm
        int ans = INT_MIN;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            ans = max(ans, sum);
            if(sum<0)sum = 0;
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

    int a = obj->subarraySum1(arr, n);
    cout<<"Maximum Subarray sum is: "<<a<<endl;

    int b = obj->subarraySum2(arr, n);
    cout<<"Maximum Subarray sum is: "<<b<<endl;

    int c = obj->subarraySum3(arr, n);
    cout<<"Maximum Subarray sum is: "<<c<<endl;

    delete obj;
    return 0;
}