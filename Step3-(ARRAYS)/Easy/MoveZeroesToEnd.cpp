// | Method        | Time Complexity | Space | Stable (Preserve Order)?   | In-place?  | Notes              |
// | ------------- | --------------- | ----- | ------------------------   | ---------  | ------------------ |
// | `moveZeroes1` | O(n)            | O(1)  | ✅ Yes                    | ✅ Yes     | Clear and fast     |
// | `moveZeroes2` | O(n)            | O(1)  | ✅ Yes                    | ✅ Yes     | Same as 1 with STL |
// | `moveZeroes3` | O(n)            | O(1)  | ❌ No                     | ✅ Yes     | May disrupt order  |


#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    void moveZeroes1(vector<int>& arr, int n){
        int j=0;
        for(int i:arr){
            if(i!=0)arr[j++] = i;
        }
        for(int i=j;i<n;i++)arr[i]=0;
    }
    void moveZeroes2(vector<int>& arr, int n){
        int j=0;
        for(int i:arr){
            if(i!=0)arr[j++] = i;
        }
        fill(arr.begin()+j, arr.end(),0);
    }
    void moveZeroes3(vector<int>& arr, int n){
        int j=0;
        while(j<n){
            if(arr[j] == 0)break;
            j++;
        }
        for(int i=j+1;i<n;i++){
            if(arr[i]!=0){
                swap(arr[i],arr[j]);
                j++;
            }
        }
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

    obj.moveZeroes1(arr, n);

    for(int i:arr)cout<<i<<" ";
    cout<<endl;

    obj.moveZeroes2(arr, n);

    for(int i:arr)cout<<i<<" ";
    cout<<endl;

    obj.moveZeroes3(arr, n);

    for(int i:arr)cout<<i<<" ";
    cout<<endl;

    return 0;
}