#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
int Fa[maxn], Rank[maxn];

void init(int n);
int find(int x);
void merge(int i, int j);

void merge1(int i,int j);
int find1(int x);

int main() {
}

void init(int n)  ///初始化
{
	for (int i = 1; i <= n; i++)
	{
		Fa[i] = i;
		Rank[i] = 1;
	}
}

int find(int x)
{
	if (Fa[x] == x)
		return x;
	else
		return find(Fa[x]);
}


int find1(int x) //路径压缩
{
	if (x == Fa[x])
		return x;
	else {
		Fa[x] = find(Fa[x]);  //父节点设为根节点
		return Fa[x];         //返回父节点
	}
	//简化：return x == Fa[x] ? x : (Fa[x] = find(Fa[x]));
	//注意赋值运算符=的优先级没有三元运算符?:高，这里要加括号
}

void merge(int i, int j)//合并
{
	Fa[find(i)] = find(j);
}

void merge1(int i, int j) //合并(按秩合并)
{
	int x = find(i), y = find(j); //先找到两个根节点
	if (Rank[x] <= Rank[y])
	{
		Fa[x] = y;
	}
	else
	{
		Fa[y] = x;
	}
	if (Rank[x] == Rank[y] && x != y)
	{
		Rank[y]++; //如果深度相同且根节点不同，则新的根节点的深度+1
	}
}
