// 4 Sum | Find Quads that add up to a target value

// Problem Statement: Given an array of N integers, your task is to find unique quads that add up to give a target value. In short, you need to return an array of all the unique quadruplets [arr[a], arr[b], arr[c], arr[d]] such that their sum is equal to a given target.

// Note:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// arr[a] + arr[b] + arr[c] + arr[d] == target

// Examples

// Example 1:
// Input Format: arr[] = [1,0,-1,0,-2,2], target = 0
// Result: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// Explanation: We have to find unique quadruplets from the array such that the sum of those elements is equal to the target sum given that is 0. The result obtained is such that the sum of the quadruplets yields 0.

// Example 2:
// Input Format: arr[] = [4,3,3,4,4,2,1,2,1,1], target = 9
// Result: [[1,1,3,4],[1,2,2,4],[1,2,3,3]]
// Explanation: The sum of all the quadruplets is equal to the target i.e. 9.

// | Method               | Approach               | Time Complexity | Space Complexity              | Notes                                                          |
// | -------------------- | ---------------------- | --------------- | ----------------------------- | -------------------------------------------------------------- |
// | `uniqueQuadraplets1` | Brute Force            | O(n⁴ log m)     | O(m)                          | Checks all quadruplets, uses set for uniqueness. Slow.         |
// | `uniqueQuadraplets2` | Hashing                | O(n³ log m)     | O(n + m)                      | Faster than brute force, still uses set and extra space.       |
// | `uniqueQuadraplets3` | Sorting + Two Pointers | O(n³)           | O(1) extra (O(m) for results) | Optimal approach, skips duplicates directly. Best in practice. |


#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    vector<vector<int>> uniqueQuadraplets1(vector<int>& arr, int target, int n){
        set<vector<int>> ans;
        long long int sum = 0;
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                for(int k=j+1;k<n-1;k++){
                    sum = 0;
                    for(int l=k+1;l<n;l++){
                        sum = arr[i] + arr[j];
                        sum += arr[k];
                        sum += arr[l];
                        if(sum == target){
                            vector<int> temp = {arr[i],arr[j],arr[k],arr[l]};
                            sort(temp.begin(), temp.end());
                            ans.insert(temp);
                        }
                    }
                }
            }
        }
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }

    vector<vector<int>> uniqueQuadraplets2(vector<int>& arr, int target, int n){
        set<vector<int>> ans;
        long long int sum = 0;
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                set<int> st;
                for(int k=j+1;k<n;k++){
                    sum = arr[i] + arr[j];
                    sum += arr[k];
                    int rem = target - sum;
                    if(st.find(rem) != st.end()){
                        vector<int> temp = {arr[i],arr[j],arr[k],rem};
                        sort(temp.begin(), temp.end());
                        ans.insert(temp);
                    }  
                    st.insert(arr[k]); 
                }
            }
        }
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }

    vector<vector<int>> uniqueQuadraplets3(vector<int>& arr, int target, int n){
        vector<vector<int>> ans;
        long long int sum = 0;
        sort(arr.begin(), arr.end());
        for(int i=0;i<n;i++){
            if(i>0 && arr[i-1]==arr[i])continue;
            for(int j=i+1;j<n;j++){
                if(i+1<j && arr[j-1]==arr[j])continue;
                int k = j+1;
                int l = n-1;
                sum = 0;
                while(k<l){
                    sum = arr[i] + arr[j];
                    sum += arr[k];
                    sum += arr[l];
                    if(sum == target){
                        ans.push_back({arr[i], arr[j], arr[k], arr[l]});
                        k++;
                        l--;
                        while(k<l && arr[k-1] == arr[k])k++;
                        while(k<l && arr[l+1] == arr[l])l--;
                    }else if(sum>target){
                        l--;
                    }else{
                        k++;
                    }
                }
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

    vector<int> arr(n);
    cout << "Enter array elements:" << endl;
    for (int i = 0; i < n; i++) cin >> arr[i];

    int target;
    cout<<"Enter Target: "<<endl;
    cin>>target;

    vector<vector<int>> ans1 = obj->uniqueQuadraplets1(arr, target, n);
    for (const auto &i : ans1)
    {
        for (const auto &j : i)
        {
            cout << j << " ";
        }
    }
    cout << endl;

    vector<vector<int>> ans2 = obj->uniqueQuadraplets2(arr, target, n);
    for (const auto &i : ans2)
    {
        for (const auto &j : i)
        {
            cout << j << " ";
        }
    }
    cout << endl;

    vector<vector<int>> ans3 = obj->uniqueQuadraplets3(arr, target, n);
    for (const auto &i : ans3)
    {
        for (const auto &j : i)
        {
            cout << j << " ";
        }
    }
    cout << endl;

    delete obj;
    return 0;
}