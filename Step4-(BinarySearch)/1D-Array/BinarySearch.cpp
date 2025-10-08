/*

Binary Search

Problem statement: You are given a sorted array of integers and a target,
                   your task is to search for the target in the given array.
                   Assume the given array does not contain any duplicate numbers.

Example :          Let’s say the given array is = {3, 4, 6, 7, 9, 12, 16, 17} and target = 6,
                   then output will be "true" or if we find position then output will be 2.
                   in case element is not present then it will return false or -1 as output.


----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
| Approach                    | Code Function   | Time Complexity | Space Complexity | Output                    | Pros                           | Cons                                     |
| --------------------------- | --------------- | --------------- | ---------------- | ------------------------- | ------------------------------ | ---------------------------------------- |
| **Iterative Binary Search** | `binarySearch1` | **O(log n)**    | **O(1)**         | Returns **index** (or -1) | Full control, returns position | More lines of code                       |
| **STL `binary_search`**     | `binarySearch2` | **O(log n)**    | **O(1)**         | Returns **true/false**    | Concise, easy to use           | Doesn’t return position (only existence) |
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

*/

#include <bits/stdc++.h>
#include "../../Header_File/BinarySearch.h"
using namespace std;


class MySolution {
public:
    int binarySearch1(vector<int>& arr, int target, int n){
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;
        while(s<=e){
            if(arr[mid] == target)return mid;
            else if(arr[mid] > target)e = mid - 1;
            else s = mid + 1;
            mid = s + (e-s)/2;
        }
        return -1;
    }
    int binarySearch2(vector<int>& arr, int target, int n){
        return binary_search(arr.begin(), arr.end(), target);
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

    int a = obj->binarySearch1(arr, target, n);
    if (a != -1) cout << "The element is present at index " << a << " in array." << endl;
    else cout << "The element is not present in array." << endl;


    int b = obj->binarySearch2(arr, target, n);
    if(b)cout<<"true"<<endl;
    else cout<<"false"<<endl;

    bool c = BinarySearch<int>::binarySearch(arr, target);
    if(c)cout<<"true"<<endl;
    else cout<<"false"<<endl;

    delete obj;
    return 0;
}