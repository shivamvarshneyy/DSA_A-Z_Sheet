// Find the repeating and missing numbers

// Problem Statement: You are given a read-only array of N integers with values also in the range [1, N] both inclusive. Each integer appears exactly once except A which appears twice and B which is missing. The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.

// Examples

// Example 1:
// Input Format:  array[] = {3,1,2,5,3}
// Result: {3,4)
// Explanation: A = 3 , B = 4 
// Since 3 is appearing twice and 4 is missing

// Example 2:
// Input Format: array[] = {3,1,2,5,4,6,7,5}
// Result: {5,8)
// Explanation: A = 5 , B = 8 
// Since 5 is appearing twice and 8 is missing


/* **************************************************************************************************** */
// | Method        | Approach                      | Time Complexity | Space Complexity |
// | ------------- | ----------------------------- | --------------- | ---------------- |
// | `findNumber1` | Frequency array               | O(n)            | O(n)             |
// | `findNumber2` | Hash map + sum check          | O(n)            | O(n)             |
// | `findNumber3` | Sum & square equations        | O(n)            | O(1)             |
// | `findNumber4` | XOR + partitioning by set bit | O(n)            | O(1)             |


#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    pair<int, int> findNumber1(vector<int>& arr, int n){
        vector<int> mp(n+1,0);
        for(const int& i:arr){
            mp[i]++;
        }
        pair<int, int> ans;
        for(int i=1;i<=n;i++){
            if(mp[i]==2)ans.first = i;
            if(mp[i]==0)ans.second = i;
        }
        return ans;
    }

    pair<int, int> findNumber2(vector<int>& arr, int n){
        unordered_map<int, int> mp;
        int sum = 0;
        for(const int& i:arr){
            mp[i]++;
            sum+=i;
        }
        int repeating = -1;
        for(const auto& i:mp){
            if(i.second==2)repeating = i.first;
        }
        sum -= repeating;
        int missing = (n*(n+1))/2 - sum;
        return {repeating, missing};
    }

    pair<int, int> findNumber3(vector<int>& arr, int n){ 
        long long sum = 0;
        long long sumOfSquare = 0;
        int repeating = -1;
        int missing = -1;
        for(const int& i:arr)sum+=i,sumOfSquare+=(i*i);
        long long Sn = (n*(n+1))/2;
        long long SoSn = (n*(n+1)*(2LL*n+1))/6;
        int x = Sn - sum;
        int y = (SoSn - sumOfSquare)/x;
        
        missing = (x+y)/2;
        repeating = (y-x)/2;
        
        return {repeating, missing};
    }

    pair<int, int> findNumber4(vector<int>& arr, int n){ 
        int R = 0;
        int M = 0;
        int xr = 0;
        for(int i=0;i<n;i++){
            xr ^= (i+1);
            xr ^= arr[i];
        }
        int pos = xr & -xr;

        for(int i=0;i<n;i++){
            if((arr[i]&pos) != 0)R ^= arr[i];
            else M ^= arr[i];

            if(((i+1)&pos) != 0)R ^= (i+1);
            else M ^= (i+1);
        }  
        for(const auto& i:arr){
            if(M==i)return {M,R};
        }
        return {R, M};
    }
};

int main() {
    MySolution* obj = new MySolution;

    int n;
    cout << "Enter array size:" << endl;
    
    while (true) {
        cin >> n;
        if (n > 0) break;
        cout << "Invalid size. Re-enter array size: ";
    }

    vector<int> arr(n);
    cout << "Enter array elements:" << endl;
    for (int i = 0; i < n; i++) cin >> arr[i];

    pair<int, int> p = obj->findNumber1(arr, n);
    cout<<"Repeating Number : "<<p.first<<" Missing Number : "<<p.second<<endl;

    pair<int, int> q = obj->findNumber2(arr, n);
    cout<<"Repeating Number : "<<q.first<<" Missing Number : "<<q.second<<endl;

    pair<int, int> r = obj->findNumber3(arr, n);
    cout<<"Repeating Number : "<<r.first<<" Missing Number : "<<r.second<<endl;

    pair<int, int> s = obj->findNumber4(arr, n);
    cout<<"Repeating Number : "<<s.first<<" Missing Number : "<<s.second<<endl;

    delete obj;
    return 0;
}