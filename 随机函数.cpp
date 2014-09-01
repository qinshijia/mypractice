#include<stdio.h>
#include<stdlib.h>
#include<cstdlib>

int main()
{   int i = 0,j = 0; 
    char a[100] ;
    while(1){
             while(1){
                      i = rand()%123;
                      if( i > 96 ) break;
             }
             a[j] = i;
             j ++;
             if( j == 100) break;
    }
    printf("%s",a);
    system("pause");
    return 0;
} 
