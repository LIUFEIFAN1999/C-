//  2020 C++大作业
//  Created by Liu Feifan on 2020/5/21.

#include <iostream>
#include "Planeline.h"

int main() {
    Planeline plane;
    cout<<"欢迎进入飞机订票系统！"<<"\n\n";
    //飞机订票系统功能展示
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"                     *****航班售票系统*****                       "<<endl;
    cout<<"                           1.增加航班                            "<<endl;
    cout<<"                           2.取消航班                            "<<endl;
    cout<<"                           3.航班信息查询                         "<<endl;
    cout<<"                           4.订票服务                            "<<endl;
    cout<<"                           5.退票服务                            "<<endl;
    cout<<"                           6.乘客信息查询                         "<<endl;
    cout<<"                           7.退出                               "<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"\n\n";
    //s为功能选择变量，i为控制循环的变量
    int s,i=1;
    while(i){
        cout<<"请选择您需要的服务：";
        cin>>s;
        switch(s){
            case 1: plane.addFlight();break;
            case 2: plane.deleteFlight();break;
            case 3: plane.searchFlight();break;
            case 4: plane.reserve();break;
            case 5: plane.refund();break;
            case 6: plane.scanPassenger();break;
            case 7: plane.ensureBack(i);break;
            default: cout<<"选择失败，请重新选择"<<endl;break;
        }
    }
    return 0;
}
