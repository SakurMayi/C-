#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <ctime>
using namespace std;
/*���������㷨
* 1. sort   ������������
* 2. random_shuffle ϴ�ƣ�ָ����Χ�������������
* 3. merge ����Ԫ�غϲ������洢����һ������
* 4. reverse ��תָ����Χ�ڵ�Ԫ��
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
��ֵ����Ԫ�أ��Ҳ������ؽ���������λ�ã����򷵻�ָ��λ�õ�����
begin ��ʼ������
end ����������
elem ν��
*/
void test1() {
	vector<int>vec;
	vec.push_back(10);
	vec.push_back(5);
	vec.push_back(20);
	vec.push_back(15);
	//Ĭ��������
	sort(vec.begin(), vec.end());
	for_each(vec.begin(), vec.end(), Printf);
	cout << endl;
	//����
	//sort(vec.begin(), vec.end(), greater<int>());
	/*�÷º���*/
	sort(vec.begin(), vec.end(), Mycompare());
	for_each(vec.begin(), vec.end(), Printf);
	cout << endl;
	cout << endl;
}
void test2(){
	srand((unsigned int)time(NULL));//����������ӣ�����ʱ��仯������Ҳ�仯
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
* 2��������������
* beg1 ����һ��ʼ������
* beg2 ��������ʼ������
* end1 ����һ����������
* end2 ����������������
* dest Ŀ��������ʼ������
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
	cout << "��תǰ��";
	for_each(v.begin(),v.end(),Printf);
	cout << endl;
	cout << "��ת��";
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
