// | Method    | Time Complexity | Space Complexity | In-Place  | Description / Notes                             |
// | --------- | --------------- | ---------------- | --------  | ----------------------------------------------- |
// | `rotate1` | **O(n)**        | **O(1)**         | ✅        | Reversal algorithm (most optimal in-place)      |
// | `rotate2` | **O(n)**        | **O(n)**         | ❌        | Uses a new vector with modular indexing         |
// | `rotate3` | **O(n)**        | **O(k)**         | ❌        | Stores first `k` elements, then shifts manually |


#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    vector<int> rotate1(vector<int>& arr, int k, int n){
        k = k%n;
        reverse(arr.begin(), arr.begin()+k);
        reverse(arr.begin()+k, arr.end());
        reverse(arr.begin(), arr.end());
        return arr;
    }

    vector<int> rotate2(vector<int>& arr, int k, int n){
        k = k%n;
        vector<int> ans;
        for(int i=k;i<k+n;i++){
            ans.emplace_back(arr[i%n]);
        }
        return ans;
    }

    vector<int> rotate3(vector<int>& arr, int k, int n){
        k = k%n;
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.emplace_back(arr[i]);
        }
        for(int i=k;i<n;i++){
            arr[i-k] = arr[i];
        }
        for(int i=n-k;i<n;i++){
            arr[i] = ans[i-n+k];
        }
        return arr;
    }
};

int main() {
    MySolution obj;

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

    int k;
    cout<<"Enter the number of postition to rotate"<<endl;
    cin>>k;

    vector<int> ans1 = obj.rotate1(arr, k, n);
    for(const int& i : ans1)cout<<i<<" ";
    cout<<endl;

    vector<int> ans2 = obj.rotate2(arr, k, n);
    for(const int& i : ans2)cout<<i<<" ";
    cout<<endl;

    vector<int> ans3 = obj.rotate3(arr, k, n);
    for(const int& i : ans3)cout<<i<<" ";
    cout<<endl;

    return 0;
}