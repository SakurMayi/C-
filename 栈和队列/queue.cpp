#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Person {
public:
	string name;
	int age;
	Person(string name, int age) {
		this->age = age;
		this->name = name;
	}
};

int main() {
	/*队列
	* 概念：先进先出的数据结构，2个出口
	* 队列容器允许一端进入另一端出
	* 只有队头队尾可以被外界访问，不能遍历
	*/

	/*构造函数*/
	queue<Person>q;
	Person p1("孙悟空", 1000);
	Person p2("唐僧", 50);
	Person p3("猪八戒", 200);
	Person p4("沙悟净", 150);
	q.push(p1);//队尾添加元素
	q.push(p2);
	q.push(p3);
	q.push(p4);
	cout << "队列大小：" << q.size() << endl;
	while (!q.empty())
	{
		// 
		cout << "队头元素 -- 姓名：" << q.front().name << "年龄：" << q.front().age << endl;//返回第一个元素
		cout << "队尾元素 -- 姓名：" << q.back().name << "年龄：" << q.back().age << endl;//返回最后一个元素
		q.pop();//队头移除第一个元素
	}
	cout << "队列大小：" << q.size();
}
