// Search Insert Position

// Problem Statement: You are given a sorted array arr of distinct values and a target value x. You need to search for the index of the target value in the array.

// If the value is present in the array, then return its index. Otherwise, determine the index where it would be inserted in the array while maintaining the sorted order.

// Example 1:
// Input Format: arr[] = {1,2,4,7}, x = 6
// Result: 3
// Explanation: 6 is not present in the array. So, if we will insert 6 in the 3rd index(0-based indexing), the array will still be sorted. {1,2,4,6,7}.

// Example 2:
// Input Format: arr[] = {1,2,4,7}, x = 2
// Result: 1
// Explanation: 2 is present in the array and so we will return its index i.e. 1.

#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    int lowerBound1(vector<int>& arr, int target, int n){
        int ans = n;
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;
        while(s<=e){
            if(arr[mid] >= target){
                ans = mid;
                e = mid-1;
            }else{
                s = mid+1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
    int lowerBound2(vector<int>& arr, int target, int n){
        return lower_bound(arr.begin(), arr.end(), target) - arr.begin();
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

    cout << "Enter target elements:" << endl;
    int target;
    cin >> target;

    int a = obj->lowerBound1(arr, target, n);
    cout<<"Insert Position in array is : "<<a<<endl;

    int b = obj->lowerBound2(arr, target, n);
    cout<<"Insert Position in array is : "<<b<<endl;

    delete obj;
    return 0;
}