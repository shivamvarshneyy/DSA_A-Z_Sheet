#include <bits/stdc++.h>
#include "../../Header_File/LinearSearch.h"
using namespace std;

class MySolution {
public:
    int linearSearch(vector<int>& arr, int target, int n){
        for(int i=0;i<n;i++){
            if(arr[i]==target)return i;
        }
        return -1;
    }

    bool linearSearch2(vector<int>& arr, int target){
        return LinearSearch<int>::search(arr, target);
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

    int target;
    cout << "Enter element to find:" << endl;
    cin>>target;

    int pos = obj.linearSearch(arr, target, n);
    cout<<"Position : "<<pos<<endl;

    bool isThere = obj.linearSearch2(arr, target);
    if(isThere == 1) cout<<"true"<<endl;
    else cout<<"false"<<endl;

    return 0;
}