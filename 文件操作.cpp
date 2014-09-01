#include <stdio.h>
#include <stdlib.h>
 
int main(void)
{
    FILE *myfile;
    char buffer[100];
    int i,j;
    double data[3][4] = {0.0};
    double data2[3][4] = {0.0};
    if ((myfile = fopen("hello.txt","rb")) == NULL)
    {
        printf("Read File Error\n");
    }
    i =0, j=0;
    /***Method One starts**********/
    while(fgets(buffer,100,myfile))
    {
 
        sscanf(buffer,"%lf %lf %lf %lf",&data[i][0],&data[i][1],&data[i][2],&data[i][3]);
        i++;
    }
    /***Method One ends**********/
    /***Method Two starts**********/
    rewind(myfile);//恢复指针到原始处
    for(i=0;i<3;i++){
        for(j=0;j<4;j++)
        {
         fscanf(myfile,"%lf", &data2[i][j]);
        }
    }
    /***Method Two ends**********/
    fclose(myfile);
 
    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            printf("%lf ", data[i][j]);
        }
        printf("\n");
    }
    printf("-------------------------\n");
        for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            printf("%lf ", data2[i][j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
