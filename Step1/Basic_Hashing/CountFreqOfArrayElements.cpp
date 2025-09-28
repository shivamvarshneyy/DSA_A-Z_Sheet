#include<bits/stdc++.h>
using namespace std;

int main(){
   int n;
   cout<<"Enter a array Size"<<endl;
   cin>>n;
   vector<int> arr(n);
   cout<<"Enter a array elements"<<endl;
   map<int, int> mp;
   for(int i=0;i<n;i++){
        cin>>arr[i];
        mp[arr[i]]++;
   }
   cout<<"[";
   for(const auto& i : mp){
        cout<<"["<<i.first<<","<<i.second<<"]";
   }
   cout<<"]";
   return 0;
}