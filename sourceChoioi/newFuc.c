#include <stdio.h>
#include <stdlib.h>

int Com(const void* X, const void* Y)
{
	int x = *((int*)X);
	int y = *((int*)Y);

	if (x > y) return 1;
	if (x < y) return -1;
	if (x == y) return 0;
}

int main()
{
	int N, M;
	int pivot = 0;
	int max = 0;
	int min = 0;
	int arr1[100001];
	int arr2[100001];

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr1[i]);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &arr2[i]);
	}
	qsort(arr1, N, sizeof(int), Com);


}
