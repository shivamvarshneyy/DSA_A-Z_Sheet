#include <bits/stdc++.h>
#include "../../Header_File/ReverseNumber.h"
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
    if(obj->isPalindrome(n))cout<<"true";
    else cout<<"false";
    delete obj;
    return 0;
}