#include <iostream>
#include <string>
#include <vector>
using namespace std;
void PrintVector(vector<int> vec) {
	for ( vector<int>:: iterator it = vec.begin(); it != vec.end(); it ++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
int main() {
	//vector 动态数组，可以动态扩展（不是原数组后面加入而是创建更大的空间拷贝并删除原空间
	vector<int>vec;

	//迭代器
	vec.begin();//第一个元素
	vec.end();//最后一个元素的下一个位置
	vec.rbegin();//第一个元素的前一个位置
	vec.rend();//倒数第一个元素

	/*构造函数
	vector<T> v;
	vector <T> V1 (v.begin(), v.end());           范围前闭后开
	vector<T> V2(n, elem)；            n个elem复制给vector
	vector<T> V3(const vector & vec);	           拷贝构造函数*/
	vector<int>v1(10, 100);
	vector<int>v2(v1.begin(), v1.end());
	vector<int>v3(v1);
	PrintVector(v1);
	PrintVector(v2);
	PrintVector(v3);

	/*赋值操作*/
	cout << endl;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	PrintVector(v1);
	v2 = v1;//①
	PrintVector(v2);
	v3.assign(v1.begin(), v1.end());//②
	PrintVector(v3);
	vector<int>v4;
	v4.assign(10,100);//③
	PrintVector(v4);

	/*容器的容量和大小
	empty(); 判断容器是否为空
	capacity(); 容器的容量
	size(); 容器的中元素个数
	resize(int num); 重新定义容器长度 如果容器变大，则以默认值填充新位置
						如果容器变小，删除超出部分
	resize(int num,elem); 重新指定容器的长度 如果容器变大，则以elem填充新位置
						如果容器变小，删除超出部分
	*/
	cout << endl;
	for (int i = 0; i < 10; i++) {
		vec.push_back(i);
	}
	PrintVector(vec);
	if (vec.empty()) {
		cout << "vec为空" << endl;
	}
	else {
		cout << "vec不为空" << endl;
		cout << "容量大小：" << vec.capacity() << endl;
		cout << "容器长度：" << vec.size() << endl;
	}
	vec.resize(15, 20);//如果比原来长默认是0填充
	PrintVector(vec);
	cout << "容量大小：" << vec.capacity() << endl;
	cout << "容器长度：" << vec.size() << endl;
	vec.resize(5);//比原来短超出部分删除
	PrintVector(vec);
	cout << "容量大小：" << vec.capacity() << endl;
	cout << "容器长度：" << vec.size() << endl;
	
	/*插入和删除
	* push_back() 尾插
	* pop_back() 尾删
	* insert(const_iterate pos, elem)迭代器指向pos位置插入elem
	* insert(const_iterate pos, int count, elem)迭代器指向pos位置插入count个elem
	* erase(const_iterator pos);删除pos处元素
	* erase(const_iterator start,const_iterator end)删除start到end区间中的数
	* clear()清空元素
	*/
	cout << endl;
	v1.clear();//清空
	PrintVector(v1);
	//尾插
	v1.push_back(10);
	v1.push_back(100);
	v1.push_back(1000);
	PrintVector(v1);
	//尾删
	v1.pop_back();
	PrintVector(v1);
	//迭代器插入 参数迭代器
	v1.insert(v1.begin(), 1);
	PrintVector(v1);
	v1.insert(v1.begin(), 2, 100);
	PrintVector(v1);
	//删除 参数也是迭代器
	v1.erase(v1.begin());
	PrintVector(v1);
	v1.erase(v1.begin(), v1.end() - 2);
	PrintVector(v1);
	/*数据存取
	at(int index);返回索引index所指的元素
	operator[i];返回索引i所指的元素
	front();返回第一个元素
	back();返回最后一个元素
	*/
	cout << endl;
	//[]访问
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}cout << endl;
	//at访问
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec.at(i) << " ";
	}cout << endl;
	cout << "第一个元素:" << vec.front();
	cout << " 最后一个元素:" << vec.back() << endl;

	/*容器互换
	* swap(vec)vec于本身元素互换
	*/

	cout << endl;
	cout << "交换前："<<endl;
	PrintVector(vec);
	vector<int>vec1;
	vec1 = v3;
	PrintVector(vec1);
	cout << "交换后：" << endl;
	vec.swap(vec1);
	PrintVector(vec);
	PrintVector(vec1);
	cout << "用于收缩内存" << endl;
	vector<int>vec2(10000000, 10);
	cout << "容器容量：" << vec2.capacity() << endl;
	cout << "容器大小：" << vec2.size() << endl;
	vec2.resize(3);
	cout << "容器容量：" << vec2.capacity() << endl;
	cout << "容器大小：" << vec2.size() << endl;
	vector<int>(vec2).swap(vec2);
	/*vector<int>(vec2)匿名对象
	* .swap(vec2)容器交换
	*/
	cout << "容器容量：" << vec2.capacity() << endl;
	cout << "容器大小：" << vec2.size() << endl;
	/*预留空间
	可以减少vector扩展次数
	reserve(int len) 预留len个元素位置，预留位置不初始化，元素不可访问
	*/
	cout << endl;
	int num = 0;//统计扩展次数
	int* p = NULL;
	vector<int>v5;
	for (int i = 0; i < 100000; i++)
	{
		v5.push_back(i);
		if (p != &v5[0]) {
			p = &v5[0];
			num++;
		}
	}
	cout << num << endl;
	vector<int>v6;
	v6.reserve(100000);
	num = 0;
	*p = NULL;
	for (int i = 0; i < 100000; i++)
	{
		v5.push_back(i);
		if (p != &v5[0]) {
			p = &v5[0];
			num++;
		}
	}
	cout << num << endl;
	return 0;
}	
