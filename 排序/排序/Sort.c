//÷±Ω”≤Â»Î≈≈–Ú
#include<stdio.h>
#include<stdlib.h>
void  InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[i + 1];
		while (end >= 0)
		{
				
			if (a[end] >tmp)
			{
				a[end + 1] = a[end];
			}
			else
			{
				break;
			}
			end--;
		}
		a[end + 1] = tmp;
	}
}
//œ£∂˚≈≈–Ú
void ShellSort(int* a, int n)
{
	int gop = n;
	while (gop > 1)
	{
		gop = gop / 3 + 1;
		for (int i = 0; i < n - gop; i++)
		{
			int end = i;
			int tmp = a[i + gop];
			while (end >=0)
			{
				if (a[end] > tmp)
				{
					a[end + gop] = a[end];
				}
				else
				{
					break;
				}
				end -= gop;
			}
			a[end + gop] = tmp;
		}
	}

}
//Ωªªª
void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

//—°‘Ò≈≈–Ú
void SeletSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	
	while (begin < end)
	{
		int min = begin;
		int max = end;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] > a[max])
			{
				max = i;
			}
			if (a[i] < a[min])
			{
				min = i;
			}
		}
		swap(&a[begin], &a[min]);
		if (max == begin)
		{
			swap(&a[end], &a[min]);
		}
		else
		{
			swap(&a[end], &a[min]);
		}
		
		begin++;
		end--;
	}
}

//∂—≈≈–Ú
void JustDown(int* a, int n, int parent)
{
	for (int i = parent; i * 2 + 1 < n; i = parent)
	{
		int child = parent * 2 + 1;
		if (a[child] < a[child + 1] && child != n - 1)
			child++;
		if (a[parent] >= a[child])
		{
			break;
		}
		else
		{
			swap(&a[parent], &a[child]);
			parent = child;
		}
	}
	
}
void HeapSort(int* a, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		JustDown(a, n, i);

	}
	for (int i = n - 1; i >= 0; i--)
	{
		swap(&a[0], &a[i]);
		JustDown(a, i, 0);
	}
}
int main()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int arr2[] = { 9,8,7,6,5,4,3,2,1,0 };
	int arr3[] = { 9,8,7,6,5,4,3,2,1,0 };
	int arr4[] = { 9,1,2,4,5,7,6,3,0,8 };

	ShellSort(arr2, 10);
	InsertSort(arr, 10);
	SeletSort(arr3, 10);
	HeapSort(arr4, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);

	}
	printf("\n");
	for (int i = 0; i < 10; i++)
	{
		
		printf("%d ", arr2[i]);
	}

	printf("\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr3[i]);

	}
	printf("\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr4[i]);

	}



	system("pause");
	return 0;
}
