// Maximum Product Subarray in an Array

// Problem Statement: Given an array that contains both negative and positive integers, find the maximum product subarray.

// Examples

// Example 1:
// Input: Nums = [1,2,3,4,5,0]
// Output: 120
// Explanation: In the given array, we can see 1×2×3×4×5 gives maximum product value.


// Example 2:
// Input:  Nums = [1,2,-3,0,-4,-5]
// Output: 20
// Explanation: In the given array, we can see (-4)×(-5) gives maximum product value.

#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    int maximumProductSubarray1(vector<int>& arr, int n){
        long long int ans = INT_MIN;
        long long int product = 1;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                product = 1;
                for(int k=i;k<=j;k++){
                    product *= arr[k];
                }
                ans = max(ans, product);
            }
        }
        return (int)ans;
    }
    int maximumProductSubarray2(vector<int>& arr, int n){
        long long int ans = INT_MIN;
        long long int product = 1;
        for(int i=0;i<n;i++){
            product = 1;
            for(int j=i;j<n;j++){
                product *= arr[j];
                ans = max(ans, product);
            }
        }
        return (int)ans;
    }
    int maximumProductSubarray3(vector<int>& arr, int n){
        long long int prefix = 1;
        long long int suffix = 1;
        long long int ans = INT_MIN;
        for(int i=0;i<n;i++){
            if(prefix==0)prefix=1;
            if(suffix==0)suffix=1;
            prefix *= arr[i];
            suffix *= arr[n-i-1];
            ans = max(ans, max(prefix, suffix));
        }
        return (int)ans;
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

    int a = obj->maximumProductSubarray1(arr, n);
    cout<<"Maximum Product Subarray is: "<<a<<endl;

    int b = obj->maximumProductSubarray2(arr, n);
    cout<<"Maximum Product Subarray is: "<<b<<endl;

    int c = obj->maximumProductSubarray3(arr, n);
    cout<<"Maximum Product Subarray is: "<<c<<endl;

    delete obj;
    return 0;
}