#include <stdio.h>

int main() {
    int a, b;


    printf("The first integer is: ");
    scanf("%d", &a);

    printf("The second integer is: ");
    scanf("%d", &b);


    if (a > b)
        {
        printf("%d is greater than %d", a, b);

        }
    else if (a < b)
        {
        printf("%d is smaller than %d", a, b);
        }
    else {
        printf("%d is equal to %d", a, b);
    }

    return 0;
}
