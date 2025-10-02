// 3 Sum : Find triplets that add up to a zero

// Problem Statement: Given an array of N integers, your task is to find unique triplets that add up to give a sum of zero. In short, you need to return an array of all the unique triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, and their sum is equal to zero.

// Examples

// Example 1:
// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: Out of all possible unique triplets possible, [-1,-1,2] and [-1,0,1] satisfy the condition of summing up to zero with i!=j!=k

// Example 2:
// Input: nums=[-1,0,1,0]
// Output: [[-1,0,1],[-1,1,0]]
// Explanation: Out of all possible unique triplets possible, [-1,0,1] and [-1,1,0] satisfy the condition of summing up to zero with i!=j!=k

// | Method                | Approach                                                | Time Complexity            | Space Complexity             | Notes                                                               |
// | --------------------- | ------------------------------------------------------- | -------------------------- | ---------------------------- | ------------------------------------------------------------------- |
// | **`uniqueTriplets1`** | Brute Force (3 nested loops + set to remove duplicates) | O(n³ log m)                | O(m) for storing triplets    | Sorting 3-element triplet is O(1), main cost is inserting into set. |
// | **`uniqueTriplets2`** | Hashing with `unordered_set` (fix i, use set for j,k)   | O(n²) avg (hash insertion) | O(n + m)                     | Sorting each triplet unnecessary; uniqueness handled by hash set.   |
// | **`uniqueTriplets3`** | Sorting + Two Pointers (optimal approach)               | O(n²)                      | O(1) extra (O(m) for result) | Most efficient, skips duplicates directly.                          |


#include <bits/stdc++.h>
using namespace std;

class MySolution
{
public:
    vector<vector<int>> uniqueTriplets1(vector<int> &arr, int n)
    {
        set<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (arr[i] + arr[j] + arr[k] == 0)
                    {
                        vector<int> temp = {arr[i], arr[j], arr[k]};
                        sort(temp.begin(), temp.end());
                        ans.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
    vector<vector<int>> uniqueTriplets2(vector<int> &arr, int n)
    {
        set<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            unordered_set<int> st;
            for (int j = i + 1; j < n; j++)
            {
                int rem = -(arr[i]+arr[j]);
                if (st.find(rem) != st.end())
                    {
                        vector<int> temp = {arr[i], arr[j], rem};
                        sort(temp.begin(), temp.end());
                        ans.insert(temp);
                    }
                st.insert(arr[j]);
            }
        }
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
    vector<vector<int>> uniqueTriplets3(vector<int> &arr, int n)
    {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++)
        {
            if(i>0 && arr[i-1]==arr[i])continue;
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum == 0){
                    ans.push_back({arr[i], arr[j], arr[k]});
                    j++;
                    k--;
                    while(j<k && arr[k+1]==arr[k])k--;
                    while(j<k && arr[j-1]==arr[j])j++;
                }
                else if (sum > 0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    MySolution *obj = new MySolution;

    int n;
    cout << "Enter array size:" << endl;

    while (true)
    {
        cin >> n;
        if (n > 0)
            break;
        cout << "Invalid size. Re-enter array size: ";
    }

    vector<int> arr(n);
    cout << "Enter array elements:" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<vector<int>> ans1 = obj->uniqueTriplets1(arr, n);
    for (const auto &i : ans1)
    {
        for (const auto &j : i)
        {
            cout << j << " ";
        }
    }
    cout << endl;

    vector<vector<int>> ans2 = obj->uniqueTriplets2(arr, n);
    for (const auto &i : ans2)
    {
        for (const auto &j : i)
        {
            cout << j << " ";
        }
    }
    cout << endl;

    vector<vector<int>> ans3 = obj->uniqueTriplets3(arr, n);
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