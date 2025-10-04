// Floor and Ceil in Sorted Array

// Problem Statement: You're given an sorted array arr of n integers and an integer x. Find the floor and ceiling of x in arr[0..n-1].
// The floor of x is the largest element in the array which is smaller than or equal to x.
// The ceiling of x is the smallest element in the array greater than or equal to x.

// Example 1:
// Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 5
// Result: 4 7
// Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.

// Example 2:
// Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 8
// Result: 8 8
// Explanation: The floor of 8 in the array is 8, and the ceiling of 8 in the array is also 8.




#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    int findCeil(vector<int>& arr, int target, int n){
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
    int findFloor(vector<int>& arr, int target, int n){
        int ans = -1;
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;
        while(s<=e){
            if(arr[mid] <= target){
                ans = mid;
                s = mid+1;
            }else{
                e = mid-1;
            }
            mid = s + (e-s)/2;
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

    cout << "Enter target elements:" << endl;
    int target;
    cin >> target;

    int b = obj->findFloor(arr, target, n);
    if(b == -1) cout << "Floor does not exist" << endl;
    else cout << "Floor of array is : " << arr[b] << endl;

    int a = obj->findCeil(arr, target, n);
    if(a == n) cout << "Ceil does not exist" << endl;
    else cout << "Ceil of array is : " << arr[a] << endl;


    delete obj;
    return 0;
}

