#include "ap.h"


// The baseint functions
// Baseints are basically bigints, but the base is not the rawtype maximum, but Base

// Adds n words from s to d, returns overflow carry bit
rawtype baseadd (rawtype *dest, rawtype *src1, rawtype *src2, size_t len, rawtype carry)
{
    size_t t;

    for (t = len; t--;)
    {
        dest[t] = src1[t] + carry;
        if ((src2 && (dest[t] += src2[t]) < src2[t]) || dest[t] >= Base)
        {
            dest[t] -= Base;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
    }

    return carry;
}

// Subtracts n words s from d, returns subtract carry bit (1)
rawtype basesub (rawtype *dest, rawtype *src1, rawtype *src2, size_t len, rawtype carry)
{
    size_t t;
    rawtype tmp, tmp2;

    for (t = len; t--;)
    {
        tmp = (src1 ? src1[t] : 0);
        tmp2 = (src2 ? src2[t] : 0) + carry;
        if ((dest[t] = tmp - tmp2) > tmp)
        {
            dest[t] += Base;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
    }

    return carry;
}

// Multiplicates n words in s by f, adds s2, stores result to d, returns overflow word
rawtype basemuladd (rawtype *dest, rawtype *src1, rawtype *src2, rawtype src3, size_t len, rawtype carry)
{
    size_t t;
    rawtype rl, rh;

    for (t = len; t--;)
    {
        asm ("mulq %3; addq %4, %%rax; adcq $0, %%rdx" : "=a" (rl), "=d" (rh) : "%a" (src1[t]), "rm" (src3), "rm" (carry) : "cc");
        if (src2) asm ("addq %4, %0; adcq $0, %1" : "=a" (rl), "=d" (rh) : "0" (rl), "1" (rh), "rm" (src2[t]) : "cc");
        asm ("divq %4" : "=a" (carry), "=d" (dest[t]) : "a" (rl), "d" (rh), "rm" (Base) : "cc");
    }

    return carry;
}

// Divides n words in s by f, stores result in d, returns remainder
rawtype basediv (rawtype *dest, rawtype *src1, rawtype src2, size_t len, rawtype carry)
{
    size_t t;
    rawtype rl, rh;

    for (t = 0; t < len; t++)
    {
        asm ("mulq %3" : "=a" (rl), "=d" (rh) : "%a" (carry), "rm" (Base) : "cc");
        if (src1) asm ("addq %4, %0; adcq $0, %1" : "=a" (rl), "=d" (rh) : "0" (rl), "1" (rh), "rm" (src1[t]) : "cc");
        asm ("divq %4" : "=a" (dest[t]), "=d" (carry) : "a" (rl), "d" (rh), "rm" (src2) : "cc");

    }

    return carry;
}
