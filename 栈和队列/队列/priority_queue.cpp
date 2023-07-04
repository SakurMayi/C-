#include <iostream>
#include <queue>
#include <functional>
using namespace std;
struct node
{
    int x;
    int y;
    bool operator < (const node & b) const{
        return this->x < b.x;
    }
};

int main()
{
    priority_queue<int>que;//默认大顶堆，值越大优先级越高；小顶堆。值越小，优先级越高
    //也可写为priority_queue<int,vector<int>,less<int>>que;
    /*
    ①que.size() 元素数量
    ②que.push(x) 插入元素x
    ③que.pop()  删除元素
    ④que.top()  访问优先级最高的元素/堆顶元素
    ⑤que.empty() 是否为空
    */
    que.push(5);
    que.push(7);
    que.push(1);
    que.push(-2);
    que.push(10);
    cout << que.size()<<endl;
    while(!que.empty())
    {
        cout << que.top() << " ";
        que.pop();
    }
    cout << endl << que.size() << endl;
    priority_queue<int,vector<int>, greater<int> >que1;//小顶堆
    que1.push(5);
    que1.push(7);
    que1.push(1);
    que1.push(-2);
    que1.push(10);
    cout << que1.size()<<endl;
    while(!que1.empty())
    {
        cout << que1.top() << " ";
        que1.pop();
    }
    cout << endl << que1.size()<< endl;
    priority_queue<node> que2;//自定义顶堆,也可以写为<>中带有3个参数的形式。
    que2.push((node){1,5});
    que2.push((node){2,4});
    que2.push((node){3,3});
    que2.push((node){-1,0});
    cout << que2.size()<<endl;
    while(!que2.empty())
    {
        cout << que2.top().x << " ";
        que2.pop();
    }
    cout << endl << que2.size();
}
