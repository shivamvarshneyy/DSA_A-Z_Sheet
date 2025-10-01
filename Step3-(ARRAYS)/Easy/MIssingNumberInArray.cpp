// Problem Statement: Given an integer N and an array of size N-1 containing N-1 numbers between 1 to N. Find the number(between 1 to N), that is not present in the given array.

// Examples

// Example 1:
// Input Format: N = 5, array[] = {1,2,4,5}
// Result: 3
// Explanation: In the given array, number 3 is missing. So, 3 is the answer.

// Example 2:
// Input Format: N = 3, array[] = {1,3}
// Result: 2
// Explanation: In the given array, number 2 is missing. So, 2 is the answer.

// | Method             | Time Complexity | Space Complexity | Works if Array is Sorted?   | Works if Array is Unsorted?  | Overflow Risk?                                         | Notes                                                                                |
// | ------------------ | --------------- | ---------------- | -------------------------   | ---------------------------  | -----------------------------------------------------  | ------------------------------------------------------------------------------------ |
// | **missingNumber1** | O(n)            | O(1)             | ✅ Yes                     | ❌ No                        | No                                                     | Works only if input array is sorted ascending.                                       |
// | **missingNumber2** | O(n)            | O(1)             | ✅ Yes                     | ✅ Yes                       | ⚠️ Yes (if `n*(n+1)/2` exceeds int) → use `long long` | Classic sum method. Your fix with `long long` is correct.                             |
// | **missingNumber3** | O(n)            | O(1)             | ✅ Yes                     | ✅ Yes                       | ✅ No                                                 | XOR method → avoids overflow. Very efficient.                                         |
// | **missingNumber4** | O(n)            | O(n)             | ✅ Yes                     | ✅ Yes                       | No                                                     | Uses frequency array (hashing). Simple and intuitive, but requires O(n) extra space. |


#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    int missingNumber1(vector<int> arr, int n){
        //if array is sorted then only this method works;
        int ans = -1;
        for(int i=0;i<n-1;i++){
            if(arr[i]!=i+1)return i+1;
        }
        if(ans==-1)return n;
        return ans;
    }

    int missingNumber2(vector<int> arr, int n){
        long long ans = 0;
        for(const int& i:arr)ans+=i;
        ans = (n*(n+1)/2LL) - ans;
        return (int)ans;
    }

    int missingNumber3(vector<int> arr, int n){
        int ans = 0;
        for(int i=0;i<n-1;i++){
            ans^=i+1;
            ans^=arr[i];
        }
        ans^=n;
        return ans;
    }
    int missingNumber4(vector<int> arr, int n){
        int ans = 0;
        vector<int> mp(n+1);
        for(const int& i:arr)mp[i]++;
        for(int i=1;i<=n;i++){
            if(mp[i]==0)return i;
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

    vector<int> arr(n-1);
    cout << "Enter array elements without missing number:" << endl;
    for (int i = 0; i < n-1; i++) cin >> arr[i];

    int k = obj->missingNumber1(arr, n);
    cout<<"Missing Number is: "<<k<<endl;

    int l = obj->missingNumber2(arr, n);
    cout<<"Missing Number is: "<<l<<endl;

    int m = obj->missingNumber3(arr, n);
    cout<<"Missing Number is: "<<m<<endl;

    int o = obj->missingNumber4(arr, n);
    cout<<"Missing Number is: "<<o<<endl;

    delete obj;
    return 0;
}