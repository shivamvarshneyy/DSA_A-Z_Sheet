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
   int maxElement = INT_MIN;
   int minElement = INT_MAX;
   int ans1 = -1;
   int ans2 = -1;
   for(const auto& i : mp){
        if(maxElement<i.second){
            maxElement = i.second;
            ans1 = i.first;
        }
        if(minElement>i.second){
            minElement = i.second;
            ans2 = i.first;
        }
   }
   cout<<ans1<<" "<<ans2;
   return 0;
}