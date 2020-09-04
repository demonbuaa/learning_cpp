#ifndef _FIR_H_
#define _FIR_H_

typedef unsigned int len_t;

class Fir
{
    public:
        Fir(double *cp, len_t len); //constructor
        void filter(double *in, double *out, len_t n);
        void update_coef(double *cp, len_t);
        len_t M(void) const;
    private:
        len_t m;
        double *coef;
};

#endif

