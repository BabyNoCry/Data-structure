#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
//¼ÆÊýÅÅÐò
void Getcount(int* a, int n)
{
	int max = a[0];
	int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int range = max - min + 1;
	int* tmp = (int*)malloc(sizeof(int)*range);
	/*for (int i = 0; i < range; i++)
		tmp[i] = 0;*/
	memset(tmp, 0, range * sizeof(int));
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		tmp[a[i] - min]++;
	}
	for (int i = 0; i < range; i++)
	{
		while (tmp[i]--)
		{
			a[j++] = min + i;
		}
	}
	free(tmp);
}

//¹é²¢ÅÅÐò
void Merge(int* a, int low, int mid, int high)
{
	int i=0, k=0;
	int* tmp= (int*)malloc(sizeof(int)*(high - low + 1));
	int left_low = low;
	int left_high = mid;
	int right_low = mid + 1;
	int right_high = high;
	while (left_low <= left_high && right_low <= right_high)
	{
		if (a[left_low] >= a[right_low])
			tmp[k++] = a[right_low++];
		else
			tmp[k++] = a[left_low++];
	}
	while (left_low <= left_high)
		tmp[k++] = a[left_low++];
	while (right_low <= right_high)
		tmp[k++] = a[right_low++];
	for ( i = 0; i < high - low + 1; i++)
		a[low + i] = tmp[i];
	free(tmp);
}
void Mer_Sort(int* a, int first, int last)
{
	int mid = 0;
	if (first < last)
	{
		mid = first + ((last - first) >> 1);
		Mer_Sort(a, first, mid);
		Mer_Sort(a, mid + 1, last);
		Merge(a, first, mid, last);
	}
}
int main()
{
	int arr[] = { 9,10,8,4,3,2,1 };
	Merage(arr, 0, 6);
	for (int i = 0; i < 7; i++)
	{
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}