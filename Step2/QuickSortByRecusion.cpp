#include<bits/stdc++.h>
using namespace std;
class MySolution{
private:
   int partition(vector<int>& arr, int low, int high){
      int i = low;
      int j = high;
      int pivot = low;
      while(i<j){
         while(i <= high-1 && arr[i]<=arr[pivot])i++;
         while(j >= low+1 && arr[j]>arr[pivot])j--;
         if(i<j)swap(arr[i], arr[j]);
      }
      swap(arr[j],arr[pivot]);
      return j;
   }
public:
   void quickSort(vector<int>& arr, int low, int high){
        if(low>=high)return;
        int p = partition(arr, low, high);
        quickSort(arr, low, p-1);
        quickSort(arr, p+1, high);
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
   obj->quickSort(arr, 0, n-1);
   for(int i:arr)cout<<i<<" ";
   delete obj;
   return 0;
}