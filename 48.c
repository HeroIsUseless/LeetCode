#include "MyLib.c"

void rotate(int **matrix, int matrixSize, int *matrixColSize)
{
    if(matrixSize == 0 || matrixSize==1)
        return;
    int row = matrixSize / matrixColSize[0];
    int col = matrixColSize[0];
    int y, x;
    for (y = 0; y < row; y++){
        for (x = 0; x < col; x++){
            swap(&matrix[y][x], &matrix[row-1-y][col-1-x]);
        }
    }
    for (y = 0; y < row/2; y++){
        for (x = 0; x < col; x++){
            swap(&matrix[y][x], &matrix[row-1-y][x]);
        }
    }
}