// Longest Consecutive Sequence in an Array

// Problem Statement: You are given an array of ‘N’ integers. You need to find the length of the longest sequence which contains the consecutive elements.

// Examples

// Example 1:
// Input: [100, 200, 1, 3, 2, 4]
// Output: 4
// Explanation: The longest consecutive subsequence is 1, 2, 3, and 4.

// Example 2:
// Input: [3, 8, 5, 7, 6]
// Output: 4
// Explanation: The longest consecutive subsequence is 5, 6, 7, and 8.

// | Method                                | Time Complexity            | Space Complexity | Notes                                                                   |
// | ------------------------------------- | -------------------------- | ---------------- | ----------------------------------------------------------------------- |
// | `longestConsecutiveSequence1` (naive) | O(N²) average, O(N³) worst | O(1)             | For each element, linear search on array. Very slow for large inputs.   |
// | `longestConsecutiveSequence2`         | O(N²) average, O(N²) worst | O(1)             | Same as #1, but skips inner loop if `element-1` exists.                 |
// | `longestConsecutiveSequence3` (sort)  | O(N log N)                 | O(1) / O(N)      | Sort array then check consecutive streaks. Handle duplicates carefully. |
// | `longestConsecutiveSequence4` (hash)  | O(N) average (amortized)   | O(N)             | Best solution: unordered_set gives O(1) lookups.                        |


#include <bits/stdc++.h>
using namespace std;

class MySolution {
private:
    bool linearSearch(vector<int>& arr, int target){
        for(const int& i:arr){
            if(i==target)return true;
        }
        return false;
    }
public:
    int longestConsecutiveSequence1(vector<int> arr, int n){
        int ans = INT_MIN;
        int count = 0;
        int element = 0;
        for(const int& i:arr){
            element = i;
            while(linearSearch(arr, element)){
                count++;
                element += 1;
            }
            ans = max(ans, count);
            count = 0;
        }
        return ans;
    }

    int longestConsecutiveSequence2(vector<int> arr, int n){
        int ans = INT_MIN;
        int count = 0;
        int element = 0;
        for(const int& i:arr){
            element = i;
            if(linearSearch(arr, element-1))continue;
            while(linearSearch(arr, element)){
                count++;
                element += 1;
            }
            ans = max(ans, count);
            count = 0;
        }
        return ans;
    }

    int longestConsecutiveSequence3(vector<int> arr, int n){
        int ans = INT_MIN;
        int count = 1;
        int element = 0;
        sort(arr.begin(), arr.end());
        for(int i=1;i<n;i++){
            if(arr[i-1]+1 == arr[i])count++;
            else{
                ans = max(ans, count);
                count = 1;
            }
        }
        ans = max(ans, count);
        return ans;
    }

    int longestConsecutiveSequence4(vector<int> arr, int n){
        int ans = INT_MIN;
        int count = 0;
        int element = 0;
        unordered_set<int> st(arr.begin(),arr.end());
        for(const int& i:st){
            element = i;
            if(st.find(element-1)!=st.end())continue;
            while(st.find(element)!=st.end()){
                count++;
                element += 1;
            }
            ans = max(ans, count);
            count = 0;
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

    int a = obj->longestConsecutiveSequence1(arr, n);
    cout<<"Length of longest consecutive sequence : "<<a<<endl;

    int b = obj->longestConsecutiveSequence2(arr, n);
    cout<<"Length of longest consecutive sequence : "<<b<<endl;

    int c = obj->longestConsecutiveSequence3(arr, n);
    cout<<"Length of longest consecutive sequence : "<<c<<endl;

    int d = obj->longestConsecutiveSequence4(arr, n);
    cout<<"Length of longest consecutive sequence : "<<d<<endl;

    delete obj;
    return 0;
}