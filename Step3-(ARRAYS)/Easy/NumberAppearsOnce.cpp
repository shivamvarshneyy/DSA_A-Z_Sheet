// Find the number that appears once, and the other numbers twice

// Problem Statement: Given a non-empty array of integers arr, every element appears twice except for one. Find that single one.

// Examples

// Example 1:
// Input Format: arr[] = {2,2,1}
// Result: 1
// Explanation: In this array, only the element 1 appear once and so it is the answer.

// Example 2:
// Input Format: arr[] = {4,1,2,1,2}
// Result: 4
// Explanation: In this array, only element 4 appear once and the other elements appear twice. So, 4 is the answer.

// | Method        | Time Complexity | Space Complexity | Works for unsorted array?   | Notes                                                                             |
// | ------------- | --------------- | ---------------- | --------------------------  | --------------------------------------------------------------------------------- |
// | `appearOnce1` | O(n)            | O(1)             | ✅ Yes                      | Uses XOR. All numbers appearing twice cancel each other. Most efficient method.   |
// | `appearOnce2` | O(n)            | O(n)             | ✅ Yes                      | Uses `unordered_map` to count occurrences. Works for any array. Extra space used. |
// | `appearOnce3` | O(n + k)        | O(k)             | ❌ Only if all elements ≤ n | Uses a frequency array. Not safe if array elements are large or negative.         |



#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    int appearOnce1(vector<int>& arr, int n){
        int xr = 0;
        for(const int& i: arr)xr^=i;
        return xr;
    }
    int appearOnce2(vector<int>& arr, int n){
        unordered_map<int,int> mp;
        for(const int& i: arr)mp[i]++;
        for(const auto& i:mp){
            if(i.second==1)return i.first;
        }
    }
    int appearOnce3(vector<int>& arr, int n){
        vector<int> nums(n+1);
        for(const int& i: arr)nums[i]++;
        for(int i=0;i<=n;i++){
            if(nums[i]==1)return i;
        }
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

    int a = obj->appearOnce1(arr,n);
    cout<<"Number that appears once: "<<a<<endl;

    int b = obj->appearOnce2(arr,n);
    cout<<"Number that appears once: "<<b<<endl;

    int c = obj->appearOnce3(arr,n);
    cout<<"Number that appears once: "<<c<<endl;

    delete obj;
    return 0;
}