// Two Sum : Check if a pair with given sum exists in Array

// Problem Statement: Given an array of integers arr[] and an integer target.

// 1st variant: Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.

// 2nd variant: Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.

// Note: You are not allowed to use the same element twice. Example: If the target is equal to 6 and num[1] = 3, then nums[1] + nums[1] = target is not a solution.

// Examples:

// Example 1:
// Input Format: N = 5, arr[] = {2,6,5,8,11}, target = 14
// Result: YES (for 1st variant)
//        [1, 3] (for 2nd variant)
// Explanation: arr[1] + arr[3] = 14. So, the answer is “YES” for the first variant and [1, 3] for 2nd variant.

// Example 2:
// Input Format: N = 5, arr[] = {2,6,5,8,11}, target = 15
// Result: NO (for 1st variant)
// 	[-1, -1] (for 2nd variant)
// Explanation: There exist no such two numbers whose sum is equal to the target.


// | Method                           | Time Complexity | Space Complexity | Notes                           |
// | -------------------------------- | --------------- | ---------------- | ------------------------------- |
// | `twoSum1` Brute                  | O(n²)           | O(1)             | Simple but inefficient          |
// | `twoSum2` Sorting + Two Pointers | O(n log n)      | O(n)             | Requires sorting, but efficient |
// | `twoSum3` Hashing                | O(n)            | O(n)             | Best choice, optimal            |


#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    pair<int, int> twoSum1(vector<int>& arr, int target, int n){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]+arr[j] == target)return {i, j};
            }
        }
        return {-1, -1};
    }
    pair<int, int> twoSum2(vector<int>& arr, int target, int n){
        vector<pair<int,int>> temp;
        for(int i=0;i<n;i++){
            temp.push_back({arr[i],i});
        } 
        sort(temp.begin(),temp.end());
        int i = 0;
        int j = n-1;
        while(i<j){
            int sum = temp[i].first + temp[j].first;
            if(sum == target)return{temp[i].second, temp[j].second};
            else if(sum>target)j--;
            else i++;
        }
        return {-1, -1};
    }
    pair<int, int> twoSum3(vector<int>& arr, int target, int n){
        unordered_map<int, int> hashmap;
        for(int i=0;i<n;i++){
            int rem = target - arr[i];
            if(hashmap.find(rem) != hashmap.end())return{hashmap[rem], i};
            hashmap[arr[i]] = i;
        }
        return {-1, -1};
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

    cout<< "Enter target sum: "<<endl;
    int target;
    cin>>target;

    pair<int,int> a = obj->twoSum1(arr, target, n);
    cout<<"These index have the required sum : "<<"["<<a.first<<", "<<a.second<<"]"<<endl;
    
    pair<int,int> b = obj->twoSum2(arr, target, n);
    cout<<"These index have the required sum : "<<"["<<b.first<<", "<<b.second<<"]"<<endl;
    
    pair<int,int> c = obj->twoSum3(arr, target, n);
    cout<<"These index have the required sum : "<<"["<<c.first<<", "<<c.second<<"]"<<endl;

    delete obj;
    return 0;
}