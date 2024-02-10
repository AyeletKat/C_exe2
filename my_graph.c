
#include "my_mat.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main(){
    //printf("Enter 100 integers:\n");
    int i,j;
    char insert;
       // Allocate memory
    int **matrix = (int**) malloc(SIZE * sizeof(int*));

    for (int i = 0; i < SIZE; ++i)
        matrix[i] = (int*) malloc(SIZE * sizeof(int));

    do{
        scanf("%c", &insert);
        //getchar(); // Consume newline character
        switch (insert) {
            case 'A':
                get_matrix(matrix);
                break;
            case 'B':
                scanf("%d %d", &i, &j);
                int ok =is_way(matrix, i, j);
                if (ok==1) printf("True");
                else if (ok==0) printf("False");
                printf("\n");
                break;
            case 'C':
                scanf("%d %d", &i, &j);
                int path = shortest_path_len(matrix, i, j);
                printf("%d",path);
                printf("\n");
                break;
            default:
                //printf("Invalid option. Please enter A, B, C, or D to exit.\n");
                break;
        }
    }
    while (insert != 'D' && insert != EOF);
    printf("\n");

       // Free memory to end program
    for (int i = 0; i < SIZE; ++i)
        free(matrix[i]);

    free(matrix);
    return 0;
}