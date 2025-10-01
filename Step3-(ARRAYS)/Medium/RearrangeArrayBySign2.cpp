// Variety-2
// Problem Statement:
// There’s an array ‘A’ of size ‘N’ with positive and negative elements (not necessarily equal). Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values. The leftover elements should be placed at the very end in the same order as in array A.

// Note: Start the array with positive elements.

// Examples: 

// Example 1:

// Input:
// arr[] = {1,2,-4,-5,3,4}, N = 6
// Output:
// 1 -4 2 -5 3 4

// Explanation: 
// Positive elements = 1,2
// Negative elements = -4,-5
// To maintain relative ordering, 1 must occur before 2, and -4 must occur before -5.
// Leftover positive elements are 3 and 4 which are then placed at the end of the array.

// Example 2:
// Input:
// arr[] = {1,2,-3,-1,-2,-3}, N = 6
// Output:
// 1 -3 2 -1 3 -2

// Explanation: 
// Positive elements = 1,2
// Negative elements = -3,-1,-2,-4
// To maintain relative ordering, 1 must occur before 2.
// Also, -3 should come before -1, and -1 should come before -2.
// After alternate ordering, -2 and -4 are left, which would be placed at the end of the ans array.


#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    void rearrangeArrayBySign1(vector<int>& arr, int size){
        vector<int> positive;
        vector<int> negative;
        for(const int& i:arr){
            if(i>=0)positive.emplace_back(i);
            else negative.emplace_back(i);
        }
        int n = positive.size();
        int m = negative.size();
        int i = 0;
        int j = 0;
        int k = 0;
        while(i<n && j<m){
            arr[k++] = positive[i++];
            arr[k++] = negative[j++];
        }
        while(i<n)arr[k++] = positive[i++];
        while(j<m)arr[k++] = negative[j++];
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

    obj->rearrangeArrayBySign1(arr, n);
    for(const int& i:arr)cout<<i<<" ";
    cout<<endl;

    delete obj;
    return 0;
}