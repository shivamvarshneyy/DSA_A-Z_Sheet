// | Method       | Time Complexity | Space Complexity | In-Place   | Use Case                                  |
// | ------------ | --------------- | ---------------- | --------   | ----------------------------------------- |
// | `rotate1`    | O(n)            | O(n)             | ❌        | When you need a new rotated copy          |
// | `rotate2`    | O(n)            | O(1)             | ✅        | When modifying the original is OK         |
// | `rotateLeft` | O(n)            | O(1)             | ✅        | Optimal for general `k`-position rotation |


#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    vector<int> rotate1(vector<int>& arr, int n){
        vector<int> ans;
        for(int i=1;i<n;i++)ans.emplace_back(arr[i]);
        ans.emplace_back(arr[0]);
        return ans;
    }

    vector<int> rotate2(vector<int> arr, int n){
        int temp = arr[0];
        for(int i=1;i<n;i++){
            arr[i-1] = arr[i];
        }
        arr[n-1] = temp;
        return arr;
    }

    vector<int> rotate3(vector<int> arr, int n){
        reverse(arr.begin()+1, arr.end());
        reverse(arr.begin(), arr.end());
        return arr;
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

    vector<int> ans1 = obj->rotate1(arr,n);
    for(const auto& i:ans1)cout<<i<<" ";
    cout<<endl;

    vector<int> ans2 = obj->rotate2(arr,n);
    for(const auto& i:ans2)cout<<i<<" ";
    cout<<endl;

    vector<int> ans3 = obj->rotate3(arr,n);
    for(const auto& i:ans3)cout<<i<<" ";
    cout<<endl;

    delete obj;
    return 0;
}