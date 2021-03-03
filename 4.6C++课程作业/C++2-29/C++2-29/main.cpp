//2-29
#include <iostream>
using namespace std;
int main(){
    int i,j,m,n;
    cout<<"The prime numbers of 1-100:"<<endl;
    for(i=2;i<=100;i++)
    {
        m=1;
        n=i/2;
        for(j=2;j<=n;j++)
        {
            if(i%j==0)
            {
                m=0;
                break;
            }
        }
        if(m)
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
/*int main(){
    int i=2,j,m,n;
    cout<<"The prime numbers of 1-100:"<<endl;
    do{
        m=1;
        n=i/2;
        j=2;
        while(j<=n)
        {
            if(i%j==0)
            {
                m=0;
                break;
            }
            j++;
        }
        if(m)
            cout<<i<<" ";
        i++;
    }while(i<=100);
    cout<<endl;
    return 0;
}
int main() {
    int i=2,j,m,n;
    cout<<"The prime numbers of 1-100:"<<endl;
    while(i<=100){
        m=1;
        n=i/2;
        j=2;
        while(j<=n)
        {
            if(i%j==0)
            {
                m=0;
                break;
            }
            j++;
        }
        if(m)
            cout<<i<<" ";
        i++;
    }
    cout<<endl;
    return 0;
}*/
