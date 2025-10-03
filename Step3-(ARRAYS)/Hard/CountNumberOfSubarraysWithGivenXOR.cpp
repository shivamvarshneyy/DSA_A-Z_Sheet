// Count the number of subarrays with given xor K

// Problem Statement: Given an array of integers A and an integer B. Find the total number of subarrays having bitwise XOR of all elements equal to k.


// Examples

// Example 1:
// Input Format: A = [4, 2, 2, 6, 4] , k = 6
// Result: 4
// Explanation: The subarrays having XOR of their elements as 6 are  [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]

// Example 2:
// Input Format: A = [5, 6, 7, 8, 9], k = 5
// Result: 2
// Explanation: The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]

// | Method                         | Approach                               | Time Complexity | Space Complexity | Explanation                                                                                                           |
// | ------------------------------ | -------------------------------------- | --------------- | ---------------- | --------------------------------------------------------------------------------------------------------------------- |
// | `countOfSubarrayWithGivenXOR1` | **Brute Force (3 loops)**              | **O(N³)**       | O(1)             | Check every subarray `(i…j)` with inner loop computing XOR. Very slow.                                                |
// | `countOfSubarrayWithGivenXOR2` | **Better Brute Force (2 loops)**       | **O(N²)**       | O(1)             | Removes 3rd loop by keeping running XOR while extending subarray `(i…j)`. Faster but still quadratic.                 |
// | `countOfSubarrayWithGivenXOR3` | **Optimal using Prefix XOR + HashMap** | **O(N)**        | **O(N)**         | Uses property: if `xr ^ k = prefix`, then such subarray exists. Stores prefix XOR counts in hash map. Most efficient. |


#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    int countOfSubarrayWithGivenXOR1(vector<int>& arr, int target, int n){
        int ans = 0;
        long long int xr = 0;
        for(int i=0;i<n-1;i++){
            for(int j=i;j<n;j++){
                xr=0;
                for(int k=i;k<=j;k++){
                    xr^=arr[k];
                }
                if(xr==target)ans++;
            }
        }
        return ans;
    }
    int countOfSubarrayWithGivenXOR2(vector<int>& arr, int target, int n){
        int ans = 0;
        long long int xr = 0;
        for(int i=0;i<n-1;i++){
            xr=0;
            for(int j=i;j<n;j++){
                xr^=arr[j];
                if(xr==target)ans++;
            }
        }
        return ans;
    }
    int countOfSubarrayWithGivenXOR3(vector<int>& arr, int target, int n){
        int ans = 0;
        long long int xr = 0;
        unordered_map<long long int, int> mp;
        mp[0]++;
        for(int i=0;i<n;i++){
            xr ^= arr[i];
            ans += mp[xr^target];
            mp[xr]++;    
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

    cout << "Enter target XOR:" << endl;
    int target;
    cin>>target;

    int a = obj->countOfSubarrayWithGivenXOR1(arr, target, n);
    cout<<" Number of subarrays with given xor K : "<< a << endl;

    int b = obj->countOfSubarrayWithGivenXOR2(arr, target, n);
    cout<<" Number of subarrays with given xor K : "<< b << endl;

    int c = obj->countOfSubarrayWithGivenXOR3(arr, target, n);
    cout<<" Number of subarrays with given xor K: "<< c << endl;

    delete obj;
    return 0;
}