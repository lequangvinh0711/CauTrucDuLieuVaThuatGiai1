﻿//Khai bao hang
#define MAX 100
void NhapDay(int a[MAX], int n)
{
	int i;
	srand((unsigned)time(NULL));
	for (i = 0; i < n; i++)
	{
		a[i] = -8 + rand() % 17;// trong khoảng [-8,8]
	}
}
void XuatDay(int a[MAX], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << '\t';
}
void MinMax(int a[MAX], int l, int r, int &min, int &max)
{
	int min1, min2, max1, max2;
	if (l == r)
	{
		min = a[l];
		max = a[l];
	}
	else
	{
		MinMax(a, l, (l + r) / 2, min1, max1);
		MinMax(a, (l + r) / 2 + 1, r, min2, max2);
		if (min1 < min2)
			min = min1;
		else
			min = min2;
		if (max1 > max2)
			max = max1;
		else
			max = max2;
	}
}