// LabViewDllTest.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#include "LabViewDllTest.h"

int Multiply( int a, int b )
{
	return a*b;
}

int Array_Multiply( double *a, int n, double c )
{
	int i;
	double *ptr = a;

	if (a==NULL)
		return(-1);

	for (i=0; i<n; i++){
		*ptr *= c;
		ptr++;
	}

	return 0;
}
