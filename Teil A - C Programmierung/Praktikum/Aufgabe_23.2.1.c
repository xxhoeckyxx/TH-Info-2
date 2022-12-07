#include <stdio.h> 

int i = 0;
int setzel(int x);
int setze2(int x);

int main(void)
{    
    auto int i = 5;
    setzel(i / 2);      printf("1. i = %d\n", i);
    setzel(i = i / 2);  printf("2. i = %d\n", i);
    i = setzel(i / 2);  printf("3. i = %d\n", i);
    setze2(i);          printf("4. i = %d\n", i);
    return (0);
}

int setzel(int i)
{
    i = i <= 2 ? 5 : 0;
    return (i);
}
int setze2(int i)
{
    i = i%i*(i*i/(2*i)+4);
    printf("5. i = %d\n", i);
    return i;
}