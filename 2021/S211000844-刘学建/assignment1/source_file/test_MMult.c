#include <stdio.h>
// #include <malloc.h>
#include <stdlib.h>

#include "parameters.h"

void REF_MMult(int, int, int, double *, int, double *, int, double *, int );
void MY_MMult_ijk(int, int, int, double *, int, double *, int, double *, int );
void MY_MMult_jik(int, int, int, double *, int, double *, int, double *, int );
void MY_MMult_ikj(int, int, int, double *, int, double *, int, double *, int );
void MY_MMult_kij(int, int, int, double *, int, double *, int, double *, int );
void MY_MMult_jki(int, int, int, double *, int, double *, int, double *, int );
void MY_MMult_kji(int, int, int, double *, int, double *, int, double *, int );
void copy_matrix(int, int, double *, int, double *, int );
void random_matrix(int, int, double *, int);
void zero_matrix(int, int, double *, int);
double compare_matrices( int, int, double *, int, double *, int );

double dclock();

int main()
{
  int 
    p, 
    m, n, k,
    lda, ldb, ldc, 
    rep;

  double
    dtime, dtime_best,        
    gflops, 
    diff;

  double 
    *a, *b, *c, *cref, *cold;    
  
  //printf( "MY_MMult = [\n" );
  printf( "type\tsize\ttime\tdiff\n");
    
  for ( p=PFIRST; p<=PLAST; p+=PINC ){
    m = ( M == -1 ? p : M );
    n = ( N == -1 ? p : N );
    k = ( K == -1 ? p : K );

    gflops = 2.0 * m * n * k * 1.0e-09;

    lda = ( LDA == -1 ? k : LDA );
    ldb = ( LDB == -1 ? n : LDB );
    ldc = ( LDC == -1 ? n : LDC );

    /* Allocate space for the matrices */
    /* Note: I create an extra column in A to make sure that
       prefetching beyond the matrix does not cause a segfault */
    a = ( double * ) malloc( m * lda * sizeof( double ) );  
    b = ( double * ) malloc( k * ldb * sizeof( double ) );
    c = ( double * ) malloc( m * ldc * sizeof( double ) );
    cold = ( double * ) malloc( m * ldc * sizeof( double ) );
    cref = ( double * ) malloc( m * ldc * sizeof( double ) );

    /* Generate random matrices A, B, Cold */
    random_matrix( m, k, a, lda );
    random_matrix( k, n, b, ldb );
    zero_matrix( m, n, cold, ldc );

    copy_matrix( m, n, cold, ldc, cref, ldc );

    /* Run the reference implementation so the answers can be compared */

    REF_MMult( m, n, k, a, lda, b, ldb, cref, ldc );

    /* Time the ijk implementation */
    for ( rep=0; rep<NREPEATS; rep++ ){
      copy_matrix( m, n, cold, ldc, c, ldc );

      /* Time your implementation */
      dtime = dclock();
      MY_MMult_ijk( m, n, k, a, lda, b, ldb, c, ldc );
      dtime = dclock() - dtime;
      if ( rep==0 )
	        dtime_best = dtime;
      else
	        dtime_best = ( dtime < dtime_best ? dtime : dtime_best );
    }
    diff = compare_matrices( m, n, c, ldc, cref, ldc );
    printf( "ijk\t%d\t%le\t%le\n", p, dtime_best, diff );
    
    /* Time the jik implementation */
    for ( rep=0; rep<NREPEATS; rep++ ){
      copy_matrix( m, n, cold, ldc, c, ldc );

      /* Time your implementation */
      dtime = dclock();
      MY_MMult_jik( m, n, k, a, lda, b, ldb, c, ldc );
      dtime = dclock() - dtime;
      if ( rep==0 )
	        dtime_best = dtime;
      else
	        dtime_best = ( dtime < dtime_best ? dtime : dtime_best );
    }
    diff = compare_matrices( m, n, c, ldc, cref, ldc );
    printf( "jik\t%d\t%le\t%le\n", p, dtime_best, diff );
    
    /* Time the ikj implementation */
    for ( rep=0; rep<NREPEATS; rep++ ){
      copy_matrix( m, n, cold, ldc, c, ldc );

      /* Time your implementation */
      dtime = dclock();
      MY_MMult_ikj( m, n, k, a, lda, b, ldb, c, ldc );
      dtime = dclock() - dtime;
      if ( rep==0 )
	        dtime_best = dtime;
      else
	        dtime_best = ( dtime < dtime_best ? dtime : dtime_best );
    }
    diff = compare_matrices( m, n, c, ldc, cref, ldc );
    printf( "ikj\t%d\t%le\t%le\n", p, dtime_best, diff );
    
    /* Time the kij implementation */
    for ( rep=0; rep<NREPEATS; rep++ ){
      copy_matrix( m, n, cold, ldc, c, ldc );

      /* Time your implementation */
      dtime = dclock();
      MY_MMult_kij( m, n, k, a, lda, b, ldb, c, ldc );
      dtime = dclock() - dtime;
      if ( rep==0 )
	        dtime_best = dtime;
      else
	        dtime_best = ( dtime < dtime_best ? dtime : dtime_best );
    }
    diff = compare_matrices( m, n, c, ldc, cref, ldc );
    printf( "kij\t%d\t%le\t%le\n", p, dtime_best, diff );
    
    /* Time the jki implementation */
    for ( rep=0; rep<NREPEATS; rep++ ){
      copy_matrix( m, n, cold, ldc, c, ldc );

      /* Time your implementation */
      dtime = dclock();
      MY_MMult_jki( m, n, k, a, lda, b, ldb, c, ldc );
      dtime = dclock() - dtime;
      if ( rep==0 )
	        dtime_best = dtime;
      else
	        dtime_best = ( dtime < dtime_best ? dtime : dtime_best );
    }
    diff = compare_matrices( m, n, c, ldc, cref, ldc );
    printf( "jki\t%d\t%le\t%le\n", p, dtime_best, diff );
    
    /* Time the kji implementation */
    for ( rep=0; rep<NREPEATS; rep++ ){
      copy_matrix( m, n, cold, ldc, c, ldc );

      /* Time your implementation */
      dtime = dclock();
      MY_MMult_kji( m, n, k, a, lda, b, ldb, c, ldc );
      dtime = dclock() - dtime;
      if ( rep==0 )
	        dtime_best = dtime;
      else
	        dtime_best = ( dtime < dtime_best ? dtime : dtime_best );
    }
    diff = compare_matrices( m, n, c, ldc, cref, ldc );
    printf( "kji\t%d\t%le\t%le\n", p, dtime_best, diff );
    
    
    
    fflush( stdout );

    free( a );
    free( b );
    free( c );
    free( cold );
    free( cref );
  }

  //printf( "];\n" );

  exit( 0 );
}

