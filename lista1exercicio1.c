#include <stdio.h>

int main()
{
    float x,y;
    
    printf("1° Nota:");
    scanf("%f", &x);
    printf("2° Nota:");
    scanf("%f", &y);

    printf("Média: %.2f \n", (x + y)/2);
    return 0;
}
