// Leaders in an Array

// Problem Statement: Given an array, print all the elements which are leaders. A Leader is an element that is greater than all of the elements on its right side in the array.

// Examples

// Example 1:
// Input: arr = [4, 7, 1, 0]
// Output:
//  7 1 0
// Explanation:
//  Rightmost element is always a leader. 7 and 1 are greater than the elements in their right side.

// Example 2:
// Input: arr = [10, 22, 12, 3, 0, 6]
// Output:
//  22 12 6
// Explanation:
//  6 is a leader. In addition to that, 12 is greater than all the elements in its right side (3, 0, 6), also 22 is greater than 12, 3, 0, 6.


// | Method            | Time Complexity | Space Complexity (ignoring output) | Space Complexity (including output) | Notes                                                   |
// | ----------------- | --------------- | ---------------------------------- | ----------------------------------- | ------------------------------------------------------- |
// | `leadersInArray1` | O(N²)           | O(1)                               | O(N)                                | Brute force; checks right-side elements for each index. |
// | `leadersInArray2` | O(N)            | O(1)                               | O(N)                                | Optimized scan from right with running maximum.         |



#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    vector<int> leadersInArray1(vector<int>& arr, int n){
        vector<int> ans;
        for(int i=0;i<n;i++){
            bool isOk = true;
            for(int j=i+1;j<n;j++){
                if(arr[i]<arr[j])isOk = false;
            }
            if(isOk)ans.emplace_back(arr[i]);
        }
        return ans;
    }

    vector<int> leadersInArray2(vector<int>& arr, int n){
        vector<int> ans;
        for(int i=n-1;i>=0;i--){
            if(ans.empty() || ans.back()<arr[i])
                ans.emplace_back(arr[i]);
        }
        reverse(ans.begin(), ans.end());
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

    vector<int> ans1 = obj->leadersInArray1(arr,n);
    for(const int& i: ans1)cout<<i<<" ";
    cout<<endl;

    vector<int> ans2 = obj->leadersInArray2(arr,n);
    for(const int& i: ans2)cout<<i<<" ";
    cout<<endl;

    delete obj;
    return 0;
}