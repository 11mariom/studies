#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

#ifndef TEST
#define TEST

#include <stdio.h>
#include "../src/main.c"

int init_suite( void ){ return 0; }
int clean_suite( void ){ return 0; }

#define MAX 3

/* 2d array test */

void test_2d_alloc( void ){
    CU_ASSERT_PTR_NULL( allocate_array_2d( 0, 0 ) );

    for( int a = 1; a < MAX; ++a ){
        for( int b = 1; b < MAX; ++b ){
            int** A = allocate_array_2d( a, b );

            for( int i = 0; i < a; ++i ){
                CU_ASSERT_PTR_NOT_NULL( A[i] );
            }
        }
    }
}

void test_2d_rand( void ){
    for( int a = 1; a < MAX; ++a ){
        for( int b = 1; b < MAX; ++b ){
            int** A = allocate_array_2d( a, b );
            rand_2d( A, a, b );

            for( int i = 0; i < a; ++i ){
                for( int j = 0; j < b; ++j ){
                    CU_ASSERT( A[i][j] > 0 );
                    CU_ASSERT( A[i][j] < RAND + 1 );
                }
            }
        }
    }
}

void test_multi( void ){
    int **A = allocate_array_2d( 3, 2 ),
        **B = allocate_array_2d( 2, 4 ),
        **C = allocate_array_2d( 3, 4 );
    A[0][0] = 2; A[0][1] = 1;
    A[1][0] = 4; A[1][1] = 9;
    A[2][0] = 7; A[2][1] = 3;
    B[0][0] = 2; B[0][1] = 5; B[0][2] = 3; B[0][3] = 9;
    B[1][0] = 1; B[1][1] = 5; B[1][2] = 2; B[1][3] = 9;
    int test[3][4] = {{5,15,8,27},{17,65,30,117},{17,50,27,90}};

    C = matrix_multi( A, B, 3, 2, 4 );

    for( int i = 0; i < 3; ++i ){
        for( int j = 0; j < 4; ++j ){
            CU_ASSERT_EQUAL( C[i][j], test[i][j] );
        }
    }
}

/* run tests */

int main( void ){
    CU_pSuite pSuite = NULL;

    /* initialize registry */
    if( CUE_SUCCESS != CU_initialize_registry() )
        return CU_get_error();

    /* add a suite to get */
    pSuite = CU_add_suite( "Matrix multiplication test", init_suite, clean_suite );
    if( NULL == pSuite ){
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add tests */
    if( (NULL == CU_add_test( pSuite, "Array allocation", test_2d_alloc) ) ||
        (NULL == CU_add_test( pSuite, "Inserting random values",  test_2d_rand) )  ||
        (NULL == CU_add_test( pSuite, "Multiplication", test_multi) ) ){
            CU_cleanup_registry();
            return CU_get_error();
    }

    /* run tests */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    printf("\n");
    CU_basic_show_failures( CU_get_failure_list() );
    printf("\n\n");

    CU_cleanup_registry();
    return CU_get_error();
}

#endif
