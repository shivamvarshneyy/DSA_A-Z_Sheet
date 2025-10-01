// Rearrange Array Elements by Sign

// Problem Statement:

// There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values.

// Note: Start the array with positive elements.

// Examples: 

// Example 1:
// Input:
// arr[] = {1,2,-4,-5}, N = 4
// Output:
// 1 -4 2 -5

// Explanation: 
// Positive elements = 1,2
// Negative elements = -4,-5
// To maintain relative ordering, 1 must occur before 2, and -4 must occur before -5.

// Example 2:
// Input:
// arr[] = {1,2,-3,-1,-2,-3}, N = 6
// Output:
// 1 -3 2 -1 3 -2

// Explanation: 
// Positive elements = 1,2,3
// Negative elements = -3,-1,-2
// To maintain relative ordering, 1 must occur before 2, and 2 must occur before 3.
// Also, -3 should come before -1, and -1 should come before -2.

/********************************************************************************************************************************* */

// | Method                  | Time Complexity | Space Complexity | Stability (Relative Order Preserved)               |
// | ----------------------- | --------------- | ---------------- | -------------------------------------------------  |
// | `rearrangeArrayBySign1` | O(N)            | O(N)             | ✅ Yes                                             |
// | `rearrangeArrayBySign2` | O(N)            | O(N)             | ✅ Yes (since positives/negatives filled in order) |




#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    void rearrangeArrayBySign1(vector<int>& arr, int n){
        vector<int> positive;
        vector<int> negative;
        for(const int& i:arr){
            if(i>=0)positive.emplace_back(i);
            else negative.emplace_back(i);
        }
        for(int i=0;i<n/2;i++){
            arr[2*i] = positive[i];
            arr[2*i+1] = negative[i];
        }
    }

    void rearrangeArrayBySign2(vector<int>& arr, int n){
        vector<int> nums(n);
        int j = 0;
        int k = 1;
        for(const int& i: arr){
            if(i>=0){
                nums[j] = i;
                j+=2;
            }else{
                nums[k] = i;
                k+=2;
            }
        }
        arr.assign(nums.begin(), nums.end());
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

    obj->rearrangeArrayBySign2(arr, n);
    for(const int& i:arr)cout<<i<<" ";
    cout<<endl;

    delete obj;
    return 0;
}