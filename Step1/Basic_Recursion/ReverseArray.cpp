#include<bits/stdc++.h>
using namespace std;
class MySolution{
public:
   void reverseArray(vector<int>& arr, int i, int n){
        if(i>=n/2)return;
        swap(arr[i],arr[n-i-1]);
        reverseArray(arr, i+1, n);
   }
};
int main(){
   MySolution* obj = new MySolution;
   int n;
   cout<<"Enter a Array size"<<endl;
   cin>>n;
   vector<int> arr(n);
   cout<<"Enter a Array element"<<endl;
   for(int i=0;i<n;i++)cin>>arr[i];
   obj->reverseArray(arr, 0, n);
   for(int i:arr)cout<<i<<" ";
   delete obj;
   return 0;
}