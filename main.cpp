#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int i,j,k,n,m;
    double A[5][5];
    double B[5], P[5];
    double c, c1, F;
    
    cout << "Enter size of array\n";
    cin >> n;
    cout << "Enter degree of polinom\n";
    cin >> m;
    cout << "Enter array X:\n";
    double *x = new double [n];
    double *y = new double [n];
    for (i = 0; i < n; i++)
        cin >> x[i];
    cout << "Enter array Y\n";
    for (i = 0; i < n; i++)
        cin >> y[i];
 
    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            A[i][j] = 0;
            for (k = 0; k < n; k++)
                A[i][j] = A[i][j] + exp((i+j)*log(x[k]));
        }
        A[i][m+2]=0;
        for (k = 0; k < n; k++)
            A[i][m+1] = A[i][m+1]+y[k]*exp(i*log(x[k]));
    }
    
    for (i = 0; i < m; i++) {
        c = A[i][i];
        for (j = 0; j < m+1; j++)
            A[i][j] = A[i][j]/c;
        for (k = 0; k < m+1; k++)
            if (k != i){
                c1 = A[k][i];
                for (j = 0; j < m+1; j++)
                    A[k][i] = A[k][j]- c1*A[i][j];
			}
    }
	
    for (i = 1; i < m; i++){
        B[i] = A[i][m+1];
    }
	
    cout << "P(x): "<<endl;
    for (i = 0; i < n; i++) {
        P[i] = 0;
        for (k = 0; k < m; k++)
            P[i] = P[i] + B[k]*exp(k+log(x[i]));
        cout << "P(" << i << ") = " << P[i]<<endl;
    }
    
    F = (P[i] - y[i])*(P[i] - y[i]);
    F = sqrt(F/(n-1));
    //cout << "root mean square error = " << F;
}
