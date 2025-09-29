#include <bits/stdc++.h>
using namespace std;
class MySolution
{
public:
    bool isSorted(vector<int>& arr, int n){
        if(n==1)return true;
        for(int i=1;i<n;i++){
            if(arr[i-1]>arr[i])return false;
        }
        return true;
    }
    // Time Complexity -> O(N);
    // Space Complexity -> O(1);

};
int main()
{
    MySolution *obj = new MySolution;
    int n;
    cout << "Enter a array size" << endl;
    while (true)
    {
        cin >> n;
        if (n > 0)
            break;
        cout << "Invalid array size.Please re-enter array size" << endl;
    }
    vector<int> arr(n);
    cout << "Enter array elements" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if(obj->isSorted(arr, n))
    cout <<"true"<< endl;
    else cout<<"false"<<endl;
    delete obj;
    return 0;
}