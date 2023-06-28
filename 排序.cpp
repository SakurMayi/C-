#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <ctime>
using namespace std;
/*常用排序算法
* 1. sort   对容器内排序
* 2. random_shuffle 洗牌，指定范围内随机调整次序
* 3. merge 容器元素合并，并存储到另一容器中
* 4. reverse 反转指定范围内的元素
*/

class Mycompare{
public:
	bool operator()(int v1,int v2) {
		return v1 > v2;
	}
};
void Printf(int val) {
	cout << val << " ";
}
/*sort(begin, end, elem)
按值查找元素，找不到返回结束迭代器位置，否则返回指定位置迭代器
begin 开始迭代器
end 结束迭代器
elem 谓词
*/
void test1() {
	vector<int>vec;
	vec.push_back(10);
	vec.push_back(5);
	vec.push_back(20);
	vec.push_back(15);
	//默认是升序
	sort(vec.begin(), vec.end());
	for_each(vec.begin(), vec.end(), Printf);
	cout << endl;
	//降序
	//sort(vec.begin(), vec.end(), greater<int>());
	/*用仿函数*/
	sort(vec.begin(), vec.end(), Mycompare());
	for_each(vec.begin(), vec.end(), Printf);
	cout << endl;
	cout << endl;
}
void test2(){
	srand((unsigned int)time(NULL));//生产随机种子，随着时间变化，排序也变化
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), Printf);
	cout << endl;
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), Printf);
	cout << endl;
	cout << endl;
}
/*merge
* merge(beg1,end1,beg2,end2,dest)
* 2个容器必须有序
* beg1 容器一开始迭代器
* beg2 容器二开始迭代器
* end1 容器一结束迭代器
* end2 容器二结束迭代器
* dest 目标容器开始迭代器
*/
void test3(){
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	for (int i = 10; i < 20; i++)
	{
		v2.push_back(i);
	}
	for_each(v1.begin(), v1.end(), Printf);
	cout << endl;
	for_each(v2.begin(), v2.end(), Printf);
	cout << endl;
	vector<int>v3;
	v3.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), v3.end(), Printf);
	cout << endl;
	cout << endl;
}
/*reverse
*/
void test4(){
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	cout << "反转前：";
	for_each(v.begin(),v.end(),Printf);
	cout << endl;
	cout << "反转后：";
	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), Printf);
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	return 0;
}
