// next_permutation : find next lexicographically greater permutation

// Problem Statement: Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.

// If such an arrangement is not possible, it must rearrange to the lowest possible order (i.e., sorted in ascending order).

// Examples

// Example 1 :
// Input format: Arr[] = {1,3,2}
// Output: Arr[] = {2,1,3}
// Explanation: All permutations of {1,2,3} are {{1,2,3} , {1,3,2}, {2,13} , {2,3,1} , {3,1,2} , {3,2,1}}. So, the next permutation just after {1,3,2} is {2,1,3}.

// Example 2:
// Input format: Arr[] = {3,2,1}
// Output: Arr[] = {1,2,3}
// Explanation: As we see all permutations of {1,2,3}, we find {3,2,1} at the last position. So, we have to return the topmost permutation.

// | Method             | Time Complexity | Space Complexity | Uses STL?                 | Notes                                                                                            |
// | ------------------ | --------------- | ---------------- | ------------------------  | ------------------------------------------------------------------------------------------------ |
// | `nextPermutation1` | O(N)            | O(1)             | ✅ `next_permutation` STL | Uses built-in function; simple and optimized.                                                    |
// | `nextPermutation2` | O(N)            | O(1)             | ❌                        | Manual implementation using standard steps: find pivot, swap, reverse suffix. Handles all cases. |

#include <bits/stdc++.h>
using namespace std;

class MySolution
{
public:
    void nextPermutation1(vector<int> &arr, int n)
    {
        next_permutation(arr.begin(), arr.end());
    }
    void nextPermutation2(vector<int> &arr, int n)
    {
        int i = -1;
        for (i = n - 2; i >= 0; i--)
        {
            if (arr[i] < arr[i + 1])
                break;
        }
        if (i == -1)
        {
            reverse(arr.begin(), arr.end());
            return;
        }
        int j = n - 1;
        while (arr[j] <= arr[i])j--;
        swap(arr[j], arr[i]);
        reverse(arr.begin() + i + 1, arr.end());
    }
};

int main()
{
    MySolution *obj = new MySolution;

    int n;
    cout << "Enter array size:" << endl;

    while (true)
    {
        cin >> n;
        if (n > 0)
            break;
        cout << "Invalid size. Re-enter array size: ";
    }

    vector<int> arr(n);
    cout << "Enter array elements:" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    obj->nextPermutation2(arr, n);
    for (const int &i : arr)
        cout << i << " ";
    cout << endl;

    delete obj;
    return 0;
}