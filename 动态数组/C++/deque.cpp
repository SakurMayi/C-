#include <iostream>
#include <string>
#include <deque>
using namespace std;
void PrintfQuede(deque<int>d) {
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
int main() {
	/*功能：双端数组 可以头插，头删*/
	/*构造函数
	* deque<T>deq; 默认形式
	* deque(beg,end); [beg.end)区间的元素拷贝给本身
	* deque(n,elem);	n个elem拷贝给本身
	* deque(const deque & dep); 拷贝构造函数
	*/
	deque <int> d1;
	for (int i = 0; i < 10; i++) {
		d1.push_back(i);
	}
	PrintfQuede(d1);

	deque<int>d2(d1.begin(), d1.end());
	PrintfQuede(d2);

	deque<int>d3(10, 100);
	PrintfQuede(d3);

	deque<int>d4(d3); 
	PrintfQuede(d4);
	cout << endl;
	/*赋值操作*/
	//operator = 赋值
	deque <int>d5;
	d5 = d1;
	PrintfQuede(d5);
	// assgin 赋值
	deque <int>d6;
	d6.assign(d1.begin(), d1.end());
	PrintfQuede(d6);
	deque<int>d7;
	d7.assign(10, 100);
	PrintfQuede(d7);
	cout << endl;
	//赋值 deque 与 vecot差不多一样
	/*deque大小操作
	* deque.empty(); 判断容器是否为空
	* deque.size(); 返回容器元素个数
	* deque.resize(num); 重新定义大小与vector一样
	* deque.resize(num,elem); 与vector一样
	*/
	PrintfQuede(d1);
	if (d1.empty()) {
		cout << "容器为空：" << endl;
	}
	else cout << "容器不为空：" << endl;
	cout << "d1的大小为：" << d1.size() << endl;
	d1.resize(12);
	PrintfQuede(d1);
	cout << "d1的大小为：" << d1.size() << endl;
	d1.resize(15, 2);
	PrintfQuede(d1);
	cout << "d1的大小为：" << d1.size() << endl;
	d1.resize(5);
	PrintfQuede(d1);
	cout << "d1的大小为：" << d1.size() << endl;
	cout << endl;
	/*插入和删除
	* 两端插入和删除
	* 
	* push_back(e); 尾插
	* push_front(e); 头插
	* pop_back(e); 尾删
	* pop_front(e); 头删
	* 
	* 指定位置删除和插入
	* 
	* insert(pos,e); pos位置插入e，返回新数据位置
	* insert(pos,n,elem); pos位置插入n个e，无返回值
	* insert(pos,beg,end); pos位子插入[beg,end)区间的数据，无返回值
	* clear(); 清空容器所有数据
	* erase(ben,end) 删除[beg,end)区间数据，返回下一个数据位置
	* erase(pos) // 删除pos位置数据，返回下一个数据位置
	*/
	//插入
	deque<int>de1;
	de1.push_back(10);
	de1.push_back(20);
	PrintfQuede(de1);
	de1.push_front(100);
	de1.push_front(200);
	PrintfQuede(de1);
	de1.pop_back();
	PrintfQuede(de1);
	de1.pop_front();
	PrintfQuede(de1);
	de1.insert(de1.begin(), 1000);
	PrintfQuede(de1);
	de1.insert(de1.begin(), 2, 10000);
	PrintfQuede(de1);
	de1.insert(de1.end(), 200);
	PrintfQuede(de1);
	de1.insert(de1.begin(), d1.begin(), d1.end());
	PrintfQuede(de1);
	//删除
	deque<int>::iterator it = de1.begin();
	it++;
	de1.erase(it);
	PrintfQuede(de1);
	de1.erase(de1.begin(),de1.end()-4);
	PrintfQuede(de1);
	de1.clear();
	PrintfQuede(de1);
	cout << endl;
	/*数据存取
	* at()  返回相对应的索引的元素
	* operator[] 返回相对应的索引的元素
	* front() 返回第一个元素
	* back() 返回最后一个元素
	*/
	for (int i = 0; i < d1.size(); i++) {
		cout << d1[i] << " ";
	}
	cout << endl;
	cout << d1.at(2) << endl;
	cout << d1.front() << endl;
	cout << d1.back() << endl;
}
