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

// | Method           | Time | Space | Works for unsorted?  | Overflow risk?           |
// | ---------------- | ---- | ----- | -------------------  | ----------------------   |
// | `missingNumber1` | O(n) | O(1)  | ❌ No (needs sorted) | No                       |
// | `missingNumber2` | O(n) | O(1)  | ✅ Yes               | ⚠️ Yes (use `long long`) |
// | `missingNumber3` | O(n) | O(1)  | ✅ Yes               | ✅ No                    |


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

    delete obj;
    return 0;
}