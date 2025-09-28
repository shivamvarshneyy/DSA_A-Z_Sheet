// | Variant                     | Best Case | Average Case | Worst Case | Space Complexity | Stable? | In-Place? |
// | --------------------------- | --------- | ------------ | ---------- | ---------------- | ------- | --------- |
// | **Bubble Sort (Iterative)** | `O(n)`    | `O(n²)`      | `O(n²)`    | `O(1)`           | ✅ Yes   | ✅ Yes  |
// | **Bubble Sort (Recursive)** | `O(n)`    | `O(n²)`      | `O(n²)`    | `O(n)` (stack)   | ✅ Yes   | ✅ Yes  |

#include<bits/stdc++.h>
using namespace std;
class MySolution{
public:
   void recursiveBubbleSort(vector<int>& arr, int n){
        if(n==1)return;
        for(int i=1;i<n;i++){
            if(arr[i-1]>arr[i])swap(arr[i-1],arr[i]);
        }
        recursiveBubbleSort(arr, n-1);
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
   obj->recursiveBubbleSort(arr, n);
   for(int i:arr)cout<<i<<" ";
   delete obj;
   return 0;
}