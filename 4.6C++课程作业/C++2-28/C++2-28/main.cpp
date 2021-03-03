//  2-28
#include <iostream>
using namespace std;
int main(){
    char menu;
    cout<<"Menu: A(dd) D(elete) S(ort) Q(uit), Select one:";
    cin>>menu;
    while(true){
        switch(menu){
            case 'A':cout<<"The data have been added."<<endl;break;
            case 'D':cout<<"The data have been deleted."<<endl;break;
            case 'S':cout<<"The data have been sorted."<<endl;break;
            case 'Q':break;
            default:cout<<"Please enter A D S Q"<<endl;break;
        }
        if(menu=='Q')
            break;
        else{
            cout<<"Menu: A(dd) D(elete) S(ort) Q(uit), Select one:";
            cin>>menu;
        }
    }
    return 0;
}
/*
int main() {
    char menu;
    cout<<"Menu: A(dd) D(elete) S(ort) Q(uit), Select one:";
    cin>>menu;
    while(true)
    {
        if(menu=='A')
            cout<<"The data have been added."<<endl;
        else
            if(menu=='D')
                cout<<"The data have been deleted."<<endl;
            else
                if(menu=='S')
                    cout<<"The data have been sorted."<<endl;
                else
                    if(menu=='Q')
                        break;
                    else
                        cout<<"Please enter A D S Q"<<endl;
        cout<<"Menu: A(dd) D(elete) S(ort) Q(uit), Select one:";
        cin>>menu;
        continue;
    }
    return 0;
}
*/
