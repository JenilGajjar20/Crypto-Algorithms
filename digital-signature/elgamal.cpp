#include <iostream>
#include <cmath>
#include <cstdlib>

// finding the inverse
#include "../partials/find_inv.cpp"

// finding gcd
#include "../partials/find_gcd.cpp"

using namespace std;

long long mod_exp(long long base, long long exp, long long mod)
{
    long long result = 1;
    base = base % mod;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        exp /= 2;
        base = (base * base) % mod;
    }

    return result;
}

bool isPrime(long long &q)
{
    if (q <= 1)
        return false;

    for (long long i = 2; i <= sqrt(q); i++)
    {
        if (q % i == 0)
            return false;
    }

    return true;
}

bool isPrimitiveRoot(long long &a, long long &q)
{
    if (a <= 1 || a >= (q - 1))
        return false;

    for (long long i = 2; i <= sqrt(q - 1); i++)
    {
        if ((q - 1) % i == 0)
        {
            if (mod_exp(a, (q - 1) / i, q) == 1)
                return false;
        }
    }

    return true;
}

void generate_keyPair(long long &q, long long &a, long long &xA, long long &yA)
{
    if (!isPrime(q))
    {
        cout << "q must a prime number!" << endl;
        exit(1);
    }

    do
    {
        a = rand() % (q - 1) + 2;
    } while (!isPrimitiveRoot(a, q));

    xA = rand() % (q - 1) + 1;

    yA = mod_exp(a, xA, q);
}

void signature(long long &q, long long &a, long long &xA, long long &m, long long &s1, long long &s2)
{
    long long k;

    do
    {
        k = rand() % (q - 1) + 1;
    } while (gcd(k, q - 1) != 1);

    s1 = mod_exp(a, k, q);

    long long k_inv = findInv(k, q - 1);

    s2 = (k_inv * (m - xA * s1)) % (q - 1);

    if (s2 < 0)
        s2 += (q - 1);
}

bool verify(long long &q, long long &a, long long &yA, long long &m, long long &s1, long long &s2)
{
    long long v1 = mod_exp(a, m, q);
    long long v2 = (mod_exp(yA, s1, q) * mod_exp(s1, s2, q)) % q;

    return v1 == v2;
}

int main()
{
    long long q, a, xA, yA;
    cout << "Enter q (value must be a large prime number): ";
    cin >> q;
    generate_keyPair(q, a, xA, yA);

    long long m;
    cout << "Enter message value: ";
    cin >> m;

    if (m <= 0 || m >= (q - 1))
        m = m % q;

    cout << "Original message: " << m << endl;

    long long s1, s2;
    signature(q, a, xA, m, s1, s2);
    cout << "Signature: (" << s1 << ", " << s2 << ") " << endl;

    bool isVerified = verify(q, a, yA, m, s1, s2);
    if (isVerified)
        cout << "Signature is valid" << endl;
    else
        cout << "Signature is not valid" << endl;

    return 0;
}