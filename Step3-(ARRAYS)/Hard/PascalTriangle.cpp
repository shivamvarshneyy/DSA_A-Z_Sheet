// Program to generate Pascal's Triangle

// Problem Statement: This problem has 3 variations. They are stated below:

// Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.

// Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.

// Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle.

// In Pascal’s triangle, each number is the sum of the two numbers directly above it as shown in the figure below:


// Examples
// Example 1:
// Input Format: N = 5, r = 5, c = 3
// Result: 6 (for variation 1)
// 1 4 6 4 1 (for variation 2)

//     1 
//    1 1 
//   1 2 1 
//  1 3 3 1 
// 1 4 6 4 1    

// (for variation 3)
// Explanation: There are 5 rows in the output matrix. Each row is formed using the logic of Pascal’s triangle.

// Example 2:
// Input Format: N = 1, r = 1, c = 1
// Result: 1 (for variation 1)
//     1 (for variation 2)
//     1  (for variation 3)
// Explanation: The output matrix has only 1 row.


// | Function                            | Purpose                                                          | Time Complexity                                                                               | Space Complexity                    | Notes                                                                                                              |
// | ----------------------------------- | ---------------------------------------------------------------- | --------------------------------------------------------------------------------------------- | ----------------------------------- | ------------------------------------------------------------------------------------------------------------------ |
// | `pascalTriangle1(int row, int col)` | Computes a single element `C(row, col)`                          | **O(col)** (loop up to `col`)                                                                 | **O(1)**                            | Efficient binomial coefficient formula. In `main` you call it with `(row-1, col-1)` so indexing is 0-based inside. |
// | `pascalTriangle2(int row)`          | Returns the `row`-th row by repeatedly calling `pascalTriangle1` | **O(row²)** (since each element uses `pascalTriangle1` which is O(row), repeated `row` times) | **O(row)** (stores one row)         | Redundant; slower than method 3.                                                                                   |
// | `pascalTriangle3(int row)`          | Returns the `row`-th row using iterative binomial formula        | **O(row)**                                                                                    | **O(row)**                          | Most optimized method for a single row.                                                                            |
// | `pascalTriangle4(int row)`          | Returns first `row` rows of Pascal’s triangle                    | **O(row²)** (sum of O(1 + 2 + … + row) ≈ O(row²))                                             | **O(row²)** (stores whole triangle) | Uses `pascalTriangle3` internally.                                                                                 |


#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    int pascalTriangle1(int row, int col){
        int ans = 1;
        for(int i=0;i<col;i++){
            ans = ans*(row-i)/(i+1);
        }
        return ans;
    }

    vector<int> pascalTriangle2(int row){
        vector<int> ans;
        for(int i=0;i<row;i++){
            ans.emplace_back(pascalTriangle1(row-1, i));
        }
        return ans;
    }

    vector<int> pascalTriangle3(int row){
        vector<int> ans;
        int t = 1;
        ans.emplace_back(1);
        for(int i=1;i<row;i++){
            t = t*(row-i)/i; 
            ans.emplace_back(t);
        }
        return ans;
    }

    vector<vector<int>> pascalTriangle4(int row){
        vector<vector<int>> ans;
        for(int i=1;i<=row;i++){
            ans.emplace_back(pascalTriangle3(i));
        }
        return ans;
    }
};

int main() {
    MySolution* obj = new MySolution;

    int row;
    cout << "Enter row :" << endl;
    
    while (true) {
        cin >> row;
        if (row > 0) break;
        cout << "Invalid size. Re-enter array size: ";
    }

    int col;
    cout << "Enter column :" << endl;
    
    while (true) {
        cin >> col;
        if (col > 0) break;
        cout << "Invalid size. Re-enter array size: ";
    }
    

    int a = obj->pascalTriangle1(row-1, col-1);
    cout<<"The element at row "<<row<<" & column "<<col<<" is: "<<a<<endl;

    
    vector<int> ans = obj->pascalTriangle2(row);
    cout<<"The "<<row<<" row of the pascal triangle is: ";
    for(const int& i:ans)cout<<i<<" ";
    cout<<endl;

    vector<int> ans1 = obj->pascalTriangle3(row);
    cout<<"The "<<row<<" row of the pascal triangle is: ";
    for(const int& i:ans1)cout<<i<<" ";
    cout<<endl;

    vector<vector<int>> ans2 = obj->pascalTriangle4(row);
    cout<<"Pascal Triangle : "<<endl;
    for(const auto& i:ans2){
        for(const auto& j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    delete obj;
    return 0;
}