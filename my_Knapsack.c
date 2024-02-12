#include <stdio.h>
#include <stdlib.h>
#define BAG_CAPACITY 20
#define NUM_ITEMS 5
#define TRUE 1;
#define FALSE 0;
int knapSack(int weights[], int values[], int selected_bool[]);
int main(){
    char items [NUM_ITEMS];
    int values [NUM_ITEMS];
    int weights[NUM_ITEMS];
    int is_selected[NUM_ITEMS];
    char result[NUM_ITEMS];
    for (int i=0; i<NUM_ITEMS; i++){
        scanf("%s %d %d",&items[i], &values[i], &weights[i]);

    }

    int solve_knapsack = knapSack(weights, values, is_selected);
    printf("Maximum profit: %d\n", solve_knapsack);
    for(int r=0; r<NUM_ITEMS; r++){
        if (is_selected[r]==1) result[r]=items[r];//1==TRUE

    }
    printf("Selected items:");
    for (int i = 0; i < NUM_ITEMS; i++)
    {
        if(result[i]!=0){
            printf(" %c", result[i]);
        }
    }
    
}


// Returns maximum out of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Returns the maximum value that can be put in a knapsack with our given max weight
int knapSack(int weights[], int values[], int selected_bool[]) {
    int i, w;
    int **M;
    //initializing all selected_bool to be zeros to avoid using previous content of the memory or garbage values
    for (i = 0; i < NUM_ITEMS; i++) {selected_bool[i]=0;}

    // Save memory place for 2D array to store results
    M = (int **)malloc((NUM_ITEMS + 1) * sizeof(int *));
    for (i = 0; i < NUM_ITEMS + 1; i++)
        M[i] = (int *)malloc((BAG_CAPACITY + 1) * sizeof(int));

    // Build table M[][] in bottom-up manner
    for (i = 0; i <= NUM_ITEMS; i++) {
        for (w = 0; w <= BAG_CAPACITY; w++) {
            if (i == 0 || w == 0)
                M[i][w] = 0;
            else if (weights[i - 1] <= w) {
                M[i][w] = max(values[i - 1] + M[i - 1][w - weights[i - 1]], M[i - 1][w]);
            } else {
                M[i][w] = M[i - 1][w];
            }
        }
    }

    // Going back to find which items were selected
    i = NUM_ITEMS;
    w = BAG_CAPACITY;
    while (i > 0 && w > 0) {
        if (M[i][w] != M[i - 1][w]) {
            selected_bool[i - 1] = 1; // Item is selected
            w = w - weights[i - 1];
        }
        i--;
    }
    int kk =M[NUM_ITEMS][BAG_CAPACITY];
    // Free memory saved for M[][]
    for (i = 0; i < NUM_ITEMS + 1; i++)
        free(M[i]);
    free(M);

    // Return the maximum value
    return kk;
}
