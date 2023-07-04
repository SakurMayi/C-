#include <iostream>
#include <string>
using namespace std;

int main() {
	/*对组创建
	* 功能：成对出现的数据，利用对组可以返回两个数据
	* 2种创建方式：
	* pair<type,type>p(value1, value2);
	* pair<type,type> p = make_pair(value1,value2);
	*/
	pair<string, int> p("Tom",20);
	cout << "姓名：" << p.first << "年龄：" << p.second << endl;


	pair<string, int> p1 = make_pair("Jerry", 18);
	cout << "姓名：" << p1.first << "年龄：" << p1.second << endl;

}
