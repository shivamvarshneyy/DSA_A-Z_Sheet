// Longest Subarray with given Sum K(Positives)

// Problem Statement: Given an array and a sum k, we need to print the length of the longest subarray that sums to k.

// Examples

// Example 1:
// Input Format: N = 3, k = 5, array[] = {2,3,5}
// Result: 2
// Explanation: The longest subarray with sum 5 is {2, 3}. And its length is 2.

// Example 2:
// Input Format: N = 5, k = 10, array[] = {2,3,5,1,9}
// Result: 3
// Explanation: The longest subarray with sum 10 is {2, 3, 5}. And its length is 3.



// | Method                              | Time Complexity | Space Complexity | Handles Negatives?     | Notes                        |
// | ----------------------------------- | --------------- | ---------------- | ---------------------  | ---------------------------- |
// | `longestSubArray1` (Brute O(n³))    | O(n³)           | O(1)             | ✅ Yes                 | Very slow, only for learning |
// | `longestSubArray2` (Brute O(n²))    | O(n²)           | O(1)             | ✅ Yes                 | Better but still quadratic   |
// | `longestSubArray3` (Prefix + Map)   | O(n)            | O(n)             | ✅ Yes                 | Best for general case        |
// | `longestSubArray4` (Sliding Window) | O(n)            | O(1)             | ❌ No (only positives) | Best when arr > 0            |

#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    int longestSubArray1(vector<int>& arr, int k, int n){
        int ans = -1;
        int sum = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                sum = 0;
                for(int m=i;m<=j;m++){
                    sum+=arr[m];
                }
                if(sum==k)ans = max(ans, j-i+1);
            }
        }
        return ans;
    }

    int longestSubArray2(vector<int>& arr, int k, int n){
        int ans = -1;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum = 0;
            for(int j=i;j<n;j++){
                sum += arr[j];
                if(sum==k)ans = max(ans, j-i+1);
            }
        }
        return ans;
    }

    int longestSubArray3(vector<int>& arr, int k, int n){
        int ans = -1;
        int sum = 0;
        unordered_map<int, int> presum;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==k)ans=i+1;
            int rem = sum-k;
            if(presum.find(rem)!=presum.end()){
                ans = max(ans, i-presum[rem]);
            }else{
                presum[sum] = i;
            }
        }
        return ans;
    }

    int longestSubArray4(vector<int>& arr, int k, int n){
        int ans = -1;
        int sum = arr[0];
        int left = 0;
        int right = 0;
        while(right<n){
            while(left<=right && sum>k){
                sum -= arr[left];
                left++;
            }
            if(sum == k)ans=max(ans, right-left+1);
            right++;
            if(right<n)sum+=arr[right];
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

    int k;
    cout << "Enter sum to check: " << endl;
    cin>>k;


    int a = obj->longestSubArray1(arr, k, n);
    cout<<"Length of Longest SubArray with sum k is: "<<a<<endl;

    int b = obj->longestSubArray2(arr, k, n);
    cout<<"Length of Longest SubArray with sum k is: "<<b<<endl;

    int c = obj->longestSubArray3(arr, k, n);
    cout<<"Length of Longest SubArray with sum k is: "<<c<<endl;

    int d = obj->longestSubArray4(arr, k, n);
    cout<<"Length of Longest SubArray with sum k is: "<<d<<endl;


    delete obj;
    return 0;
}