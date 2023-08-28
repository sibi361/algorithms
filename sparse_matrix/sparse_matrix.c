#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_ROWS 4
#define DEFAULT_COLUMNS 4

typedef struct
{
    int row, col, val;
} sparse;

int m, n;

int get_matrix(int mat[][n], int rows, int cols);
int get_matrix_non_zero_count(int mat[][n], int rows, int cols);
void convert_to_sparse_matrix(int mat[][n], int rows, int cols,
                              sparse mat_sparse[], int *non_zero_count);
void print_sparse_matrix(sparse *mat_sparse, int non_zero_count);
void print_sparse_matrix_as_normal_matrix(sparse *mat_sparse);
void print_matrix(int mat[][n], int rows, int cols);

void main()
{
    int non_zero_count;
    // printf("Enter number of rows and cols as m n\n");
    // scanf("%d %d", &m, &n);

    m = DEFAULT_ROWS;
    n = DEFAULT_COLUMNS;

    // int mat[m][n];
    // printf("Enter matrix:\n");
    // non_zero_count = get_matrix(mat, m, n);

    // test cases
    // int mat[][DEFAULT_COLUMNS] = {{1, 0, 0, 0}, {0, 2, 0, 0}, {0, 0, 3, 0}, {0, 0, 0, 4}};
    int mat[][DEFAULT_COLUMNS] = {{1, 0, 0, 0}, {0, 0, 44, 0}, {0, 0, 3, 0}, {12, 0, 0, 4}};

    non_zero_count = get_matrix_non_zero_count(mat, m, n);
    if (non_zero_count >= m * n / 2)
    {
        printf("\nERROR: Given matrix is NOT sparse as count(zeroes) < \
count(non-zero elements)\n");
        exit(0);
    }

    sparse mat_sparse[non_zero_count]; // less than half will be non-zero

    printf("Given matrix:\n");
    print_matrix(mat, m, n);

    convert_to_sparse_matrix(mat, m, n, mat_sparse, &non_zero_count);

    printf("\nGiven matrix sparse matrix representation:\n");
    print_sparse_matrix(mat_sparse, non_zero_count);

    printf("\nAbove representation being printed as normal matrix:\n");
    print_sparse_matrix_as_normal_matrix(mat_sparse);

    printf("\nsizeof(mat) = %d\n", sizeof(mat));
    printf("sizeof(mat_sparse) = %d\n\n", sizeof(mat_sparse));
    printf("sizeof(mat_sparse[0]) = %d\n\n", sizeof(mat_sparse[0]));
}

int get_matrix(int mat[][n], int rows, int cols)
{
    int non_zero_count = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &mat[i][j]);
            if (mat[i][j] != 0)
                ++non_zero_count;
        }
    return non_zero_count;
}

int get_matrix_non_zero_count(int mat[][n], int rows, int cols)
{
    int non_zero_count = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (mat[i][j] != 0)
                ++non_zero_count;
    return non_zero_count;
}

void convert_to_sparse_matrix(int mat[][n], int rows, int cols,
                              sparse mat_sparse[], int *non_zero_count)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (mat[i][j] != 0)
            {
                ++*non_zero_count;
                mat_sparse[*non_zero_count].row = i;
                mat_sparse[*non_zero_count].col = j;
                mat_sparse[*non_zero_count].val = mat[i][j];
            }

    // adding metadata
    mat_sparse[0].row = rows;
    mat_sparse[0].col = cols;
    mat_sparse[0].val = *non_zero_count;
}

void print_sparse_matrix(sparse *mat_sparse, int non_zero_count)
{
    printf("id\tRow\tColumn\tValue\n");

    for (int i = 0; i <= non_zero_count; i++)
        printf("%d\t%d\t%d\t%d\n",
               i,
               mat_sparse[i].row,
               mat_sparse[i].col,
               mat_sparse[i].val);
}

void print_sparse_matrix_as_normal_matrix(sparse *mat_sparse)
{
    int rows = mat_sparse[0].row,
        cols = mat_sparse[0].col,
        non_zero_k = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            if (i == mat_sparse[non_zero_k].row &&
                j == mat_sparse[non_zero_k].col)
                printf("%d\t", mat_sparse[non_zero_k++].val);
            else
                printf("0\t");
        printf("\n");
    }
}

void print_matrix(int mat[][n], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            printf("%d\t", mat[i][j]);
        printf("\n");
    }
}
