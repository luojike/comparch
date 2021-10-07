#include <stdlib.h>

#define A(i,j) a[ (i)*lda + (j) ]

void zero_matrix( int m, int n, double *a, int lda )
{
  int i,j;

  for ( i=0; i<m; i++ )
    for ( j=0; j<n; j++ )
      A( i,j ) = 0.0;
}
