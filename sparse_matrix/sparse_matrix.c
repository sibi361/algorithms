#include <stdio.h>
#include <stdlib.h>

// #define DEFAULT_ROWS 3
// #define DEFAULT_COLUMNS 3
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
                              sparse mat_sparse[]);
void print_sparse_matrix(sparse *mat_sparse, int non_zero_count);
void print_sparse_matrix_as_normal_matrix(sparse *mat_sparse);
void print_matrix(int mat[][n], int rows, int cols);

void main()
{
    int non_zero_count, matrix_size;
    // printf("Enter number of rows and cols as m n\n");
    // scanf("%d %d", &m, &n);

    m = DEFAULT_ROWS;
    n = DEFAULT_COLUMNS;

    // int mat[m][n];
    // printf("Enter matrix:\n");
    // non_zero_count = get_matrix(mat, m, n);

    // test cases
    // few non-zero elements
    // int mat[][DEFAULT_COLUMNS] = {{1, 0, 0}, {0, 2, 0}, {0, 0, 0}};
    // many non-zero elements
    // int mat[][DEFAULT_COLUMNS] = {{1, 2, 0}, {0, -8, 0}, {0, 5, 0}};

    // few non-zero elements
    int mat[][DEFAULT_COLUMNS] = {{1, 0, 0, 0},
                                  {0, 2, 0, 0},
                                  {0, 0, 3, 0},
                                  {0, 0, 0, 4}};
    // many non-zero elements
    // int mat[][DEFAULT_COLUMNS] = {{1, 0, 0, 0},
    //                               {13, 0, 44, 0},
    //                               {0, -4, 3, 0},
    //                               {12, 0, 0, 4}};

    non_zero_count = get_matrix_non_zero_count(mat, m, n);
    matrix_size = m * n / 2;
    if (non_zero_count > matrix_size)
    {
        printf("\nERROR: Given matrix is NOT sparse as count(non-zero elements)\
[%d] is > half the matrix size[%d]\n\n",
               non_zero_count, matrix_size);
        exit(0);
    }

    sparse mat_sparse[non_zero_count]; // less than half will be non-zero

    printf("Given matrix:\n");
    print_matrix(mat, m, n);

    convert_to_sparse_matrix(mat, m, n, mat_sparse);

    printf("\nSparse matrix representation:\n");
    print_sparse_matrix(mat_sparse, non_zero_count);

    printf("\nSparse matrix representation being printed as normal matrix:\n");
    print_sparse_matrix_as_normal_matrix(mat_sparse);

    printf("\n\nsizeof(mat) = %d\n", sizeof(mat));
    printf("sizeof(mat_sparse) = %d\n", sizeof(mat_sparse));

    printf("\nHence it is observed that sparse matrix representation \
saves space in matrices of size greater than nine when they have very few \
non-zero elements as compared to the conventional two dimensional \
representation.\n\n");
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
                              sparse mat_sparse[])
{
    int k = 0; // non-zero count
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (mat[i][j] != 0)
            {
                ++k;
                mat_sparse[k].row = i;
                mat_sparse[k].col = j;
                mat_sparse[k].val = mat[i][j];
            }

    // adding metadata
    mat_sparse[0].row = rows;
    mat_sparse[0].col = cols;
    mat_sparse[0].val = k;
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
