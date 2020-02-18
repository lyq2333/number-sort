#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<windows.h>
#define numbersize 131072
char string[40] , string2[20], path2[20];
void bubble();
void quick();
void count();
void radix();
void bubblesort(int *a, int n);
void quicksort(int *a, int p, int r);
int partition(int *a, int p, int r);
void countsort(int *a, int *b, int limit, int n);
void radixsort(int *a, int n);
void stablecountsort(int *a, int *b, int limit, int n);
int size=4;
void main()
{
	while (size <= 131072)
	{
		if (size == 4)
		{
			strcpy(string, "The time of the sort of 2:");
			strcpy(path2, "result_2.txt");
		}
		else if (size == 32)
		{
			strcpy(string, "The time of the sort of 5:");
			strcpy(path2, "result_5.txt");
		}
		else if (size == 256)
		{
			strcpy(string, "The time of the sort of 8:");
			strcpy(path2, "result_8.txt");
		}
		else if (size == 2048)
		{
			strcpy(string, "The time of the sort of 11:");
			strcpy(path2, "result_11.txt");
		}
		else if (size == 16384)
		{
			strcpy(string, "The time of the sort of 14:");
			strcpy(path2, "result_14.txt");
		}
		else if (size == 131072)
		{
			strcpy(string, "The time of the sort of 17:");
			strcpy(path2, "result_17.txt");
		}
		bubble();
		quick();
		count();
		radix();
		size *= 8;
	}
	
}
void bubble()
{
	FILE *fp;
	char  ch, string1[numbersize][6], path1[100] = {"../output/bubblesort/"};
	int a[numbersize] ;
	int i, j;
	int p = 0;
	if ((fp = fopen("../input/input.txt", "r")) == NULL)
	{
		printf("error");
		exit(0);
	}
	for (i = 0; i < size; i++)
	{
		ch = fgetc(fp);
		j = 0;
		while (ch != '\n')
		{
			string1[i][j] = ch;
			j++;
			ch = fgetc(fp);
		}
		string1[i][j] = '\0';
	}
	fclose(fp);
	for (i = 0; i < size; i++)
	{
		a[i] = atoi(string1[i]);
	}
	double f;
	LARGE_INTEGER start, fin, fre;
	QueryPerformanceFrequency(&fre);
	QueryPerformanceCounter(&start);//测量执行时间
	bubblesort(a,size);//bubblesort
	QueryPerformanceCounter(&fin);
	f = (double)(fin.QuadPart - start.QuadPart) / (double)fre.QuadPart;
	printf("%.10f\n", f*pow(10.0,9));
	for (i = 0; i < size; i++)
		itoa(a[i], string1[i], 10);
	strcat(path1, path2);
	if ((fp = fopen(path1, "w")) == NULL)
	{
		printf("error");
		exit(0);
	}
	for (i = 0; i < size; i++)
	{
		fputs(string1[i], fp);
		fputs("\n", fp);
	}
	fclose(fp);
	if ((fp = fopen("../output/bubblesort/time.txt", "a")) == NULL)
	{
		fp = fopen("../output/bubblesort/time.txt", "w");
	}
	fputs(string, fp);
	sprintf(string2, "%lf", f);
	fputs(string2, fp);
	fputs("s\n", fp);
	fclose(fp);
}
void quick()
{
	FILE *fp;
	char  ch, string1[numbersize][6], path1[100] = { "../output/quicksort/" };
	int a[numbersize];
	int i, j;
	int p = 0;
	if ((fp = fopen("../input/input.txt", "r")) == NULL)
	{
		printf("error");
		exit(0);
	}
	for (i = 0; i < size; i++)
	{
		ch = fgetc(fp);
		j = 0;
		while (ch != '\n')
		{
			string1[i][j] = ch;
			j++;
			ch = fgetc(fp);
		}
		string1[i][j] = '\0';
	}
	fclose(fp);
	for (i = 0; i < size; i++)
	{
		a[i] = atoi(string1[i]);
	}
	double f;
	LARGE_INTEGER start, fin, fre;
	QueryPerformanceFrequency(&fre);
	QueryPerformanceCounter(&start);
	quicksort(a, p, size - 1);//quicksort
	QueryPerformanceCounter(&fin);
	f = (double)(fin.QuadPart - start.QuadPart) / (double)fre.QuadPart;
	printf("%f\n", f);
	for (i = 0; i < size; i++)
		itoa(a[i], string1[i], 10);
	strcat(path1, path2);
	if ((fp = fopen(path1, "w")) == NULL)
	{
		printf("error");
		exit(0);
	}
	for (i = 0; i < size; i++)
	{
		fputs(string1[i], fp);
		fputs("\n", fp);
	}
	fclose(fp);
	if ((fp = fopen("../output/quicksort/time.txt", "a")) == NULL)
	{
		fp = fopen("../output/quicksort/time.txt", "w");
	}
	fputs(string, fp);
	sprintf(string2, "%lf", f);
	fputs(string2, fp);
	fputs("s\n", fp);
	fclose(fp);
}
void count()
{
	FILE *fp;
	char  ch, string1[numbersize][6], path1[100] = {"../output/countsort/"};
	int a[numbersize], b[numbersize];
	int i, j;
	int p = 0;
	if ((fp = fopen("../input/input.txt", "r")) == NULL)
	{
		printf("error");
		exit(0);
	}
	for (i = 0; i < size; i++)
	{
		ch = fgetc(fp);
		j = 0;
		while (ch != '\n')
		{
			string1[i][j] = ch;
			j++;
			ch = fgetc(fp);
		}
		string1[i][j] = '\0';
	}
	fclose(fp);
	for (i = 0; i < size; i++)
	{
		a[i] = atoi(string1[i]);
	}
	double f;
	LARGE_INTEGER start, fin, fre;
	QueryPerformanceFrequency(&fre);
	QueryPerformanceCounter(&start);
	countsort(a, b, 65536, size);//countsort
	QueryPerformanceCounter(&fin);
	f = (double)(fin.QuadPart - start.QuadPart) / (double)fre.QuadPart;
	printf("%f\n", f);
	for (i = 0; i < size; i++)
		itoa(a[i], string1[i], 10);
	strcat(path1, path2);
	if ((fp = fopen(path1, "w")) == NULL)
	{
		printf("error");
		exit(0);
	}
	for (i = 0; i < size; i++)
	{
		fputs(string1[i], fp);
		fputs("\n", fp);
	}
	fclose(fp);
	if ((fp = fopen("../output/countsort/time.txt", "a")) == NULL)
	{
		fp = fopen("../output/countsort/time.txt", "w");
	}
	fputs(string, fp);
	sprintf(string2, "%lf", f);
	fputs(string2, fp);
	fputs("s\n", fp);
	fclose(fp);
}
void radix()
{
	FILE *fp;
	char  ch, string1[numbersize][6], path1[100] = { "../output/radixsort/" };
	int a[numbersize];
	int i, j;
	int p = 0;
	if ((fp = fopen("../input/input.txt", "r")) == NULL)
	{
		printf("error");
		exit(0);
	}
	for (i = 0; i < size; i++)
	{
		ch = fgetc(fp);
		j = 0;
		while (ch != '\n')
		{
			string1[i][j] = ch;
			j++;
			ch = fgetc(fp);
		}
		string1[i][j] = '\0';
	}
	fclose(fp);
	for (i = 0; i < size; i++)
	{
		a[i] = atoi(string1[i]);
	}
	double f;
	LARGE_INTEGER start, fin, fre;
	QueryPerformanceFrequency(&fre);
	QueryPerformanceCounter(&start);
	radixsort(a, size);//radixsort
	QueryPerformanceCounter(&fin);
	f = (double)(fin.QuadPart - start.QuadPart) / (double)fre.QuadPart;
	printf("%.10f\n", f);
	for (i = 0; i < size; i++)
		itoa(a[i], string1[i], 10);
	strcat(path1, path2);
	if ((fp = fopen(path1, "w")) == NULL)
	{
		printf("error");
		exit(0);
	}
	for (i = 0; i < size; i++)
	{
		fputs(string1[i], fp);
		fputs("\n", fp);
	}
	fclose(fp);
	if ((fp = fopen("../output/radixsort/time.txt", "a")) == NULL)
	{
		fp = fopen("../output/radixsort/time.txt", "w");
	}
	fputs(string, fp);
	sprintf(string2, "%lf", f);
	fputs(string2, fp);
	fputs("s\n", fp);
	fclose(fp);
}
void bubblesort(int *a, int n)
{
	int i, j, b;
	for (j = 1; j < n; j++)
		for (i = 0; i < n - j; i++)
		{
			if (a[i]>a[i + 1])
			{
				b = a[i];
				a[i] = a[i + 1];
				a[i + 1] = b;
			}
		}
}
void quicksort(int *a, int p, int r)
{
	int q;
	if (p < r)
	{
		q = partition(a, p, r);
		quicksort(a, p, q - 1);
		quicksort(a, q + 1, r);
	}
}
int partition(int *a, int p, int r)
{
	int i, j, b;
	i = p - 1;
	for (j = p; j < r; j++)
	{
		if (a[j] <= a[r])
		{
			i++;
			b = a[j];
			a[j] = a[i];
			a[i] = b;
		}
	}
	b = a[i + 1];
	a[i + 1] = a[r];
	a[r] = b;
	return i + 1;
}
void countsort(int *a, int *b, int limit, int n)
{
	int c[65536], i;
	for (i = 0; i < limit; i++)
		c[i] = 0;
	for (i = 0; i < n; i++)
		c[a[i]]++;
	for (i = 1; i < limit; i++)
		c[i] = c[i] + c[i - 1];
	for (i = n - 1; i >= 0; i--)
	{
		c[a[i]]--;
		b[c[a[i]]] = a[i];
	}
	for (i = 0; i < n; i++)
		a[i] = b[i];
}
void radixsort(int *a, int n)
{
	int i, j, m, z;
	int *b = new int[size];
	float f = 10;
	for (i = 1; i <= 5; i++)
	{
		for (j = 0; j < n; j++)
		{
			m = a[j] / pow(f, i);
			z = a[j] / pow(f, i - 1);
			b[j] = z - m * 10;
		}
		stablecountsort(a, b, 10, size);
	}
}
void stablecountsort(int *a, int *b, int limit, int n)
{
	int c[10], i;
	int *d = new int[size];
	for (i = 0; i < limit; i++)
		c[i] = 0;
	for (i = 0; i < n; i++)
		c[b[i]]++;
	for (i = 0; i < limit; i++)
	{
		if (i == 0) c[i] = c[i];
		else c[i] = c[i] + c[i - 1];
	}
	for (i = n - 1; i >= 0; i--)
	{
		c[b[i]]--;
		d[c[b[i]]] = a[i];
	}
	for (i = 0; i < n; i++)
		a[i] = d[i];
}