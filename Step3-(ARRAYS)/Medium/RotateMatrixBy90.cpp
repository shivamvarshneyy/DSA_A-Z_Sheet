// Rotate Image by 90 degree

// Problem Statement: Given a matrix, your task is to rotate the matrix 90 degrees clockwise.

// Note: Rotate matrix 90 degrees anticlockwise

// Examples
// Example 1:

// Input: [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]
// Explanation: Rotate the matrix simply by 90 degree clockwise and return the matrix.

// Example 2:
// Input: [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
// Output:[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
// Explanation: Rotate the matrix simply by 90 degree clockwise and return the matrix

// | Method          | Works for Rectangular? | Time Complexity | Space Complexity | Notes                                                                             |
// | --------------- | ---------------------- | --------------- | ---------------- | --------------------------------------------------------------------------------- |
// | `rotateMatrix1` | ✅ Yes                  | O(m×n)          | O(m×n)           | Creates a new matrix; handles both square and rectangular matrices.               |
// | `rotateMatrix2` | ❌ No                   | O(m²)           | O(1)             | In-place; only works for square matrices because it uses transpose + row reverse. |


#include <bits/stdc++.h>
using namespace std;

class MySolution
{
public:
    vector<vector<int>> rotateMatrix1(vector<vector<int>> &arr, int m, int n)
    {
        vector<vector<int>> nums(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                nums[j][m-1-i] = arr[i][j];
            }
        }
        return nums;
    }

    void rotateMatrix2(vector<vector<int>> &arr, int m, int n)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = i; j < n; j++)
            {
                swap(arr[i][j], arr[j][i]);
            }
        }
        for(int i = 0; i < m; i++){
            reverse(arr[i].begin(), arr[i].end());
        }
    }
};

int main()
{
    MySolution *obj = new MySolution;

    int m;
    cout << "Enter row size:" << endl;

    while (true)
    {
        cin >> m;
        if (m > 0)
            break;
        cout << "Invalid size. Re-enter row size: ";
    }

    int n;
    cout << "Enter col size:" << endl;

    while (true)
    {
        cin >> n;
        if (n > 0)
            break;
        cout << "Invalid size. Re-enter col size: ";
    }

    vector<vector<int>> arr(m, vector<int>(n));
    cout << "Enter array elements:" << endl;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    vector<vector<int>> nums = obj->rotateMatrix1(arr, m, n);

    cout << "Array after rotating 90° clockwise : " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }

    obj->rotateMatrix2(arr, m, m);

    cout << "Array after rotating 90° clockwise : " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    delete obj;
    return 0;
}