#include <iostream>
using namespace std;
int d[6] = { 0 };
void add(int l, int r, int v) {
	d[l] += v;
	d[r + 1] -= v;
}
int main()
{
	/*
	一维前缀和
	*/
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//有一个数组arr，求区间和如[0,2],[1,4],[0,10],[4,8]
	int sum[10];
	//前缀和数组，sum[i] = sum[i-1]+arr[i];sum[0]=arr[0];
	//sum[j]-sum[i] 即[i,j]的和
	sum[0] = arr[0];
	cout << sum[0] << " ";
	for (int i = 1; i < 10; i++) {
		sum[i] = sum[i - 1] + arr[i];
		cout << sum[i] << endl;
	}
	//复杂度O(n);
	cout << endl;
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

	/*二维前缀和
	* n = 3 , m = 4
	* 1 5 6 8
	* 9 6 7 3
	* 5 3 2 4
	* (1,1)->(2,2) 矩阵和 sum = 6 + 7 + 3 + 2 = 18
	* (0,1)->(1,3) 矩阵和 sum = 5 + 6 + 8 + 6 + 7 + 3 = 35 复杂度为：O(nm)
	* 用前缀和 也就是i=0行的前缀和 和 i=1行的前缀和计算(0,1)->(1,3)  复杂度为O(min{n,m})
	* 也可以用动态规划进行优化
	* 这个是可以优化到O(1)
	* 
	*/

}