#include<bits/stdc++.h>
#include"../../Header_File/CountDigit.h"
using namespace std;
class MySolution{
public:
    int countDigit(int n){
        CountDigit obj;
        return obj.countDigit(n);
    }
};
int main(){
    MySolution* obj = new MySolution;
    int n;
    cout<<"Enter Number:"<<endl;
    cin>>n;
    int res = obj -> countDigit(n);
    cout<<res<<endl;
    delete obj;
    return 0;
}
