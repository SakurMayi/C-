#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;
int d[6] = { 0 };
void add(int l, int r, int v) {
	d[l] += v;
	d[r + 1] -= v;
}
int main(){
/*
	一维差分
	* arr 1 3 7 5 2
	* d 1 2 3 -2 -3 //arr中每2项之差
	* sumd 1 3 7 5 2 //利用d数组求原数组
	* 则有差分标记：
	* [L,R] + V => d[L] + V, d[R+1] - V
	* 然后再把标记后的数组进行一次前缀和
	*/
	//原数组 
	int arr1[5] = { 1,3,7,5,2 };
	//差分标记
	add(2, 4, 5);
	add(1, 3, 2);
	add(0, 2, -3);
	//做前缀和
	for (int i = 1; i < 5; i++) d[i] += d[i - 1];
	for (int i = 0; i < 5; i++) {
		arr1[i] += d[i];
		cout << arr[i] << " ";
	}
	memset(d, 0, sizeof(0));
	cout << endl;
}
