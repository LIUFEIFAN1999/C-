//  2-26
#include <iostream>
using namespace std;
int main() {
    char isRain;
    cout<<"Is it raining? (Y for Yes and N for No):";
    cin>>isRain;
    if(isRain=='Y')
        cout<<"It is raining."<<endl;
    else if(isRain=='N')
        cout<<"It is not raining."<<endl;
    while(isRain!='Y'&&isRain!='N')
    {
        cout<<"Is it raining? (Y for Yes and N for No):";
        cin>>isRain;
        if(isRain=='Y')
            cout<<"It is raining."<<endl;
        else if (isRain=='N')
            cout<<"It is not raining."<<endl;
    }
    return 0;
}
