#include "fir.h"

Fir::Fir(double *cp, len_t len)
{
    m = len;
    coef = new double[m];
    for(int k = 0; k < m; k ++)
    {
        coef[k] = cp[k];
    }
}

void Fir::filter(double* in, double* out, len_t n)
{
    double *buffer = new double[m];
    double y;
    double x;
    int k;

    for(k = 0; k < m; k ++)
    {
        buffer[k] = 0.0f;
    }

    for(int kn = 0; kn < n; kn ++)
    {
        x = in[kn];
        
        //shifting buffer
        for(k = m-1; k > 0; k --)
        {
            buffer[k] = buffer[k-1];
        }
        buffer[0] = x;

        //innder product
        y = 0.0f;
        for(k =0; k < m; k ++)
        {
            y += buffer[k] * coef[k];
        }
        out[kn] = y;
    }

}  

/* update FIR filter coefficients */
void Fir::update_coef(double *cp, len_t len)
{
    delete[] coef;
    m = len;
    coef = new double[m];
    for(int k = 0; k < m; k ++)
    {
        coef[k] = cp[k];
    }
}

/* return length of the filer */
len_t Fir::M(void) const
{
   return m;
}


