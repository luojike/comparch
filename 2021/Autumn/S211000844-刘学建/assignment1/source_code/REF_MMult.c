/* Create macros so that the matrices are stored in column-major order */

#define A(i,j) a[ (i)*lda + (j) ]
#define B(i,j) b[ (i)*ldb + (j) ]
#define C(i,j) c[ (i)*ldc + (j) ]

/* Routine for computing C = A * B + C */

void REF_MMult( int m, int n, int p, double *a, int lda, 
                                    double *b, int ldb,
                                    double *c, int ldc )
{
  int i, j, k;

  for ( i=0; i<m; i++ ){
    for ( j=0; j<n; j++ ){
      for ( k=0; k<p; k++ ){
		C( i,j ) = C( i,j ) +  A( i,k ) * B( k,j );
      }
    }
  }
}


  
