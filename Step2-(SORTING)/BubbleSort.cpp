// | Variant                     | Best Case | Average Case | Worst Case | Space Complexity | Stable? | In-Place? |
// | --------------------------- | --------- | ------------ | ---------- | ---------------- | ------- | --------- |
// | **Bubble Sort (Iterative)** | `O(n)`    | `O(n²)`      | `O(n²)`    | `O(1)`           | ✅ Yes   | ✅ Yes  |


#include<bits/stdc++.h>
using namespace std;
class MySolution{
public:
   void bubbleSort(vector<int>& arr, int n){
        for(int i=0;i<n-1;i++){
            bool isSwapped = false;
            for(int j=1;j<n-i;j++){
                if(arr[j]<arr[j-1])swap(arr[j],arr[j-1]);
                isSwapped = true;
            }
            if(isSwapped == false)return;
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
   obj->bubbleSort(arr, n);
   for(int i:arr)cout<<i<<" ";
   delete obj;
   return 0;
}