#include <iostream>
#include "fir.h"

using namespace std;

int main()
{
    const len_t N = 4;
    const len_t M = 4;   
    int k; 
    double coef[M] = {1.0, 1.0, 1.0, 1.0};
    double x[N] = {0.2, 0.3, 0.2, 0.3};
    double y[N];

    Fir filter1(coef, M);
    cout << filter1.M() << endl;
    
    filter1.filter(x, y, N);

    for(k = 0; k < N; k ++)
    {
        cout << y[k] << ' ';
    }
    cout << endl;
   
    return 0;
}