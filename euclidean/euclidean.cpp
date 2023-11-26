#include <iostream>

// finding gcd
#include "../partials/find_gcd.cpp"

using namespace std;

int main()
{
    long long t;
    cout << "Number of test cases: ";
    cin >> t;

    while (t--)
    {
        long long a, b;

        cout << "a: ";
        cin >> a;

        cout << "b: ";
        cin >> b;

        long long result = gcd(a, b);
        cout << "GCD of " << a << " and " << b << ": " << result << endl;
    }
    return 0;
}