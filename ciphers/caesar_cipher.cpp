#include <iostream>
using namespace std;

string encryptCaesar(string message, int shift)
{
    string encryptedMessage = "";
    for (int i = 0; i < message.length(); i++)
    {
        if (isalpha(message[i]))
        {
            char base = (isupper(message[i])) ? 'A' : 'a';
            char encryptedChar = ((message[i] - base + shift) % 26) + base;
            encryptedMessage += encryptedChar;
        }
        else
        {
            encryptedMessage += message[i];
        }
    }
    return encryptedMessage;
}

string decryptCaesar(string encryptedMessage, int shift)
{
    string decryptedMessage = "";
    for (int i = 0; i < encryptedMessage.length(); i++)
    {
        if (isalpha(encryptedMessage[i]))
        {
            char base = (isupper(encryptedMessage[i])) ? 'A' : 'a';
            char decryptedChar = ((encryptedMessage[i] - base - shift + 26) % 26) + base;
            decryptedMessage += decryptedChar;
        }
        else
        {
            decryptedMessage += encryptedMessage[i];
        }
    }
    return decryptedMessage;
}

int main()
{
    string message = "NIRMA";
    int shift = 3;

    string encrypted = encryptCaesar(message, shift);
    string decrypted = decryptCaesar(encrypted, shift);

    cout << "Original Message: " << message << endl;
    cout << "Encrypted Message: " << encrypted << endl;
    cout << "Decrypted Message: " << decrypted << endl;

    return 0;
}
