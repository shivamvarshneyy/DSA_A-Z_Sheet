#include<bits/stdc++.h>
using namespace std;
class MySolution{
public:
   void selectionSort(vector<int>& arr, int n){
        for(int i=0;i<n-1;i++){
            int mini = i;
            for(int j=i+1;j<n;j++){
                if(arr[mini]>arr[j])mini = j;
            }
            swap(arr[i], arr[mini]);
        }
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
   obj->selectionSort(arr, n);
   for(int i:arr)cout<<i<<" ";
   delete obj;
   return 0;
}