#include <stdio.h>
#include <stdlib.h>

void main()
{

	float x=1;
	double y=1;

	while((1+x) > 1)
	{
	x = x/2;
	printf("x= %e\n", x);
	}

	while((1+y) > 1)
	{
	y = y/2;
	printf("y= %e\n", y);
	}

}
