#include <iostream>
#include <random>
#include <chrono>
#include <vector>
using namespace std;

class LCRNG
{
public:
    LCRNG(unsigned long long seed, unsigned long long a, unsigned long long c, unsigned long long m)
        : seed(seed), a(a), c(c), m(m) {}

    // Function to generate a random number
    unsigned long long generateRandomNumber()
    {
        seed = (a * seed + c) % m;
        return seed;
    }

private:
    unsigned long long seed; // Current seed value
    unsigned long long a;    // Multiplier
    unsigned long long c;    // Increment
    unsigned long long m;    // Modulus
};

int main()
{
    unsigned long long seed, a, c, m, numToGenerate;

    cout << "Enter the seed value: ";
    cin >> seed;

    cout << "Enter the multiplier (a): ";
    cin >> a;

    cout << "Enter the increment (c): ";
    cin >> c;

    cout << "Enter the modulus (m): ";
    cin >> m;

    cout << "Enter the number of random numbers to generate: ";
    cin >> numToGenerate;

    LCRNG lcrng(seed, a, c, m);

    cout << "\nGenerated Numbers:" << endl;
    for (unsigned long long i = 0; i < numToGenerate; i++)
        cout << lcrng.generateRandomNumber() << " ";

    return 0;
}
