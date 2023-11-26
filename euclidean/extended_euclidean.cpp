#include <iostream>
using namespace std;

int gcdExtended(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    *x = y1 - (b % a) * x1;
    *y = x1;

    return gcd;
}

int main()
{
    int t;
    cout << "Number of test cases: ";
    cin >> t;

    while (t--)
    {
        int x, y, a, b;

        cout << "a: ";
        cin >> a;

        cout << "b: ";
        cin >> b;

        int g = gcdExtended(a, b, &x, &y);
        cout << "GCD of " << a << " and " << b << " is: " << g << endl;
    }

    return 0;
}