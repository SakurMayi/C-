#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, left, right, a, mid;

int main()
{
    vector<int> vec;
    vec.reserve(n);
    for (int i = 0; i < n; i++) {
        cin >> a;
        vec.push_back(a);
    }
    ::left = 0;//起始点
    ::right = n - 1;//终点
    cin >> a;
    bool isprime = false;
    while (::left <= ::right ) {//循环判定条件
        mid = (::right + ::left) / 2;//计算中间点
        if (vec[mid] < a) {
            ::left = mid + 1;
        }
        else if (vec[mid] > a) {
            ::right = mid - 1;
        }
        else {
            cout << "数组中有此元素,下标为：" << mid << endl;
            isprime = true;
            break;
        }
    }
    if(!isprime) cout << "数组中不存在该元素" << endl;
    return 0;
}
