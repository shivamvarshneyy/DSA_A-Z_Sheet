// | Method            | Time Complexity | Space Complexity | Sorted Required | In-Place? | Optimal |
// | ----------------- | --------------- | ---------------- | --------------- | --------- | ------- |
// | removeDuplicates1 | O(n log n)      | O(n)             | ❌              | ❌       | ❌      |
// | removeDuplicates2 | O(n)            | O(n)             | ✅              | ❌       | ✅      |
// | removeDuplicates3 | O(n)            | O(1)             | ✅              | ✅       | ✅✅   |


#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    vector<int> removeDuplicates1(vector<int>& arr, int n){
        set<int> st(arr.begin(), arr.end());
        vector<int> ans;
        for(const int& i: st)ans.emplace_back(i);
        return ans;
    }
    
    vector<int> removeDuplicates2(vector<int>& arr, int n){
        vector<int> ans;
        for(const int& i: arr){
            if(ans.empty() || ans.back()!=i)
                ans.emplace_back(i);
        }
        return ans;
    }

    int removeDuplicates3(vector<int>& arr, int n){
        int j = 0;
        for(int i=1;i<n;i++){
            if(arr[j]!=arr[i]){
                j++;
                arr[j] = arr[i];
            }
        }
        return j;
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

    vector<int> ans1 = obj->removeDuplicates1(arr, n);
    for(const int& i: ans1)cout<<i<<" ";
    cout<<endl;

    vector<int> ans2 = obj->removeDuplicates2(arr, n);
    for(const int& i: ans2)cout<<i<<" ";
    cout<<endl;

    int j = obj->removeDuplicates3(arr, n);
    for(int i=0;i<=j;i++)cout<<arr[i]<<" ";
    cout<<endl;

    delete obj;
    return 0;
}