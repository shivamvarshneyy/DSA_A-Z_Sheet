// | Case          | Time Complexity | Space Complexity   | Explanation                                            |
// | ------------- | --------------- | ------------------ | ------------------------------------------------------ |
// | **Best**      | `O(n log n)`    | `O(n)`             | Always divides array in half; merges take linear time  |
// | **Average**   | `O(n log n)`    | `O(n)`             | Same as best; performance doesn’t depend on input      |
// | **Worst**     | `O(n log n)`    | `O(n)`             | Even in worst input, divide + merge is still `n log n` |
// | **Stable?**   | ✅ Yes          | –                  | Maintains original order of equal elements             |
// | **In-place?** | ❌ No           | `O(n)` extra space | Temporary arrays used for merging                      |


#include<bits/stdc++.h>
using namespace std;
class MySolution{
private:
   void merge(vector<int>& arr, int low, int mid, int high){
      vector<int> temp;
      int i = low;
      int j = mid+1;
      while(i<=mid && j<=high){
         if(arr[i]<=arr[j]){
            temp.emplace_back(arr[i]);
            i++;
         }else{
            temp.emplace_back(arr[j]);
            j++;
         }
      }
      while(i<=mid){
         temp.emplace_back(arr[i]);
         i++;
      }
      while(j<=high){
         temp.emplace_back(arr[j]);
         j++;
      }
      for(int i=low;i<=high;i++){
         arr[i] = temp[i-low];
      }
   }
public:
   void mergeSort(vector<int>& arr, int low, int high){
        if(low >= high)return;
        int mid = low + (high - low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
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
   obj->mergeSort(arr, 0, n-1);
   for(int i:arr)cout<<i<<" ";
   delete obj;
   return 0;
}