// Majority Elements(N/3 times) | Find the elements that appears more than N/3 times in the array

// Problem Statement: Given an array of N integers. Find the elements that appear more than N/3 times in the array. If no such element exists, return an empty vector.

// Examples

// Example 1:
// Input Format: N = 5, array[] = {1,2,2,3,2}
// Result: 2
// Explanation: Here we can see that the Count(1) = 1, Count(2) = 3 and Count(3) = 1.Therefore, the count of 2 is greater than N/3 times. Hence, 2 is the answer.

// Example 2:
// Input Format:  N = 6, array[] = {11,33,33,11,33,11}
// Result: 11 33
// Explanation: Here we can see that the Count(11) = 3 and Count(33) = 3. Therefore, the count of both 11 and 33 is greater than N/3 times. Hence, 11 and 33 is the answer.

// 📊 Complexity Comparison Table
// | Function           | Approach                   | Time Complexity | Space Complexity |
// | ------------------ | -------------------------- | --------------- | ---------------- |
// | `majorityElement1` | Brute Force                | **O(n²)**       | **O(1)**         |
// | `majorityElement2` | Sorting                    | **O(n log n)**  | **O(1)**         |
// | `majorityElement3` | Hashing                    | **O(n)**        | **O(n)**         |
// | `majorityElement4` | Moore’s Voting (optimized) | **O(n)**        | **O(1)**         |


#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    vector<int> majorityElement1(vector<int>& arr, int n){
        vector<int> ans;
        int count = 0;
        for(int i=0;i<n;i++){
            count = 0;
            for(int j=i;j<n;j++){
                if(arr[i]==arr[j])count++;
            }
            if(find(ans.begin(), ans.end(), arr[i]) != ans.end())continue;
            if(count>n/3)ans.emplace_back(arr[i]);
            if(ans.size()==2)break;
        }
        return ans;
    }

    vector<int> majorityElement2(vector<int>& arr, int n){
        vector<int> ans;
        sort(arr.begin(), arr.end());
        int count = 1;
        for(int i=1;i<n;i++){
            if(arr[i-1] == arr[i])count++;
            else count = 1; 
            if(count>n/3 && (ans.empty() || ans.back()!=arr[i]))ans.emplace_back(arr[i]);
            if(ans.size()==2)break;
        }
        return ans;
    }

    vector<int> majorityElement3(vector<int>& arr, int n){
        vector<int> ans;
        unordered_map<int, int> mp;
        for(const int& i : arr)mp[i]++;
        for(const auto& i : mp){
            if(i.second>n/3)ans.emplace_back(i.first);
        }
        return ans;
    }

    vector<int> majorityElement4(vector<int>& arr, int n){
        //Extended Moore’s Voting algorithm
        vector<int> ans;
        int ele1 = -1;
        int ele2 = -1;
        int count1 = 0;
        int count2 = 0;
        for(const auto& i : arr){
            if(count1 == 0 && ele2 != i)ele1 = i,count1=1;
            else if(count2 == 0 && ele1 != i)ele2 = i,count2=1;
            else if(ele1 == i)count1++;
            else if(ele2 == i)count2++;
            else count1--,count2--;
        }
        count1 = 0;
        count2 = 0;
        for(const auto& i:arr){
            if(ele1==i)count1++;
            if(ele2==i)count2++;
        }
        if(count1>n/3)ans.emplace_back(ele1);
        if(count2>n/3)ans.emplace_back(ele2);
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

    vector<int> ans1 = obj->majorityElement1(arr, n);
    cout<<"Major Frequency elements are: "<<endl;
    for(const int& i:ans1)cout<<i<<" ";
    cout<<endl;

    vector<int> ans2 = obj->majorityElement2(arr, n);
    cout<<"Major Frequency elements are: "<<endl;
    for(const int& i:ans2)cout<<i<<" ";
    cout<<endl;

    vector<int> ans3 = obj->majorityElement3(arr, n);
    cout<<"Major Frequency elements are: "<<endl;
    for(const int& i:ans3)cout<<i<<" ";
    cout<<endl;

    vector<int> ans4 = obj->majorityElement4(arr, n);
    cout<<"Major Frequency elements are: "<<endl;
    for(const int& i:ans4)cout<<i<<" ";
    cout<<endl;

    delete obj;
    return 0;
}