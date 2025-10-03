// Merge two Sorted Arrays Without Extra Space

// Problem statement: Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

// Examples

// Example 1:
// Input:
// n = 4, arr1[] = [1 4 8 10]
// m = 5, arr2[] = [2 3 9]
// Output:
// arr1[] = [1 2 3 4]
// arr2[] = [8 9 10]
// Explanation: After merging the two non-decreasing arrays, we get, 1,2,3,4,8,9,10.

// Example2:
// Input:
// n = 4, arr1[] = [1 3 5 7]
// m = 5, arr2[] = [0 2 6 8 9]
// Output:
// arr1[] = [0 1 2 3]
// arr2[] = [5 6 7 8 9]
// Explanation: After merging the two non-decreasing arrays, we get, 0 1 2 3 5 6 7 8 9.

// | Method          | Approach                                                                                                   | Time Complexity                                     | Space Complexity | Notes / Pros & Cons                                                                                                                                     |
// | --------------- | ---------------------------------------------------------------------------------------------------------- | --------------------------------------------------- | ---------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------|
// | **mergeArray1** | **Extra array method**: Merge into a temporary array, then copy back to `arr1` and `arr2`                  | O(m + n)                                            | O(m + n)         | ✅ Simple and easy to implement<br>❌ Uses extra space (not in-place)                                                                                  |
// | **mergeArray2** | **Swap & sort method**: Swap largest in `arr1` with smallest in `arr2`, then sort both arrays individually | O((m+n) log m + (m+n) log n) → O(m log m + n log n) | O(1)             | ✅ In-place, no extra array<br>❌ Sorting after swap increases runtime; slower for large arrays                                                        |
// | **mergeArray3** | **Gap method (Shell-sort like)**: Compare elements at gap distance and reduce gap until 0                  | O((m+n) log(m+n))                                   | O(1)             | ✅ In-place, no extra array<br>✅ Efficient for large arrays compared to mergeArray2<br>❌ Slightly more complex to implement; careful indexing needed |


#include <bits/stdc++.h>
using namespace std;

class MySolution
{
public:
    void mergeArray1(vector<int> &arr1, vector<int> &arr2, int m, int n)
    {
        vector<int> temp;
        int i = 0;
        int j = 0;
        while (i < m && j < n)
        {
            if (arr1[i] <= arr2[j])
                temp.emplace_back(arr1[i++]);
            else
                temp.emplace_back(arr2[j++]);
        }
        while (i < m)
            temp.emplace_back(arr1[i++]);
        while (j < n)
            temp.emplace_back(arr2[j++]);
        for (i = 0; i < m; i++)
        {
            arr1[i] = temp[i];
        }
        for (j = 0; j < n; j++)
        {
            arr2[j] = temp[j + m];
        }
    }
    void mergeArray2(vector<int> &arr1, vector<int> &arr2, int m, int n)
    {
        int i = m - 1;
        int j = 0;
        while (i >= 0 && j < n)
        {
            if (arr1[i] > arr2[j])
            {
                swap(arr1[i], arr2[j]);
                i--;
                j++;
            }
            else
            {
                break;
            }
        }
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
    }
    void mergeArray3(vector<int> &arr1, vector<int> &arr2, int m, int n)
    {
        int len = m+n;
        int gap = len/2 + len%2;
        while(gap>0){
            int left = 0;
            int right = left + gap;
            while(right < len){
                if(left<m && right>=m){
                    if(arr1[left]>arr2[right-m])swap(arr1[left], arr2[right-m]);
                }else if(left>=m){
                    if(arr2[left-m]>arr2[right-m])swap(arr2[left-m],arr2[right-m]);
                }else{
                    if(arr1[left]>arr1[right])swap(arr1[left],arr1[right]);
                }
                left++;
                right++;
            }
            if(gap == 1)break;
            gap = gap/2 + gap%2;
        }
    }
};

int main()
{
    MySolution *obj = new MySolution;

    int m;
    cout << "Enter array1 size:" << endl;

    while (true)
    {
        cin >> m;
        if (m > 0)
            break;
        cout << "Invalid size. Re-enter array1 size: ";
    }

    vector<int> arr1(m);
    cout << "Enter array1 elements:" << endl;
    for (int i = 0; i < m; i++)
        cin >> arr1[i];

    int n;
    cout << "Enter array2 size:" << endl;

    while (true)
    {
        cin >> n;
        if (n > 0)
            break;
        cout << "Invalid size. Re-enter array2 size: ";
    }

    vector<int> arr2(n);
    cout << "Enter array2 elements:" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr2[i];

    obj->mergeArray3(arr1, arr2, m, n);

    cout << "Sorted Arrays are : " << endl;
    cout << "Array1 : ";
    for (const int &i : arr1)
        cout << i << " ";
    cout << endl;
    cout << "Array2 : ";
    for (const int &i : arr2)
        cout << i << " ";
    cout << endl;

    delete obj;
    return 0;
}