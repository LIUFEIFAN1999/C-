//2-34
#include <iostream>
using namespace std;
int main() {
    int i=1,j,k;
    j=5;
    for(k=1;k<=3;k++)
    {
        i*=j;
        j--;
    }
    int m=1,n,s;
    for(n=3;n>0;n--)
    {
        m*=n;
    }
    s=i/m;
    cout<<"There are balls of five colors, so there are "<<s<<" different ways to select three balls of different colors."<<endl;
    return 0;
}
