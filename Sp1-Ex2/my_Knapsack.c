#include <stdio.h>
#define BAG_WEIGHT 20
#define NUM_ITEMS 5

int knapSack (int weights[], int values[] , int selected_bool[]){
    int i,j;
    int mat[NUM_ITEMS+1][BAG_WEIGHT+1]={0};
    for(i=1;i<=NUM_ITEMS;i++){
        for(j=1;j<=BAG_WEIGHT; j++){
            if(weights[i-1]<=j){

            if(mat[i-1][j]>values[i-1]+mat[i-1][j-weights[i-1]]){
                mat[i][j] = mat[i-1][j];
            }
            else{
                mat[i][j] = values[i-1]+mat[i-1][j-weights[i-1]];

            }
            }

        }
    }
    j=BAG_WEIGHT;
    
    for(i=NUM_ITEMS;i>0;i--){
        if(mat[i][j] == mat[i-1][j]){
            selected_bool[i-1] = 0;
        }
        else{
            selected_bool[i-1] = 1;
            j = j-weights[i-1];
        }
    }

    return mat[NUM_ITEMS][BAG_WEIGHT];
}

int main(){
    int i;
    char items[NUM_ITEMS];
    int values[NUM_ITEMS];
    int weights[NUM_ITEMS];
    int selected_bool[NUM_ITEMS] = {0};
    for(i=0;i< NUM_ITEMS;i++){
        scanf(" %c%d%d", &items[i], &values[i], &weights[i]);
    }

    int ans = knapSack(weights, values ,selected_bool);
    printf("Maximum profit: %d\n", ans);
    printf("Selected items: ");
    for(i=0;i< NUM_ITEMS;i++){
        if(selected_bool[i]){
            printf("%c ", items[i]);
        }
    }
    printf("\n");

    return 0;
}
