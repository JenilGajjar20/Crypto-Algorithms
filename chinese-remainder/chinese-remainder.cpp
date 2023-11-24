#include <iostream>
#include <vector>
using namespace std;

int findInv(int a, int m)
{
    int m0 = m, q, t;
    int x0 = 0, x1 = 1;
    int itr = 0;

    if (m == 1)
        return 0;

    while (a > 1)
    {
        itr++;
        cout << "itr: " << itr << endl;

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

int findMinX(vector<int> num, vector<int> rem, int size, int prod)
{
    int ans = 0;

    int pp;
    for (int i = 0; i < size; i++)
    {
        pp = prod / num[i];
        cout << "pp: " << pp << endl;
        ans += rem[i] * pp * findInv(pp, num[i]);
    }

    return ans % prod;
}

int main()
{
    int size, prod = 1;
    cout << "Size: ";
    cin >> size;

    // Entering numbers
    vector<int> num(size);
    for (int i = 0; i < size; i++)
    {
        cout << "Enter numbers: ";
        cin >> num[i];
    }

    // Calculating Product of three numbers
    for (int i = 0; i < size; i++)
        prod *= num[i];

    cout << "Product of numbers: " << prod << endl;

    // Entering remainders
    vector<int> rem(size);
    for (int i = 0; i < size; i++)
    {
        cout << "Enter remainders: ";
        cin >> rem[i];
    }

    int result = findMinX(num, rem, size, prod);
    cout << "Result: " << result << endl;

    return 0;
}