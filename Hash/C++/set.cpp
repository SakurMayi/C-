#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
/*set容器和multset容器：插入时自动排序,默认从小到大排序
    区别：前者不允许有重复元素，后者允许有重复元素
    二者本质：都输入关联式容器，底层都用二叉树实现
*/
/*方法：set和multset一样
set<T> set;//默认构造函数
set(const set & st);//拷贝构造函数
set &operator = (const set & st);// 赋值
set.empty();//判断是否为空集
set.insert();//插入元素
set.swap();//交换
set.clear()//清空
set.erase(pos) //删除迭代器pos所指的元素
set.erase(x) //删除值为x的元素
sets.erase(beg,end)//删除[ben,end)内的元素
find(x)//查找元素，如果存在返回改值的迭代器，不存在返回set.end()
count(x)//统计元素的个数
*/
/*排序：
1.内置排序
2.自定义数据类型排序
利用仿函数改变排序规则。
*/

class Mycompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};
class Student
{
public:
    string name;
    int age;
    Student(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
};
class Studentcompare{
public:
    bool operator()(const Student & s1, const Student & s2){
        return s1.age > s2.age;
    }
};
void printf(const set<int, Mycompare> &sets)
{
    for (set<int, Mycompare>::iterator it = sets.begin(); it != sets.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
void printf(set<int> &sets)
{
    for (set<int>::iterator it = sets.begin(); it != sets.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
int main()
{
    set<int> sets;
    set<int> set2;
    for (int i = 0; i < 10; i++)
    {
        sets.insert(i);
        set2.insert(i + 1);
    }
    set<int> s2(sets);
    printf(s2);
    cout << sets.size() << endl;
    cout << "交换前：" << endl;
    printf(sets);
    printf(set2);
    cout << "交换后：" << endl;
    sets.swap(set2);
    printf(sets);
    printf(set2);
    sets.erase(sets.begin(), sets.end());
    cout << sets.size() << endl;
    printf(sets);
    printf(set2);
    set2.erase(3);
    printf(set2);
    set2.clear();
    printf(set2);
    set<int>::iterator it = s2.find(3);
    if (it == s2.end())
        cout << "没找到" << endl;
    else
        cout << "找到了" << *it << endl;
    cout << s2.count(3) << endl;
    cout << "内置排序：" << endl;
    set<int, Mycompare> s1;
    s1.insert(50);
    s1.insert(10);
    s1.insert(20);
    s1.insert(0);
    s1.insert(100);
    printf(s1);
    cout << endl;
    cout << "set自定义数据类型排序" << endl;
    set<Student,Studentcompare> s3;
    Student p1("zhangsan", 22);
    Student p2("xiaoming", 18);
    Student p3("lisi", 15);
    Student p4("wanger", 20);
    s3.insert(p1);
    s3.insert(p2);
    s3.insert(p3);
    s3.insert(p4);
    for (set<Student,Studentcompare>::iterator i = s3.begin(); i != s3.end() ; i++)
    {
        cout <<i->name<<" "<<i->age<<endl;
    }
    return 0;
}
