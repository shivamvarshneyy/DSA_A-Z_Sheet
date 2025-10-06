// Finding Sqrt of a number using Binary Search

// Problem Statement: You are given a positive integer n. Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of 'sqrt(n)'.

// Note: The question explicitly states that if the given number, n, is not a perfect square, our objective is to find the maximum number, x, such that x squared is less than or equal to n (x*x <= n). In other words, we need to determine the floor value of the square root of n.

// Examples

// Example 1:
// Input Format: n = 36
// Result: 6
// Explanation: 6 is the square root of 36.

// Example 2:
// Input Format: n = 28
// Result: 5
// Explanation: Square root of 28 is approximately 5.292. So, the floor value will be 5.

#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    int squareRoot(int n){
        if(n<=1)return n;
        int s = 0;
        int e = n;
        int mid = s+(e-s)/2;
        
        while(s<=e){
            if(mid == n/mid)return mid;
            else if(mid < n/mid)s = mid+1;
            else e = mid-1;
            mid = s+(e-s)/2;
        }
        return e;
    }
    int squareRoot1(int n){
        if(n<=1)return n;
        int s = 1;
        int e = n/2;
        int ans = 0;
        int mid = s+(e-s)/2;
        
        while(s<=e){
            if(mid == n/mid)return mid;
            else if(mid < n/mid){
                ans = mid;
                s = mid+1;
            }else e = mid-1;
            mid = s+(e-s)/2;
        }
        return e;
    }
    int squareRoot2(int n){
        if(n==0)return 0;
        else if(n<=3)return 1;
        int s = 0;
        int e = n/2;
        int mid = s+(e-s)/2;
        while(s<=e){
            if(mid == n/mid)return mid;
            else if(mid < n/mid)s = mid+1;
            else e = mid-1;
            mid = s+(e-s)/2;
        }    
        return e;
    }
    int squareRoot3(int n) {
        int ans = sqrt(n);
        return ans;
    }   
};

int main() {
    MySolution obj;

    int n;
    cout << "Enter number:" << endl;
    
    while (true) {
        cin >> n;
        if (n > 0) break;
        cout << "Enter Positive Value only. Re-enter number: ";
    }

    int a = obj.squareRoot(n);
    cout<<"Square root of "<<n<<" is : "<<a<<endl;

    int b = obj.squareRoot1(n);
    cout<<"Square root of "<<n<<" is : "<<b<<endl;

    int c = obj.squareRoot(n);
    cout<<"Square root of "<<n<<" is : "<<c<<endl;

    int d = obj.squareRoot(n);
    cout<<"Square root of "<<n<<" is : "<<d<<endl;

    return 0;
}