#include <stdio.h>

int main ()
{
    int a,b,c;
    int n,i;

    a=0;
    b=4;
    printf("donnez un nombre n : ");
    scanf("%d",n);

    if (n==0)
    {
        printf("Le 0eme terme vaut 0");
    }
    else 
    {
        if (n==1)
        {
            printf("Le 1er terme vaut 4");
        }
        else
        {
            i=0;
            while(i<=n)
            {
                c=(-(n+2)*a) + (5*b+5);
                a=b;
                b=c;
                i++;
            }
            
        }
    }
    return 0; 
}