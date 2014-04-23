#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RAND 10

int **allocate_array_2d( int x, int y ){
    if( ( x == 0 ) || ( y == 0 ) )
        return NULL;

    int **ptr;
    ptr = (int**) malloc( x * sizeof( int* ) );
    
    for( int i = 0; i < x; ++i )
        ptr[i] = (int*) malloc( y * sizeof( int ) );

    return ptr;
}

void rand_2d( int **A, int x, int y ){ 
    srand(time(NULL));

    for( int i = 0; i < x; ++i ){
        for( int j = 0; j < y; ++j ){
            A[i][j] = rand() % RAND + 1;
        }
    }
}

void print_array_2d( int **A, int x, int y ){
    printf("{");
    for( int i = 0; i < x; ++i ){
        printf("{");
        for( int j = 0; j < y; ++j )
            printf("%d,", A[i][j]);
        printf("\b},");
    }
    printf("\b}\n");
}

int **matrix_multi( int **A, int **B, int a, int b, int c ){
    int** C = allocate_array_2d( a, c );

    for( int i = 0; i < a; ++i )
        for( int j = 0; j < c; ++j ){
            C[i][j] = 0;
            for( int k = 0; k < b; ++k )
                C[i][j] += A[i][k] * B[k][j];
        }
    return C;
}

#ifndef TEST

int main(){
    int n, m, p;
    printf("Give dimensions: n, m, p: ");
    scanf("%d %d %d", &n, &m, &p);

    int **A = allocate_array_2d( n, m ), 
        **B = allocate_array_2d( m, p ), 
        **C = allocate_array_2d( n, p );

    rand_2d( A, n, m );
    rand_2d( B, m, p );

    print_array_2d( A, n, m );
    print_array_2d( B, m, p );

    C = matrix_multi( A, B, n, m, p );
    print_array_2d( C, n, p );

    return 0;
}

#endif
