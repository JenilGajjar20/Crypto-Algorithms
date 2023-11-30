#include <iostream>
#include <vector>

// finding the inverse
#include "../partials/find_inv.cpp"

using namespace std;

// This function finds the minimum x such that x % num[i] is equal to rem[i] for all i
long long findMinX(vector<long long> num, vector<long long> rem, long long size, long long prod)
{
    long long ans = 0;

    long long pp;
    for (long long i = 0; i < size; i++)
    {
        pp = prod / num[i];
        cout << "pp: " << pp << endl;
        ans += rem[i] * pp * findInv(pp, num[i]);
    }

    return ans % prod;
}

int main()
{
    long long size, prod = 1;
    cout << "Size: ";
    cin >> size;

    // Entering numbers
    vector<long long> num(size);
    for (long long i = 0; i < size; i++)
    {
        cout << "Enter numbers: ";
        cin >> num[i];
    }

    // Calculating Product of numbers
    for (long long i = 0; i < size; i++)
        prod *= num[i];

    cout << "Product of numbers: " << prod << endl;

    // Entering remainders
    vector<long long> rem(size);
    for (long long i = 0; i < size; i++)
    {
        cout << "Enter remainders: ";
        cin >> rem[i];
    }

    long long result = findMinX(num, rem, size, prod);
    cout << "Result: " << result << endl;

    return 0;
}