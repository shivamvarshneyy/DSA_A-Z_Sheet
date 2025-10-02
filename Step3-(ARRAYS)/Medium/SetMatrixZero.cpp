// Set Matrix Zero

// Problem Statement: Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix.

// Examples

// Examples 1:
// Input: matrix=[[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]
// Explanation: Since matrix[2][2]=0.Therfore the 2nd column and 2nd row wil be set to 0.

// Examples 2:
// Input: matrix=[[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output:[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
// Explanation:Since matrix[0][0]=0 and matrix[0][3]=0. Therefore 1st row, 1st column and 4th column will be set to 0


// | Approach           | Idea                                      | Time Complexity               | Space Complexity                     |
// | ------------------ | ----------------------------------------- | ----------------------------- | ------------------------------------ |
// | **setMatrixzero1** | Mark with `-1` first, then convert to `0` | `O(m*n * (m+n))` (worst case) | `O(1)` (ignoring recursion overhead) |
// | **setMatrixzero2** | Use extra arrays `row[]` & `col[]`        | `O(m*n)`                      | `O(m+n)`                             |
// | **setMatrixzero3** | Use 1st row & col as markers              | `O(m*n)`                      | `O(1)` (optimal)                     |


#include <bits/stdc++.h>
using namespace std;

class MySolution
{
private:
    void makeRowZero(vector<vector<int>>& arr, int row, int col)
    {
        for (int i = 0; i < col; i++)
        {
            if (arr[row][i] != 0)
                arr[row][i] = -1;
        }
    }
    void makeColZero(vector<vector<int>>& arr, int col, int row)
    {
        for (int i = 0; i < row; i++)
        {
            if (arr[i][col] != 0)
                arr[i][col] = -1;
        }
    }

public:
    void setMatrixzero1(vector<vector<int>>& arr, int m, int n)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == 0)
                {
                    makeRowZero(arr, i, n);
                    makeColZero(arr, j, m);
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == -1)
                {
                    arr[i][j] = 0;
                }
            }
        }
    }

    void setMatrixzero2(vector<vector<int>>& arr, int m, int n)
    {
        vector<int> row(m);
        vector<int> col(n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == 0)
                {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (row[i] == 1 || col[j] == 1)
                {
                    arr[i][j] = 0;
                }
            }
        }
    }

    void setMatrixzero3(vector<vector<int>>& arr, int m, int n)
    {
        int col0 = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == 0)
                {
                    arr[i][0] = 0;
                    if(j==0)col0 = 0;
                    else arr[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (arr[0][j] == 0 || arr[i][0] == 0)
                {
                    arr[i][j] = 0;
                }
            }
        }
        if(arr[0][0] == 0){
            for(int j=0;j<n;j++)arr[0][j] = 0;
        }
        if(col0 == 0){
            for(int i=0;i<m;i++)arr[i][0] = 0;
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

    obj->setMatrixzero3(arr, m, n);
    cout<<"Matrix after Setting Zero : "<<endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    delete obj;
    return 0;
}