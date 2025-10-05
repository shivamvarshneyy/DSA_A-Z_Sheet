// Peak element in Array

// Problem Statement: Given an array of length N. Peak element is defined as the element greater than both of its neighbors. Formally, if 'arr[i]' is the peak element, 'arr[i - 1]' < 'arr[i]' and 'arr[i + 1]' < 'arr[i]'. Find the index(0-based) of a peak element in the array. If there are multiple peak numbers, return the index of any peak number.

// Note: For the first element, the previous element should be considered as negative infinity as well as for the last element, the next element should be considered as negative infinity.

// Examples

// Example 1:
// Input Format: arr[] = {1,2,3,4,5,6,7,8,5,1}
// Result: 7
// Explanation: In this example, there is only 1 peak that is at index 7.

// Example 2:
// Input Format: arr[] = {1,2,1,3,5,6,4}
// Result: 5
// Explanation: In this example, there are 2 peak numbers that are at indices 1 and 5. We can consider any of them.

// Example 3:
// Input Format: arr[] = {1, 2, 3, 4, 5}
// Result: 4
// Explanation: In this example, there is only 1 peak that is at the index 4.

// Example 4:
// Input Format: arr[] = {5, 4, 3, 2, 1}
// Result: 0
// Explanation: In this example, there is only 1 peak that is at the index 0.


// | Method         | Approach                    | Time Complexity | Space Complexity | Notes                                                                                           |
// | -------------- | --------------------------- | --------------- | ---------------- | ----------------------------------------------------------------------------------------------- |
// | `peakElement`  | Binary Search               | O(log n)        | O(1)             | Efficient, returns **any peak**. Works well for large arrays. Edge elements handled separately. |
// | `peakElement1` | Linear Scan (`max_element`) | O(n)            | O(1)             | Simple to implement. Always returns the **first maximum**. Not efficient for very large arrays. |


#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    int peakElement(vector<int>& arr, int n){
        int s = 1;
        int e = n-2;
        int mid = s + (e-s)/2;
        if(n==1)return 0;
        else if(arr[0]>arr[1])return 0;
        else if(arr[n-1]>arr[n-2])return n-1;
        else{
            while(s<=e){
                if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1])return mid;
                else if(arr[mid-1] < arr[mid] && arr[mid] < arr[mid+1])s = mid + 1;
                else e = mid -1;
                mid = s + (e-s)/2;
            }
        }
        return -1;
    }
    int peakElement1(vector<int>& arr, int n){
        return max_element(arr.begin(), arr.end())-arr.begin();
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

    int a = obj->peakElement(arr, n);
    cout<<"Peak Element position is : "<<a<<endl;

    delete obj;
    return 0;
}