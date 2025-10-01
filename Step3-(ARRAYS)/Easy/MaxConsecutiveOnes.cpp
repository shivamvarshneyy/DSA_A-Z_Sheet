// Count Maximum Consecutive One's in the array

// Problem Statement: Given an array that contains only 1 and 0 return the count of maximum consecutive ones in the array.

// Examples:

// Example 1:

// Input: prices = {1, 1, 0, 1, 1, 1}

// Output: 3

// Explanation: There are two consecutive 1’s and three consecutive 1’s in the array out of which maximum is 3.

// Input: prices = {1, 0, 1, 1, 0, 1} 

// Output: 2

// Explanation: There are two consecutive 1's in the array. 


// | Method     | Time Complexity | Space Complexity | Notes                                                                                                     |
// | ---------- | --------------- | ---------------- | --------------------------------------------------------------------------------------------------------- |
// | `maxOnes1` | O(n)            | O(1)             | Iterates through the array, counts consecutive 1's, updates maxCount. Works for any array with 0s and 1s. |  |



#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    int maxOnes1(vector<int>& arr, int n){
        int ans = 0;
        int count = 0;
        for(int i:arr){
            if(i==1)count++;
            else{
                ans = max(ans, count);
                count = 0;
            }
        }
        ans = max(ans, count);
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

    int a = obj->maxOnes1(arr,n);
    cout<<"Max consecutive one's present in array: "<<a<<endl;

    delete obj;
    return 0;
}