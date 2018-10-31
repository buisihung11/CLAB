#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */


void createMatrices(int *a){
    int x, y;
    //a=(int*)malloc(2 * 3 * sizeof(int));
    for (int i= 0; i< 2;i++)
        for(int j=0;j< 3; j++)
            scanf("%d" , (a + (3*i + j)));
}
void printMatrix(int *a){
    int x, y;
    for(int i=0;i<2;i++){
        for (int j=0;j<3;j++){
            printf("%d\t", *(a + (3*i + j)));
        }
        printf("\n");
    }
}
int sumMatrix(){
    int x,y,*s,*a,i,j;
    for( i=0;i<x;i++)
        for( j=0;j<y;j++)
            *s = *a + *a;
}
int main(int argc, char** argv) {
    int x,y, *s, *a, *b;
    printf("Matrix Add\n");
    printf("Accept size: ");
    scanf("%d%d", &x, &y);
    a = (int*) malloc(x*y*sizeof(int));
    printf("Matrix 1: \n");
    createMatrices(a);
    for(int i=0;i<2;i++){
        for (int j=0;j<3;j++){
            printf("%d\t", *(a + (3*i + j)));
        }
        printf("\n");
    }
    printMatrix(a);
    // printf("Matrix 2: \n");
    // createMatrices(b);
    // printMatrix(b);
    // //printf("s = a + b");
    // sumMatrix();
    
    return (EXIT_SUCCESS);
}
