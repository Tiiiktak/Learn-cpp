/*
	归并排序 C++实现
	先自上而下将乱序数列分解为数个长度为1的数列
	再自下而上组成长度为2,4,8...的有序数列
 */
#include <iostream>
using namespace std; 

//合并两个有序数组
void mergearray(int a[], int start, int mid, int end, int temp[])
{
	int i = start, j = mid + 1; //i-前一数组迭代, j-后一数组迭代
	int m = mid, n =end; 
	int k = 0; //temp[]计数
	
	while (i<=m && j<=n) //合并排序
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++]; 
		else
			temp[k++] = a[j++]; 
	}
	//将原数组中剩余元素放入temp
	while (i <= m)
		temp[k++] = a[i++]; 
	while (j <= n)
		temp[k++] = a[j++]; 
	//将temp迁入原数组
	for (i = 0; i < k; ++i)
		a[start+i] = temp[i]; 
}

//拆分
void mergesort(int a[], int start, int end, int temp[])
{
	if (start < end)
	{
		int mid = (start+end)/2; 
		mergesort(a, start, mid, temp); 
		mergesort(a, mid+1, end, temp); 
		mergearray(a, start, mid, end, temp); 
	}
}

bool merge(int a[], int n)
{
	int *p = new int[n]; 
	if (p == NULL)
		return false; 
	mergesort(a, 0, n-1, p); 
	delete[] p; 
	return true; 
}

int main(int argc, char const *argv[])
{
	int arr[10] = {3, 2, 6, 4, 8, 9, 0, 1, 5, 7}; 
	if (!merge(arr, 10))
		cout << "Error: out of memory.\n"; 
	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i] << " "; 
	}
	return 0;
}