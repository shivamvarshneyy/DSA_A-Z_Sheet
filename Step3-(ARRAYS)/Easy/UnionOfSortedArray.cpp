// | Method                          | Works on Unsorted?  | Time Complexity       | Space Complexity |
// | ------------------------------- | ------------------  | --------------------- | ---------------- |
// | **unionOfArray1 (set)**         | ✅ Yes              | O((n + m) log(n + m)) | O(n + m)(for set)|        
// | **unionOfArray2 (two-pointer)** | ❌ Needs sorted     | O(n + m)              | O(n + m)(for ans)|        
// | **unionOfArray3 (map)**         | ✅ Yes              | O((n + m) log(n + m)) | O(n + m)(for map)|         


#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    vector<int> unionOfArray1(vector<int>& arr1, vector<int>& arr2, int n, int m){
        vector<int> res;
        set<int> st(arr1.begin(), arr1.end());
        st.insert(arr2.begin(), arr2.end());
        for(const int& i:st)res.emplace_back(i);
        return res;
    }

    vector<int> unionOfArray2(vector<int>& arr1, vector<int>& arr2, int n, int m){
        vector<int> res;
        int i=0;
        int j=0;
        while(i<n && j<m){
            if(arr1[i]==arr2[j]){
                if((res.empty() || arr1[i]!=res.back()))
                res.push_back(arr1[i]);
                i++;
                j++;
            }else if(arr1[i]<arr2[j]){
                if((res.empty() || arr1[i]!=res.back()))
                res.push_back(arr1[i]);
                i++;
            }else if(arr1[i]>arr2[j]){
                if((res.empty()  || arr2[j]!=res.back()))
                res.push_back(arr2[j]);
                j++;
            }
        }
        while(i<n){
            if((res.empty() || arr1[i]!=res.back()))
            res.push_back(arr1[i]);
            i++;
        }
        while(j<m){
            if(res.empty()  || arr2[j]!=res.back())
            res.push_back(arr2[j]);
            j++;
        }
        
        return res;
    }

    vector<int> unionOfArray3(vector<int>& arr1, vector<int>& arr2, int n, int m){
        vector<int> res;
        map<int, int> mp;
        for(const int& i:arr1)mp[i]++;
        for(const int& i:arr2)mp[i]++;
        for(const auto& i:mp)res.emplace_back(i.first);
        return res;
    }
};

int main() {
    MySolution* obj = new MySolution;

    int n;
    cout << "Enter array1 size:" << endl;
    
    while (true) {
        cin >> n;
        if (n > 0) break;
        cout << "Invalid size. Re-enter array1 size: "<<endl;
    }

    vector<int> arr1(n);
    cout << "Enter array1 elements in ascending order:" << endl;
    for (int i = 0; i < n; i++) cin >> arr1[i];

    int m;
    cout << "Enter array2 size:" << endl;
    
    while (true) {
        cin >> m;
        if (m > 0) break;
        cout << "Invalid size. Re-enter array2 size: "<<endl;
    }

    vector<int> arr2(m);
    cout << "Enter array2 elements in ascending order:" << endl;
    for (int i = 0; i < m; i++) cin >> arr2[i];

    vector<int> ans1 = obj->unionOfArray1(arr1, arr2, n, m);

    cout<<"union of arrays arr1 and arr2 is : "<<endl;
    for(const int& i:ans1)cout<<i<<" ";
    cout<<endl;

    vector<int> ans2 = obj->unionOfArray2(arr1, arr2, n, m);

    cout<<"union of arrays arr1 and arr2 is : "<<endl;
    for(const int& i:ans2)cout<<i<<" ";
    cout<<endl;

    vector<int> ans3 = obj->unionOfArray3(arr1, arr2, n, m);

    cout<<"union of arrays arr1 and arr2 is : "<<endl;
    for(const int& i:ans3)cout<<i<<" ";
    cout<<endl;

    delete obj;
    return 0;
}