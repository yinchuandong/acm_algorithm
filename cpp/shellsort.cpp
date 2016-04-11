#include<iostream>

using namespace std;

/********************************************************
*函数名称：ShellInsert
*参数说明：pDataArray 无序数组；
*          d          增量大小
*		   iDataNum为无序数据个数
*说明：    希尔按增量d的插入排序
*********************************************************/
void ShellInsert(int* pDataArray, int d, int iDataNum)
{
	for (int i = d; i < iDataNum; i += 1)    //从第2个数据开始插入
	{
		int j = i - d;
		int temp = pDataArray[i];    //记录要插入的数据
		while (j >= 0 && pDataArray[j] > temp)    //从后向前，找到比其小的数的位置
		{
			pDataArray[j+d] = pDataArray[j];    //向后挪动
			j -= d;
		}

		if (j != i - d)    //存在比其小的数
			pDataArray[j+d] = temp;
	}
}

/********************************************************
*函数名称：ShellSort
*参数说明：pDataArray 无序数组；
*		   iDataNum为无序数据个数
*说明：    希尔排序
*********************************************************/
void ShellSort(int* pDataArray, int iDataNum)
{
	int d = iDataNum / 2;    //初始增量设为数组长度的一半
	while(d >= 1)
	{
		ShellInsert(pDataArray, d, iDataNum);
		d = d / 2;    //每次增量变为上次的二分之一
	}
}

int main(int num, char *args[]){
	int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int n = 10;
	ShellInsert(arr, 4, n);
	for (int i = 0; i < n; i++){
		cout<<arr[i]<<' ';
	}
	cout<<endl;
	
	ShellInsert(arr, 1, n);
	for (int i = 0; i < n; i++){
		cout<<arr[i]<<' ';
	}
	cout<<endl;
	return 0;
}
