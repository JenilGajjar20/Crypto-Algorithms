#include <iostream>
#include <string>
using namespace std;

string encryptTranspositionCipher(int key, string plaintext)
{
    string ciphertext = "";

    for (int col = 0; col < key; col++)
    {
        int pointer = col;
        while (pointer < plaintext.length())
        {
            ciphertext += plaintext[pointer];
            pointer += key;
        }
    }

    return ciphertext;
}

string decryptTranspositionCipher(int key, string cipherText)
{
    string plainText = "";

    int rows = (cipherText.length() + key - 1) / key;

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < key; col++)
        {
            int pointer = row + col * rows;
            if (pointer < cipherText.length())
                plainText += cipherText[pointer];
        }
    }

    return plainText;
}

int main()
{
    string plaintext;
    int key;

    cout << "Enter the plaintext: ";
    cin >> plaintext;

    cout << "Enter the key: ";
    cin >> key;

    string encryptedText = encryptTranspositionCipher(key, plaintext);
    cout << "Encrypted: " << encryptedText << endl;

    string decryptedText = decryptTranspositionCipher(key, encryptedText);
    cout << "Decrypted: " << decryptedText << endl;

    return 0;
}
