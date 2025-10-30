#include <bits/stdc++.h>
#include "../../Header_File/CubeRoot.h"
using namespace std;

int main() {
    MySolution obj;

    int n;
    cout << "Enter a number:" << endl;
    
    cin>>n;

    double a = CubeRoot::cubeRoot(n);
    cout<<"Cube root of "<<n<<" is : "<<a<<endl;

    return 0;
}