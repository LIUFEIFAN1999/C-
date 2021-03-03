
//  Planeline.cpp
#include <iostream>
#include <string>
#include <iomanip>
#include "Planeline.h"

//构造函数实现
Planeline::Planeline(){
    f=(fLNode *)malloc(sizeof(fLNode));    //初始化链表
    f->next=NULL;
}

//添加航线函数实现
void Planeline::addFlight(){
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"                        *****航线添加服务*****                    "<<"\n\n";
    cout<<"请输入您要添加航班的数量：";
    int i=0;
    cin>>i;
    fLinkList f1,f2;
    f1=f;
    while(f1->next!=NULL)    //尾插法
        f1=f1->next;
    for(int j=1; j<=i; j++){
        cout<<endl;
        cout<<"请输入第"<<j<<"列航班的信息"<<endl;
        f2=(fLNode *)malloc(sizeof(fLNode));
        cout<<"请设定航班号：";
        cin>>(f2->data.no);
        cout<<"请设定起飞地：";
        cin>>(f2->data.from);
        cout<<"请设定目的地：";
        cin>>f2->data.to;
        cout<<"请设定总座位数：";
        cin>>f2->data.seats;
        f2->data.remaining=f2->data.seats;
        //初始化航班的乘客链表
        f2->data.p=(pLNode *)malloc(sizeof(pLNode));
        f2->data.p->next=NULL;
        //节点插入
        f2->next=f1->next;
        f1->next=f2;
        f1=f1->next;
        cout<<"添加航班成功！"<<endl;
    }
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"----------------------------------------------------------------"<<"\n\n";
}


//取消航线函数实现
void Planeline::deleteFlight(){
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"                        *****航班取消服务*****                    "<<"\n\n";
    string NO;
    cout<<"请输入要取消航班的航班号：";
    cin>>NO;
    fLinkList f1;
    f1=f;
    while(f1->next!=NULL&&f1->next->data.no!=NO)       //通过航班号查找
    {
        f1=f1->next;
    }
    if(f1->next==NULL)                                //未查找到
        cout<<"你输入的航班号有误,取消航班失败！"<<endl;
    else{                                             //查找成功
        cout<<left<<setw(14)<<"航班号"<<setw(16)<<"出发地"<<setw(16)<<"到达地"<<setw(15)<<"总座位数"<<setw(14)<<"余票数"<<endl;
        showFlightInfo(f1->next);                     //显示该航班信息
        int i;
        cout<<"你确定要取消此航班吗？（1：是/0：否）：";
        cin>>i;
        if(i==1){            //删除节点
            fLinkList f2;
            f2=f1->next;
            f1->next=f2->next;
            free(f2);
            cout<<"取消航班"<<NO<<"成功!"<<endl;
        }
    }
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"----------------------------------------------------------------"<<"\n\n";
}

//查询航班函数实现
void Planeline::searchFlight(){
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"                        *****航班查询服务*****                    "<<"\n\n";
    fLinkList f1;
    int i=0;
    string destination;
    cout<<"请输入您的目的地： ";
    cin>>destination;
    f1=f;
    cout<<"\n"<<"***航班信息***"<<endl;
    cout<<left<<setw(14)<<"航班号"<<setw(16)<<"出发地"<<setw(16)<<"到达地"<<setw(15)<<"总座位数"<<setw(14)<<"余票数"<<endl;
    while(f1->next!=NULL){
        f1=f1->next;
        if(f1->data.to==destination){
            showFlightInfo(f1);            //显示目的地相同的航班信息
            i++;
        }
    }
    if(i==0)        //目的地符合要求的航班数为0
        cout<<"无查询结果！" <<endl;
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"----------------------------------------------------------------"<<"\n\n";
}

//订票函数实现
void Planeline::reserve(){
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"                        *****航班订票服务*****                    "<<"\n\n";
    fLinkList f1;
    f1=f;
    string NO;
    cout<<"请输入你要订票的航班号：";
    cin>>NO;
    cout<<"请输入你要预定的机票的数量：";
    int number;
    cin>>number;
    //通过航班号查找
    do{
        f1=f1->next;
    }while(f1!=NULL && f1->data.no!=NO);
    if(f1==NULL)          //未找到航班号
        cout<<"您输入的航班号有误，订票失败"<<endl;
    else if(f1->data.remaining>=number){     //查找成功，并且余票充足
        for(int j=1; j<=number; j++){
            cout<<"\n"<<"请输入第"<<j<<"位乘客的信息"<<endl;
            insertPassenger(f1->data.p);    //录入乘客信息
            f1->data.remaining --;          //余票数减1
            cout<<"订票成功！"<<endl;
        }
    }
    else
        cout<<"该航班余票不足，余票还剩"<<f1->data.remaining<<"张"<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"----------------------------------------------------------------"<<"\n\n";
}

