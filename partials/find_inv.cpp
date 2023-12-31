// This function calculates the modular multiplicative inverse of a module m using the extended euclidean algorithm

long long findInv(long long a, long long m)
{
    long long m0 = m, q, t;
    long long x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1)
    {
        q = a / m;

        t = m;

        m = a % m;
        a = t;

        t = x0;

        x0 = x1 - q * x0;

        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}