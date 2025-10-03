// Length of the longest subarray with zero Sum

// Problem Statement: Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.

// Examples

// Example 1:
// Input Format: N = 6, array[] = {9, -3, 3, -1, 6, -5}
// Result: 5
// Explanation: The following subarrays sum to zero:
// {-3, 3} , {-1, 6, -5}, {-3, 3, -1, 6, -5}
// Since we require the length of the longest subarray, our answer is 5!

// Example 2:
// Input Format: N = 8, array[] = {6, -2, 2, -8, 1, 7, 4, -10}
// Result: 8
// Subarrays with sum 0 : {-2, 2}, {-8, 1, 7}, {-2, 2, -8, 1, 7}, {6, -2, 2, -8, 1, 7, 4, -10}
// Length of longest subarray = 8

// Example 3:
// Input Format: N = 3, array[] = {1, 0, -5}
// Result: 1
// Subarray : {0}
// Length of longest subarray = 1

// Example 4:
// Input Format: N = 5, array[] = {1, 3, -5, 6, -2}
// Result: 0
// Subarray: There is no subarray that sums to zero

// | Method                     | Approach                               | Time Complexity | Space Complexity | Explanation                                                                                                                                |
// | -------------------------- | -------------------------------------- | --------------- | ---------------- | ------------------------------------------------------------------------------------------------------------------------------------------ |
// | `lengthOfLongestSubarray1` | **Brute Force (3 loops)**              | **O(N³)**       | O(1)             | Uses 3 loops → pick every subarray `(i…j)`, compute sum with a 3rd loop. Very slow for large N.                                            |
// | `lengthOfLongestSubarray2` | **Better Brute Force (2 loops)**       | **O(N²)**       | O(1)             | Removes 3rd loop by keeping a running sum while extending subarray `(i…j)`. Still quadratic but better.                                    |
// | `lengthOfLongestSubarray3` | **Optimal using Prefix Sum + HashMap** | **O(N)**        | **O(N)**         | Uses prefix sum + map to store first occurrence of each sum. If sum repeats, the subarray between indices has 0 sum. Fastest and scalable. |



#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    int lengthOfLongestSubarray1(vector<int>& arr, int n){
        int ans = 0;
        long long int sum = 0;
        for(int i=0;i<n-1;i++){
            for(int j=i;j<n;j++){
                sum=0;
                for(int k=i;k<=j;k++){
                    sum+=arr[k];
                }
                if(sum==0)ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
    int lengthOfLongestSubarray2(vector<int>& arr, int n){
        int ans = 0;
        long long int sum = 0;
        for(int i=0;i<n-1;i++){
            sum=0;
            for(int j=i;j<n;j++){
                sum+=arr[j];
                if(sum==0)ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
    int lengthOfLongestSubarray3(vector<int>& arr, int n){
        int ans = 0;
        long long int sum = 0;
        unordered_map<long long int, int> mp;
        for(int i=0;i<n;i++){
            sum += arr[i];
            if(sum==0)ans = i+1;
            if(mp.find(sum) != mp.end()){
                ans = max(ans, i - mp[sum]);
            }else{
                mp[sum] = i;
            }
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

    int a = obj->lengthOfLongestSubarray1(arr, n);
    cout<<" Length Of Longest Subarray : "<< a << endl;

    int b = obj->lengthOfLongestSubarray2(arr, n);
    cout<<" Length Of Longest Subarray : "<< b << endl;

    int c = obj->lengthOfLongestSubarray3(arr, n);
    cout<<" Length Of Longest Subarray : "<< c << endl;

    delete obj;
    return 0;
}