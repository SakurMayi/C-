#include <iostream>
#include <string>
#include <stack>
using namespace std;
void PrintStack() {

}
int main() {
	/*
	概念：stack是一个先进后出的数据结构，只有一个出口
	* 栈中只有顶端元素可以被外界使用，因此栈不允许有遍历行为
	* 入栈 push
	* 出栈 pop
	* 
	接口：
	* 构造函数：
	* stack<T> stk; 默认构造形式
	* stack(const stack &stk); 拷贝构造形式
	* 赋值操作：
	* stack & operator = (const stack & stk);
	* 数据存取：
	* push(elem);向栈顶添加元素
	* pop();移除栈顶元素
	* top();返回栈顶元素
	* 
	* 大小操作：
	* empty();判断是否空栈
	* size();栈的大小
	*/
	stack<int> stk;
	//入栈
	stk.push(10);
	stk.push(20);
	stk.push(30);
	stk.push(40);
	cout << "栈的大小：" << stk.size() << endl;
	while (!stk.empty()) {
		//查看栈顶元素
		cout << "栈顶元素为：" << stk.top() << endl;
		//出栈
		stk.pop();
	}
	cout << "栈的大小：" << stk.size() << endl;
	return 0;
}
