// LabViewDllTest_unitTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>

#include "..\LabViewDllTest\LabViewDllTest.h"

void test_Multiply(void)
{
	int a = 3;
	int b = 4;
	int c;

	printf("%s\n", __FUNCTION__);
	c = Multiply(a, b);
	printf("%d x %d = %d\n", a, b, c);
}

void test_Array_Multiply(void)
{
	double c = 1.2;
	double a[]={0.5, 1.0, 1.5, 2.0};
	int retVal;
	double *A;
	clock_t time1, time2;
	int I=500, N=1000000, i;

	printf("%s\n", __FUNCTION__);

	printf("(%f %f %f %f) x %f = ", a[0], a[1], a[2], a[3], c);
	retVal = Array_Multiply(a, 4, c);
	printf("(%f %f %f %f)   (%d)\n", a[0], a[1], a[2], a[3], retVal);

	retVal = Array_Multiply(NULL, 4, c);
	printf("(%f %f %f %f)   (%d)\n", a[0], a[1], a[2], a[3], retVal);

	printf("%d iterations of array size %d\n", I, N);

	A = (double *) malloc(N * sizeof(double));

	for (i=0; i<N; i++){
		A[i] = (double)rand()/(double)RAND_MAX;
	}

	time1 = clock();
	for (i=0; i<I; i++){
		Array_Multiply(A, N, 1.2);
	}
	time2 = clock();
	printf("Time per Array_Multiply call: %f ms\n", 1000*((double)(time2-time1))/CLOCKS_PER_SEC/I);

}

int _tmain(int argc, _TCHAR* argv[])
{
	clock_t time1, time2;

	printf("LabViewDll Unit Tests\n");
	time1 = clock();

	test_Multiply();
	test_Array_Multiply();

	time2 = clock();

	printf("Total time: %f ms\n", 1000 * ((double)(time2 - time1)) / CLOCKS_PER_SEC);

	getchar();

	return 0;
}