//退票函数实现
void Planeline::refund(){
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"                        *****航班退票服务*****                    "<<"\n\n";
    string NO;
    string NAME;
    cout<<"请输入要退票的航班号：";
    cin>>NO;
    fLinkList f1;
    f1=f->next;
    while(f1!=NULL && f1->data.no!=NO)      //通过航班号查找
        f1=f1->next;
    if(f1==NULL)                            //未找到航班号
        cout<<"您输入的航班号有误，请重新确认后重试！"<<endl;
    else{                                   //成功找到航班
        cout<<"请输入需要退票的乘客姓名：";
        cin>>NAME;
        pLinkList p1;
        p1=f1->data.p;
        while(p1->next!=NULL && p1->next->data.name!=NAME)   //通过姓名查找
            p1=p1->next;
        if(p1->next==NULL)                                   //未找到姓名
            cout<<"您不在该航班乘客名单中，请重新确认后重试！"<<endl;
        else{                                               //查找成功
            int i;
            cout<<"你确定要退票吗？（1：是/0：否）：";
            cin>>i;
            if(i==1){
                //删除乘客链表节点
                pLinkList p2;
                p2=p1->next;
                p1->next=p2->next;
                free(p2);
                cout<<"退票成功！"<<endl;
                f1->data.remaining++;
            }
        }
    }
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"----------------------------------------------------------------"<<"\n\n";
}

//乘客信息浏览函数实现
void Planeline::scanPassenger(){
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"                       *****乘客信息浏览服务*****                  "<<"\n\n";
    string NO;
    cout<<"请输入你想要查询乘客名单中乘客所在的航班号：";
    cin>>NO;
    fLinkList f1;
    f1=f;
    //通过航班号查找
    do{
        f1=f1->next;
    }while(f1!=NULL && f1->data.no!=NO);
    //未找到航班号
    if(f1==NULL)
        cout<<"航班输入有误，查询失败"<<endl;
    //查找成功
    else
        showPassengerInfo(f1);       //显示该航班所有乘客
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"----------------------------------------------------------------"<<"\n\n";
}

//输入乘客信息函数实现
void Planeline::insertPassenger(pLinkList p){
    pLinkList p1,p2;
    p2=(pLNode *)malloc(sizeof(pLNode));    //初始化
    cout<<"请输入乘客姓名：";
    cin>>p2->data.name;
    cout<<"请输入乘客身份证号：";
    cin>>p2->data.id;
    p1=p;
    if(p1->next==NULL){        //第一位乘客
        p2->data.seat=1;
        p2->next=p1->next;
        p1->next=p2;
    }
    else{
        //乘客座位号安排
        int i=1;      //座位号初始化
        /*座位号按顺序从1开始安排，座位号最大值应与航班总票数一致
         *为了避免座位号超出最大值，乘客退票后该座位号需再次使用
         *遍历乘客链表，若座位号i尚未使用，则该乘客的座位号为i
         *若座位号i已被使用，则座位号+1继续遍历乘客链表
         */
        pLinkList p3;
        p3=p->next;
        while(p3!=NULL){
            p3=p->next;
            //遍历链表座位号
            while(p3!=NULL && p3->data.seat!=i)
                p3=p3->next;
            if(p3==NULL)      //无相同座位号
                p2->data.seat=i;
            else              //有相同座位号
                i++;
        }
        //按照字母顺序排列（从a-Z）
        while(p1->next!=NULL && strcmp(p2->data.name.c_str(), p1->next->data.name.c_str())>0)
            p1=p1->next;
        //乘客链表节点插入
        p2->next=p1->next;
        p1->next=p2;
    }
    cout<<left<<setw(14)<<"姓名"<<setw(16)<<"身份证号"<<"座位号"<<endl;
    cout<<left<<setw(12)<<p2->data.name<<setw(10)<<p2->data.id<<setw(10)<<p2->data.seat<<endl;
}

//展示航班信息函数实现
void Planeline::showFlightInfo(fLinkList f){
    cout<<left<<setw(10)<<f->data.no<<setw(12)<<f->data.from<<setw(12)<<f->data.to<<setw(10)<<f->data.seats<<setw(10)<<f->data.remaining<<endl;
}

//显示乘客信息函数实现
void Planeline::showPassengerInfo(fLinkList f){
    pLinkList p1;
    p1=f->data.p->next;
    if(p1==NULL)
        cout<<"该航班尚无任何乘客！"<<endl;
    else{
        cout<<"\n"<<"***乘客名单***"<<"\n\n";
        cout<<left<<setw(14)<<"姓名"<<setw(16)<<"身份证号"<<"座位号"<<endl;
        while(p1!=NULL){
            cout<<left<<setw(12)<<p1->data.name<<setw(10)<<p1->data.id<<setw(10)<<p1->data.seat<<endl;
            p1=p1->next;
        }
    }
}

//确定系统退出函数实现
void Planeline::ensureBack(int &i){
    cout<<"你确定要退出系统吗？（0：是/1:否）：";
    cin>>i;
    if(i==0)
        cout<<"退出成功！"<<endl;
}

