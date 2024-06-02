#include <stdio.h>
#include "my_mat.h"

#define N 10

int main() {
    
    char choose;
    scanf("%c",&choose);
    int mat [N][N];
    int d1,d2;

    while(choose!='D'){
        if(choose=='A'){
            CreateMatrix(mat);
        }
        else if(choose=='B'){
            scanf("%d %d",&d1,&d2);
            IsTherePath(mat,d1,d2);
            printf("\n");
        }
        else if(choose=='C'){
            scanf("%d %d",&d1,&d2);
            ShortestPath(mat,d1,d2);
            printf("\n");

        }
        scanf("%c",&choose);
    }
}