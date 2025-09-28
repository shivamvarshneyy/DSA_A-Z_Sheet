#include <bits/stdc++.h>
#include "ReverseNumber.h"
using namespace std;
class MySolution
{
public:
    bool isPalindrome(int n)
    {
        ReverseNumber obj;
        return n == obj.reverse(n);
    }
};
int main()
{
    MySolution *obj = new MySolution;
    int n;
    cout << "Enter a Number" << endl;
    cin >> n;
    bool res = obj->isPalindrome(n);
    cout << res << endl;
    delete obj;
    return 0;
}