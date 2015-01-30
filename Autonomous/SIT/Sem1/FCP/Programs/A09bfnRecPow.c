#include <stdio.h>
#include <stdlib.h>

int fnRecPow(int, int);
int main(void)
{
    int iX, iN;
	float fRes;
    printf("\n Enter value of x and n\n");
    scanf("%d%d", &iX, &iN);

	if(iN<0)
	{
		fRes = 1.0/fnRecPow(iX,-iN);
	}
	else
	{
	    fRes = fnRecPow(iX,iN);
	}
    printf("\n%d raised to the power %d is %d\n",iX, iN, fRes);
    return 0;
}

int fnRecPow(int iX, int iN)
{
    if(0==iN)
		return 1;
	else if(1 == iN)
        return iX;
    else
        return (iX * fnRecPow(iX, iN-1));
}
