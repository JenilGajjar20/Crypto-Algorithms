#include <iostream>
#include <string>
using namespace std;

int gcd_extended(int a, int b, int &x, int &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1;
    int gcd = gcd_extended(b % a, a, x1, y1);

    x = y1 - (b / a) * x1;
    y = x1;

    return gcd;
}

int find_inverse(int a, int m)
{
    int x, y;
    int gcd = gcd_extended(a, m, x, y);

    if (gcd != 1)
        throw invalid_argument("Inverse doesn't exist for the given key.");

    return (x % m + m) % m; // Ensure a positive result
}

string affine_encrypt(const string &message, int a, int b, int m)
{
    string encrypted;
    for (char c : message)
    {
        if (isalpha(c))
        {
            int x = c - 'A';
            int encrypted_char = (a * x + b) % m;
            encrypted += static_cast<char>(encrypted_char + 'A');
        }
        else
            encrypted += c;
    }
    return encrypted;
}

string affine_decrypt(const string &ciphertext, int a, int b, int m)
{
    int a_inv = find_inverse(a, m);
    string decrypted;
    for (char c : ciphertext)
    {
        if (isalpha(c))
        {
            int y = c - 'A';
            int decrypted_char = (a_inv * (y - b + m)) % m;
            decrypted += static_cast<char>(decrypted_char + 'A');
        }
        else
            decrypted += c;
    }
    return decrypted;
}

int main()
{
    string message;
    int a = 3, b, m;

    cout << "Enter the message to encrypt: ";
    cin >> message;
    cout << "Enter the value of 'b' (encryption key): ";
    cin >> b;
    m = 26;

    for (char &c : message)
        c = toupper(c);

    string encrypted_message = affine_encrypt(message, a, b, m);
    cout << "Encrypted message: " << encrypted_message << endl;

    string decrypted_message = affine_decrypt(encrypted_message, a, b, m);
    cout << "Decrypted message: " << decrypted_message << endl;

    return 0;
}
