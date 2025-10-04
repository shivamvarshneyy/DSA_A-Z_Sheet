// Search Element in a Rotated Sorted Array

// Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values) and a target value k. Now the array is rotated at some pivot point unknown to you. Find the index at which k is present and if k is not present return -1.

// Examples

// Example 1:
// Input Format: arr = [4,5,6,7,0,1,2,3], k = 0
// Result: 4
// Explanation: Here, the target is 0. We can see that 0 is present in the given rotated sorted array, nums. Thus, we get output as 4, which is the index at which 0 is present in the array.

// Example 2:
// Input Format: arr = [4,5,6,7,0,1,2], k = 3
// Result: -1
// Explanation: Here, the target is 3. Since 3 is not present in the given rotated sorted array. Thus, we get the output as -1.

// | Function Name          | Time Complexity | Space Complexity | Notes                                                                                                             |
// | ---------------------- | --------------- | ---------------- | ----------------------------------------------------------------------------------------------------------------- |
// | `searchInRotatedArray` | O(log N)        | O(1)             | Standard binary search on rotated sorted array; uses constant extra space and halves search space each iteration. |



#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    int searchInRotatedArray(vector<int>& arr, int target, int n){
        int ans = -1;
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;
        while(s<=e){
            if(arr[mid] == target)return mid;
            else if(arr[s]<=arr[mid]){
                if(target<=arr[mid] && target>=arr[s])e = mid-1;
                else s = mid+1;
            }else{
                if(target>=arr[mid] && target<=arr[e])s = mid+1;
                else e = mid-1;
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

    int a = obj->searchInRotatedArray(arr, target, n);
    if(a == -1)cout<<"Element is not present"<<endl;
    else cout<<"Position of element is : "<<a<<endl;

    delete obj;
    return 0;
}