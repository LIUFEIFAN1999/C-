
//Planeline.h
#ifndef Planeline_h
#define Planeline_h
using namespace std;

//乘客信息
typedef class{
public:
    string name;    //姓名
    string id;      //身份证
    int seat;       //座位号
}Passenger;

//乘客信息链表
typedef class pLNode
{
public:
    Passenger data;
    pLNode *next;
}pLNode, *pLinkList;

//航班信息
typedef class{
public:
    string no;         //航班号
    string from;       //出发地
    string to;         //到达地
    int seats;         //总座位数
    int remaining;     //剩余座位
    pLinkList p;       //乘客链表
}Flight;

//航线链表
typedef class fLNode{
public:
    Flight data;
    fLNode *next;
}fLNode, *fLinkList;

/*飞机航线类*/
class Planeline{
private:
    fLinkList f;         //私有数据成员：航线链表
    void insertPassenger(pLinkList p);              //输入乘客信息
    void showFlightInfo(fLinkList f);               //显示航班信息
    void showPassengerInfo(fLinkList f);            //显示乘客信息
public:
    Planeline();                         //构造函数
    ~Planeline(){free(f);}               //析构函数：释放链表内存
    void addFlight();                    //添加航线
    void deleteFlight();                 //取消航线
    void searchFlight();                 //查询航班
    void reserve();                      //订票
    void refund();                       //退票
    void scanPassenger();                //浏览乘客信息
    void ensureBack(int &i);             //系统退出确认函数
};

#endif /* Planeline_h */
