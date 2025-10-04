// Last occurrence in a sorted array

// Given a sorted array of N integers, write a program to find the index of the last occurrence of the target key. If the target is not found then return -1.

// Examples:

// Example 1:
// Input: N = 7, target=13, array[] = {3,4,13,13,13,20,40}
// Output: 4
// Explanation: As the target value is 13 , it appears for the first time at index number 2.

// Example 2:
// Input: N = 7, target=60, array[] = {3,4,13,13,13,20,40}
// Output: -1
// Explanation: Target value 60 is not present in the array 
// Disclaimer: Don't jump directly to the solution, try it out yourself first.



#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    int lastOccurance(vector<int>& arr, int target, int n){
        int ans = -1;
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;
        while(s<=e){
            if(arr[mid]==target){
                ans = mid;
                s = mid+1;
            }if(arr[mid] > target){
                e = mid-1;
            }else{
                s = mid+1;
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

    int a = obj->lastOccurance(arr, target, n);
    cout<<"Last Occurance of element is : "<<a<<endl;

    delete obj;
    return 0;
}