// Stock Buy And Sell

// Problem Statement: You are given an array of prices where prices[i] is the price of a given stock on an ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// Examples

// Example 1:
// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and
// sell on day 5 (price = 6), profit = 6-1 = 5.

// Note: That buying on day 2 and selling on day 1
// is not allowed because you must buy before
// you sell.

// Example 2:
// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are
// done and the max profit = 0.

// | Approach / Function             | Time Complexity (Best) | Time Complexity (Average) | Time Complexity (Worst) | Space Complexity |
// | ------------------------------- | ---------------------- | ------------------------- | ----------------------- | ---------------- |
// | **buySellStock1 (Brute Force)** | O(n²)                  | O(n²)                     | O(n²)                   | O(1)             |
// | **buySellStock2 (Optimal)**     | O(n)                   | O(n)                      | O(n)                    | O(1)             |

#include <bits/stdc++.h>
using namespace std;

class MySolution
{
public:
    int buySellStock1(vector<int> &arr, int n)
    {
        int maxProfit = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] > arr[i])
                    maxProfit = max(maxProfit, arr[j] - arr[i]);
            }
        }
        return maxProfit;
    }
    int buySellStock2(vector<int> &arr, int n)
    {
        int maxProfit = 0;
        int minimumPriceToBuy = arr[0];
        for (const int &i : arr)
        {
            maxProfit = max(maxProfit, i - minimumPriceToBuy);
            minimumPriceToBuy = min(minimumPriceToBuy, i);
        }
        return maxProfit;
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

    int a = obj->buySellStock1(arr, n);
    cout << "Maximum profit will be: " << a << endl;

    int b = obj->buySellStock2(arr, n);
    cout << "Maximum profit will be: " << b << endl;

    delete obj;
    return 0;
}