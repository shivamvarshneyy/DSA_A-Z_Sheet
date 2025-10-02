// Count Subarray sum Equals K

// Problem Statement: Given an array of integers and an integer k, return the total number of subarrays whose sum equals k.

// A subarray is a contiguous non-empty sequence of elements within an array.

// Examples

// Example 1:
// Input Format: N = 4, array[] = {3, 1, 2, 4}, k = 6
// Result: 2
// Explanation: The subarrays that sum up to 6 are [3, 1, 2] and [2, 4].

// Example 2:
// Input Format: N = 3, array[] = {1,2,3}, k = 3
// Result: 2
// Explanation: The subarrays that sum up to 3 are [1, 2], and [3].


// | **Method**               | **Description**                                                                | **Time Complexity** | **Space Complexity** | **When to Use**                                 |
// | ------------------------ | ------------------------------------------------------------------------------ | ------------------- | -------------------- | ----------------------------------------------- |
// | `countSubArrayWithSumK1` | Brute force with 3 nested loops – check all possible subarrays and compute sum | (O(n^3))            | (O(1))               | Very small arrays (n ≤ 50) or just for learning |
// | `countSubArrayWithSumK2` | Better approach with 2 loops – maintain running sum in the inner loop          | (O(n^2))            | (O(1))               | Medium arrays (n ≤ 10^3), easier to implement   |
// | `countSubArrayWithSumK3` | Optimal approach using prefix sum + hashmap to store frequency of prefix sums  | (O(n))              | (O(n))               | Large arrays (n up to 10^5 or 10^6)             |


#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    int countSubArrayWithSumK1(vector<int>& arr, int target, int n){
        int count = 0;
        int sum = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                sum = 0;
                for(int k=i;k<=j;k++){
                    sum+=arr[k];
                }
                if(sum==target)count++;
            }
        }
        return count;
    }

    int countSubArrayWithSumK2(vector<int>& arr, int target, int n){
        int count = 0;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum = 0;
            for(int j=i;j<n;j++){
                sum+=arr[j];
                if(sum==target)count++;
            }
        }
        return count;
    }

    int countSubArrayWithSumK3(vector<int>& arr, int target, int n){
        int count = 0;
        int sum = 0;
        int rem = 0;
        unordered_map<int, int> mp;
        mp[0]++;
        for(int i=0;i<n;i++){
            sum += arr[i];
            rem = sum - target;
            count += mp[rem];
            mp[sum]++;
        }
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

    cout<<"Enter the sum you check count for : "<<endl;
    int k;
    cin>>k;

    int a = obj->countSubArrayWithSumK1(arr, k, n);
    cout<<"The number of subarrays with given sum "<<k<<" is : "<<a;
    cout<<endl;

    int b = obj->countSubArrayWithSumK2(arr, k, n);
    cout<<"The number of subarrays with given sum "<<k<<" is : "<<b;
    cout<<endl;

    int c = obj->countSubArrayWithSumK3(arr, k, n);
    cout<<"The number of subarrays with given sum "<<k<<" is : "<<c;
    cout<<endl;

    delete obj;
    return 0;
}