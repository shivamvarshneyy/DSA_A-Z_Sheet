// Spiral Traversal of Matrix

// Problem Statement: Given a Matrix, print the given matrix in spiral order.

// Examples:

// Example 1:
// Input: Matrix[][] = { 
//                       { 1, 2, 3, 4 },
// 		                 { 5, 6, 7, 8 },
// 		                 { 9, 10, 11, 12 },
// 	                     { 13, 14, 15, 16 }
//                     }

// Outhput: 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.
// Explanation: The output of matrix in spiral form.

// Example 2:
// Input: Matrix[][] = { 
//                       { 1, 2, 3 },
// 	                     { 4, 5, 6 },
// 		                 { 7, 8, 9 }
//                     }
			    
// Output: 1, 2, 3, 6, 9, 8, 7, 4, 5.
// Explanation: The output of matrix in spiral form.

#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    vector<int> spiralMatrix(vector<vector<int>> arr, int m, int n){
        int top = 0;
        int left = 0;
        int right = n-1;
        int bottom = m-1;
        vector<int> ans;
        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++){
                ans.emplace_back(arr[top][i]);
            }
            top++;
            for(int i=top;i<=bottom;i++){
                ans.emplace_back(arr[i][right]);
            }
            right--;
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                ans.emplace_back(arr[bottom][i]);
                }
                bottom--;
            }
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                ans.emplace_back(arr[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};

int main() {
    MySolution* obj = new MySolution;

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

    vector<int> ans = obj->spiralMatrix(arr, m, n);

    cout<<"Matrix after spiral : "<<endl;
    for (int i = 0; i < n*m ; i++)
        cout << ans[i] << " ";
        cout<<endl;

    delete obj;
    return 0;
}