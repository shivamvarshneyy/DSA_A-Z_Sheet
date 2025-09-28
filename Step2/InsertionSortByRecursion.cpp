// | Variant                        | Best Case | Average Case | Worst Case | Space Complexity | Stable? | In-Place? |
// | ------------------------------ | --------- | ------------ | ---------- | ---------------- | ------- | --------- |
// | **Insertion Sort (Iterative)** | `O(n)`    | `O(n²)`      | `O(n²)`    | `O(1)`           | ✅ Yes   | ✅ Yes  |
// | **Insertion Sort (Recursive)** | `O(n)`    | `O(n²)`      | `O(n²)`    | `O(n)` (stack)   | ✅ Yes   | ✅ Yes  |


#include<bits/stdc++.h>
using namespace std;
class MySolution{
public:
   void recursiveInsertionSort(vector<int>& arr, int i, int n){
      if(i==n)return;
      int j = i;
      while(j>0 && arr[j-1]>arr[j]){
         swap(arr[j],arr[j-1]);
         j--;
      }
      recursiveInsertionSort(arr, i+1, n);
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
   obj->recursiveInsertionSort(arr, 1, n);
   for(int i:arr)cout<<i<<" ";
   delete obj;
   return 0;
}