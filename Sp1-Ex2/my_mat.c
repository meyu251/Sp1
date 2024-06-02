#include "my_mat.h"
#include <stdio.h>

#define N 10



int min(int a,int b){
    return (a>b) ? b : a;
}

void FloydWarshel(int mat[N][N]){
    for(int k=0; k<N; k++){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(mat[i][j]!=0 && mat[i][k]!=0 && mat[k][j]!=0){
                    mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
                }
                if(i!=j && mat[i][j]==0 && mat[i][k]!=0 && mat[k][j]!=0){
                    mat[i][j]=mat[i][k]+mat[k][j];
                }
            }
        }
    }

}

void CreateMatrix(int Matrix [N][N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &Matrix[i][j]);
        }
    }
    FloydWarshel(Matrix);
}

void IsTherePath(int Matrix [N][N] ,int StartNode,int EndNode){
    if(StartNode == EndNode){
        printf("False");
        return;
    }
    if(Matrix[StartNode][EndNode] == 0){
        printf("False");
    }
    else{
        printf("True");
    }

}

void ShortestPath(int Matrix [N][N],int StartNode,int EndNode){
    if(StartNode == EndNode){
        printf("-1");
        return;
    }

    if(Matrix[StartNode][EndNode]==0){
        printf("-1");
    }
    else{
         printf("%d",Matrix[StartNode][EndNode]);
    }


}
