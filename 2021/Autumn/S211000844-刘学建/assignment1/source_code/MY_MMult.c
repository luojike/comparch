/* Create macros so that the matrices are stored in row-major order */

#define A(i,j) a[ (i)*lda + (j) ]
#define B(i,j) b[ (i)*ldb + (j) ]
#define C(i,j) c[ (i)*ldc + (j) ]

/* Routine for computing C = A * B + C */

void MY_MMult_ijk( int m, int n, int p, double *a, int lda, 
									double *b, int ldb,
									double *c, int ldc)
{
  int i, j, k;

  for ( i=0; i<m; i++ ){        /* Loop over the rows of C */
    for ( j=0; j<n; j++ ){        /* Loop over the columns of C */
		register double sum = 0;
		for ( k=0; k<p; k++ ){        /* Update C( i,j ) with the inner
										product of the ith row of A and
										the jth column of B */
			sum += A(i,k) * B(k,j);
		}
		C(i,j) = sum;
    }
  }
}

void MY_MMult_jik( int m, int n, int p, double *a, int lda, 
									double *b, int ldb,
									double *c, int ldc)
{
  int i, j, k;

  for ( j=0; j<n; j++ ){        /* Loop over the columns of C */
    for ( i=0; i<m; i++ ){        /* Loop over the rows of C */
		register double sum = 0;
		for ( k=0; k<p; k++ ){        /* Update C( i,j ) with the inner
										product of the ith row of A and
										the jth column of B */
			sum += A(i,k) * B(k,j);
		}
		C(i,j) = sum;
    }
  }
}

void MY_MMult_ikj( int m, int n, int p, double *a, int lda, 
									double *b, int ldb,
									double *c, int ldc)
{
  int i, j, k;

  for ( i=0; i<m; i++ ){        
    for ( k=0; k<p; k++ ){        
		register double r = A(i,k);
		for ( j=0; j<n; j++ ){        
			C(i,j) += r * B(k,j);
		}
    }
  }
}

void MY_MMult_kij( int m, int n, int p, double *a, int lda, 
									double *b, int ldb,
									double *c, int ldc)
{
  int i, j, k;

  for ( k=0; k<p; k++ ){        
    for ( i=0; i<m; i++ ){        
		register double r = A(i,k);
		for ( j=0; j<n; j++ ){        
			C(i,j) += r * B(k,j);
		}
    }
  }
}

void MY_MMult_jki( int m, int n, int p, double *a, int lda, 
									double *b, int ldb,
									double *c, int ldc)
{
  int i, j, k;

  for ( j=0; j<n; j++ ){        
    for ( k=0; k<p; k++ ){        
		register double r = B(k,j);
		for ( i=0; i<m; i++ ){        
			C(i,j) += A(i,k) * r;
		}
    }
  }
}

void MY_MMult_kji( int m, int n, int p, double *a, int lda, 
									double *b, int ldb,
									double *c, int ldc)
{
  int i, j, k;

  for ( k=0; k<p; k++ ){        
    for ( j=0; j<n; j++ ){        
		register double r = B(k,j);
		for ( i=0; i<m; i++ ){        
			C(i,j) += A(i,k) * r;
		}
    }
  }
}
