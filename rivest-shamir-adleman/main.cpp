#include <iostream>
#include <random>
#include <chrono>

// finding the inverse
#include "../partials/find_inv.cpp"

// finding gcd
#include "../partials/find_gcd.cpp"

using namespace std;

// Modular Exponentiation
long long Exponentiation(long long a, long long b, long long mod)
{
    long long f = 1;
    a = a % mod;

    while (b > 0)
    {
        // Check if b is odd.
        if (b % 2 == 1)
            f = (f * a) % mod;

        // Square a and reduce b by half.
        a = (a * a) % mod;
        b = b / 2;
    }

    return f;
}

int main()
{
    // Seed the random number generator with current time
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937_64 generator(seed);

    // Generating random prime number p
    long long p = uniform_int_distribution<long long>(10, 99)(generator);
    cout << "value of p: " << p << endl;

    // Generating random prime number q
    long long q = uniform_int_distribution<long long>(10, 99)(generator);
    cout << "value of q: " << q << endl;

    long long n = p * q; // Calculate n
    cout << "Value of n: " << n << endl;

    long long phi = (p - 1) * (q - 1); // Calculate phi
    cout << "Value of phi: " << phi << endl;

    // Generating random e between [2, phi - 1] as 1 < e < phi
    uniform_int_distribution<long long> _e(2, phi - 1);
    long long e = _e(generator);

    // check if gcd of e and phi is 1.
    while (gcd(e, phi) != 1)
        e = _e(generator);

    cout << "value of e: " << e << endl;

    // Calculating value of d using modular inverse
    long long d = findInv(e, phi);
    cout << "value of d: " << d << endl;

    // Generating a random message value between [0, n - 1]
    uniform_int_distribution<long long> message(0, n - 1);
    long long msg = message(generator);
    cout << "Value of Message: " << msg << endl;

    // Encrypt the message using the public key (e, n)
    long long c = Exponentiation(msg, e, n);
    cout << "Encrypted Data: " << c << endl;

    // Decrypt the message using the private key (d, n)
    long long m = Exponentiation(c, d, n);
    cout << "Decrypted Data: " << m << endl;

    // Check if the decrypted message matches the original generated message
    if (m == msg)
        cout << "Decryption successful";
    else
        cout << "Decryption failed";

    return 0;
}