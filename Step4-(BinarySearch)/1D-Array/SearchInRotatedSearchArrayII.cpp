// Search Element in Rotated Sorted Array II

// Problem Statement: Given an integer array arr of size N, sorted in ascending order (may contain duplicate values) and a target value k. Now the array is rotated at some pivot point unknown to you. Return True if k is present and otherwise, return False. 

// Pre-requisite: Search Element in Rotated Sorted Array I & Binary Search algorithm

// Examples

// Example 1:
// Input Format: arr = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 3
// Result: True
// Explanation: The element 3 is present in the array. So, the answer is True.

// Example 2:
// Input Format: arr = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 10
// Result: False
// Explanation: The element 10 is not present in the array. So, the answer is False.

// | **Case**         | **Time Complexity** | **Reason**                                                                                                           | **Space Complexity** | **Reason**                                       |
// | ---------------- | ------------------- | -------------------------------------------------------------------------------------------------------------------- | -------------------- | ------------------------------------------------ |
// | **Best Case**    | **O(1)**            | Target found at the first `mid` check.                                                                               | **O(1)**             | Only constant extra variables (`s`, `e`, `mid`). |
// | **Average Case** | **O(log N)**        | Works like binary search when there are few duplicates.                                                              | **O(1)**             | No extra data structures used.                   |
// | **Worst Case**   | **O(N/2)** ~ O(N)   | When many duplicates exist (e.g., `[1,1,1,1,1]`), the duplicate skip (`s++`, `e--`) can degenerate to linear search. | **O(1)**             | Still constant auxiliary space.                  |


#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    bool searchInRotatedArrayII(vector<int>& arr, int target, int n){
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;
        while(s<=e){
            if(arr[mid] == target)return true;
            if(arr[s] == arr[mid] && arr[mid] == arr[e]){
                s++;
                e--;
                continue;
            }
            if(arr[mid]>=arr[s]){
                if(arr[s]<=target && arr[mid]>=target)e = mid - 1;
                else s = mid + 1;
            }else{
                if(arr[mid]<target && arr[e]>=target)s = mid + 1;
                else e = mid - 1;
            }
            mid = s + (e-s)/2;
        }
        return false;
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

    int a = obj->searchInRotatedArrayII(arr, target, n);
    if(a == 0)cout<<"false"<<endl;
    else cout<<"true"<<endl;

    delete obj;
    return 0;
}