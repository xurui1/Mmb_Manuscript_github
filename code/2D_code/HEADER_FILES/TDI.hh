/*
  In this header-file we have the algorithm for the tri-diagonal matrix solver
  For more general informaiton, visit: (https://en.wikipedia.org/wiki/Tridiagonal_matrix_algorithm)
  Order: Ml, Mm, Mu, RightVerctor, size
*/
void TDI(double* a, double* b, double* c, double* d, int n) { 

  // since we start from x0 (not x1)
  n--; 
  c[0] /= b[0];
  d[0] /= b[0];
  
  for (int i = 1; i < n; i++) {
    c[i] /= b[i] - a[i]*c[i-1];
    d[i] = (d[i] - a[i]*d[i-1]) / (b[i] - a[i]*c[i-1]);
  }
  
  d[n] = (d[n] - a[n]*d[n-1]) / (b[n] - a[n]*c[n-1]);
  
  for (int i = n; i-- > 0;) {
    d[i] -= c[i]*d[i+1];
  }
  return;
  
}
