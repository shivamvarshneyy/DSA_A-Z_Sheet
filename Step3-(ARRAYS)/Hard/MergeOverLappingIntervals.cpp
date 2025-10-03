// Merge Overlapping Sub-intervals

// Problem Statement: Given an array of intervals, merge all the overlapping intervals and return an array of non-overlapping intervals.

// Examples

// Example 1: 
// Input: intervals=[[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] are overlapping we can merge them to form [1,6]
//  intervals.

// Example 2:
// Input: [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Since intervals [1,4] and [4,5] are overlapping we can merge them to form [1,5].


// | Function             | Approach                                               | Time Complexity | Space Complexity  | Notes                                                                                                                                             |
// | -------------------- | ------------------------------------------------------ | --------------- | ----------------- | ------------------------------------------------------------------------------------------------------------------------------------------------- |
// | **`mergeInterval1`** | Sort intervals by start time, then merge sequentially. | **O(n log n)**  | O(n) (for result) | Sorting ensures order. Then one linear pass merges overlaps. Handles adjacent `[1,4],[4,5] → [1,5]` and nested intervals `[1,10],[2,3] → [1,10]`. |


#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    vector<pair<int, int>> mergeInterval1(vector<pair<int, int>> arr, int n){
        vector<pair<int, int>> ans;
        sort(arr.begin(), arr.end());
        for(int i=0;i<n;i++){
            if(ans.empty() || ans.back().second < arr[i].first){
                ans.push_back(arr[i]);
            }else{
                ans.back().second = max(ans.back().second, arr[i].second);
            }
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

    vector<pair<int, int>> arr(n);
    cout << "Enter array elements:" << endl;
    for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;

    vector<pair<int, int>> res = obj -> mergeInterval1(arr, n);

    cout<<"Merged Intervals are : "<<endl;
    cout<<"[";
    for(int i=0;i<res.size();i++){
        cout<<"["<<res[i].first<<", "<<res[i].second<<"]";
        if(i!=res.size()-1)cout<<", ";
    }
    cout<<"]"<<endl;

    delete obj;
    return 0;
}