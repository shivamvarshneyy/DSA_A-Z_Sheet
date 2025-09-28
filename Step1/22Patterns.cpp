#include <bits/stdc++.h>
using namespace std;

class MySolution
{
public:
    void pattern1(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }
    void pattern2(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }
    void pattern3(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cout << j + 1;
            }
            cout << endl;
        }
    }
    void pattern4(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cout << i + 1;
            }
            cout << endl;
        }
    }
    void pattern5(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= n - i - 1; j++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }
    void pattern6(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= n - i - 1; j++)
            {
                cout << j + 1;
            }
            cout << endl;
        }
    }
    void pattern7(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                cout << " ";
            }
            for (int j = 0; j <= 2 * i; j++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }
    void pattern8(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                cout << " ";
            }
            for (int j = 2 * (n - i) - 1; j > 0; j--)
            {
                cout << "*";
            }
            for (int j = 0; j < i; j++)
            {
                cout << " ";
            }
            cout << endl;
        }
    }
    void pattern9(int n)
    {
        pattern7(n);
        pattern8(n);
    }
    void pattern10(int n)
    {
        int star;
        for (int i = 0; i < 2 * n - 1; i++)
        {
            if (i <= 4)
                star = i;
            else
                star = 2 * n - i - 2;
            for (int j = 0; j <= star; j++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }
    void pattern11(int n)
    {
        int r;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
                r = 0;
            else
                r = 1;
            for (int j = 0; j <= i; j++)
            {
                r = !(r);
                cout << r << " ";
            }
            cout << endl;
        }
    }
    void pattern12(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cout << j + 1;
            }
            for (int j = 0; j < 2 * (n - i - 1); j++)
            {
                cout << " ";
            }
            for (int j = i; j >= 0; j--)
            {
                cout << j + 1;
            }
            cout << endl;
        }
    }
    void pattern13(int n)
    {
        int res = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cout << res++ << " ";
            }
            cout << endl;
        }
    }
    void pattern14(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (char j = 'A'; j <= 'A' + i; j++)
            {
                cout << j;
            }
            cout << endl;
        }
    }
    void pattern15(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (char j = 'A'; j <= 'A' + n - i - 1; j++)
            {
                cout << j;
            }
            cout << endl;
        }
    }
    void pattern16(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                char res = 'A' + i;
                cout << res;
            }
            cout << endl;
        }
    }
    void pattern17(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                cout << " ";
            }
            for (char j = 'A'; j <= 'A' + i; j++)
            {
                cout << j;
            }
            for (char j = 'A' + i - 1; j >= 'A'; j--)
            {
                cout << j;
            }
            cout << endl;
        }
    }
    void pattern18(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (char j = 'E' - i; j <= 'E'; j++)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
    void pattern19(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= n - i - 1; j++)
            {
                cout << "*";
            }
            for (int j = 0; j < 2 * i; j++)
            {
                cout << " ";
            }
            for (int j = 0; j <= n - i - 1; j++)
            {
                cout << "*";
            }
            cout << endl;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cout << "*";
            }
            for (int j = 0; j < 2 * (n - i - 1); j++)
            {
                cout << " ";
            }
            for (int j = i; j >= 0; j--)
            {
                cout << "*";
            }
            cout << endl;
        }
    }
    void pattern20(int n)
    {
        int star;
        for (int i = 0; i < 2 * n - 1; i++)
        {
            if (i <= 4)
                star = i;
            else
                star = 2 * n - i - 2;
            for (int j = 0; j <= star; j++)
            {
                cout << "*";
            }
            for (int j = 0; j < 2 * (n - star - 1); j++)
            {
                cout << " ";
            }
            for (int j = 0; j <= star; j++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }
    void pattern21(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
    void pattern22(int n){
        int top = 0;
        int bottom = n;
        int left = 0;
        int right = n;
        for(int i = 0; i < 2*n-1; i++){
            for(int j = 0; j < 2*n-1; j++){
                cout<< n - min(min(i, j), min(2*n-2-i, 2*n-2-j))<<" ";
            }
            cout<<endl;
        }

    }
};

int main()
{
    MySolution *obj = new MySolution();
    int n;
    cout << "Enter number\n";
    cin >> n;
    obj->pattern22(n);
    return 0;
}

