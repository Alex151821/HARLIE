#if !defined(__RAW_H)
#define __RAW_H


// The modint raw data type, unsigned if possible
typedef unsigned long long rawtype;


const rawtype MAXMODULUS = 0xFFFFFFFFFFFFFFFFULL;
const rawtype MAXRAW = 0xFFFFFFFFFFFFFFFFULL;
const int RAWBITS = 64;

// Base (must be BASEDIGIT^BASEDIGITS = BASE < all MODULI)
const rawtype BASE = 10000000000000000000ULL;
const rawtype BASEDIGIT = 10;
const int BASEDIGITS = 19;
const rawtype BASEFACTORS[] = {2, 5};           // All prime factors of BASE
const int NBASEFACTORS = 2;                     // Number of prime factors of BASE

const rawtype MODULI[3] = {18446744069414584321ULL, 18446744056529682433ULL, 18446742974197923841ULL};     // upto n = 3*2^32
const rawtype PRIMITIVEROOTS[3] = {7, 10, 19};
const rawtype WFTAMODULI[3] = {0, 0, 0};                // not used
const rawtype WFTAPRIMITIVEROOTS[3] = {0, 0, 0};

const size_t MAXTRANSFORMLENGTH = 6442450944UL; // Maximum transform length for these moduli


// Low-level inline functions

// x86-64 GCC

inline rawtype modmul (rawtype a, rawtype b, rawtype m)
{
    rawtype rl, rh, c;

    // double-width multiplication

    asm ("mulq %3" : "=a" (rl), "=d" (rh) : "%a" (a), "rm" (b) : "cc");

    // modulo reduction

    if (m == 18446744069414584321ULL)
    {
        // modulus == 2^64-2^32+1
        rawtype t;

        // 1st shift
        t = rh;
        c = rh << 32;
        rh >>= 32;
        t = rl - t;
        if (t > rl) rh--;

        rl = t + c;
        if (rl < t) rh++;

        // 2nd shift
        t = rh;
        c = rh << 32;
        rh >>= 32;
        t = rl - t;
        if (t > rl) rh--;

        rl = t + c;
        if (rl < t) rh++;


        // Final check
        return (rh || rl >= m ? rl - m : rl);
    }
    else if (m == 18446744056529682433ULL)
    {
        // modulus == 2^64-2^34+1
        rawtype t;

        // 1st shift
        t = rh;
        c = rh << 34;
        rh >>= 30;
        t = rl - t;
        if (t > rl) rh--;

        rl = t + c;
        if (rl < t) rh++;

        // 2nd shift
        t = rh;
        c = rh << 34;
        rh >>= 30;
        t = rl - t;
        if (t > rl) rh--;

        rl = t + c;
        if (rl < t) rh++;

        // 3rd shift
        t = rh;
        c = rh << 34;
        rh >>= 30;
        t = rl - t;
        if (t > rl) rh--;

        rl = t + c;
        if (rl < t) rh++;


        // Final check
        return (rh || rl >= m ? rl - m : rl);
    }
    else
    {
        // modulus == 2^64-2^40+1
        rawtype t;

        // 1st shift
        t = rh;
        c = rh << 40;
        rh >>= 24;
        t = rl - t;
        if (t > rl) rh--;

        rl = t + c;
        if (rl < t) rh++;

        // 2nd shift
        t = rh;
        c = rh << 40;
        rh >>= 24;
        t = rl - t;
        if (t > rl) rh--;

        rl = t + c;
        if (rl < t) rh++;

        // 3rd shift
        t = rh;
        c = rh << 40;
        rh >>= 24;
        t = rl - t;
        if (t > rl) rh--;

        rl = t + c;
        if (rl < t) rh++;

        // Final check
        return (rh || rl >= m ? rl - m : rl);
    }
}

inline rawtype modadd (rawtype a, rawtype b, rawtype m)
{
    rawtype r;

    r = a + b;
    return (r < a || r >= m ? r - m : r);
}

inline rawtype modsub (rawtype a, rawtype b, rawtype m)
{
    rawtype r;

    r = a - b;
    return (a < b ? r + m : r);
}


#endif  // __RAW_H
