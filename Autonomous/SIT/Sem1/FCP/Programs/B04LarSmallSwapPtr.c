#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int iaList[50], iNum, i, j, iTemp, iPos;
    int *iPtr1,*iPtr2;

    iPtr1 = iPtr2 = iaList;
    printf("\nEnter the value of n : ");
    scanf("%d", &iNum);

    printf("\nEnter the elements: ");
    for(i=0;i<iNum;++i)
    {
        scanf("%d", &iaList[i]);
    }

    for(i=1;i<iNum;++i)
    {
        if(iaList[i] < *iPtr1)
        {
            iPtr1 = &iaList[i];
        }
        if(iaList[i] > *iPtr2)
        {
            iPtr2 = &iaList[i];
        }
    }

    printf("\nArray elements before swapping the largest and smallest elements\n");
    for(i=0;i<iNum;i++)
    {
        printf("%d\t", iaList[i]);
    }

    printf("\nSmallest Element = %d\n",*iPtr1);
    printf("\nLargest Element = %d\n",*iPtr2);

    iTemp = *iPtr1;
    *iPtr1 = *iPtr2;
    *iPtr2 = iTemp;

    printf("\nArray elements after swapping the largest and smallest elements\n");
    for(i=0;i<iNum;i++)
    {
        printf("%d\t", iaList[i]);
    }
    printf("\n");
    return 0;
}

