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
    ::left = 0;//��ʼ��
    ::right = n - 1;//�յ�
    cin >> a;
    bool isprime = false;
    while (::left <= ::right ) {//ѭ���ж�����
        mid = (::right + ::left) / 2;//�����м��
        if (vec[mid] < a) {
            ::left = mid + 1;
        }
        else if (vec[mid] > a) {
            ::right = mid - 1;
        }
        else {
            cout << "�������д�Ԫ��,�±�Ϊ��" << mid << endl;
            isprime = true;
            break;
        }
    }
    if(!isprime) cout << "�����в����ڸ�Ԫ��" << endl;
    return 0;
}
