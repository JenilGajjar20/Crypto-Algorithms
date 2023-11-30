#include <iostream>
#include <string>
using namespace std;

string encryptRailFence(string message, int rails)
{
    string encryptedMessage = "";

    char matrix[rails][message.length()];
    for (int i = 0; i < rails; i++)
    {
        for (int j = 0; j < message.length(); j++)
            matrix[i][j] = '\0';
    }

    int row = 0;
    int direction = 1;

    for (int i = 0; i < message.length(); i++)
    {
        matrix[row][i] = message[i];

        if (row == 0)
            direction = 1;
        else if (row == rails - 1)
            direction = -1;

        row += direction;
    }

    for (int i = 0; i < rails; i++)
    {
        for (int j = 0; j < message.length(); j++)
        {
            if (matrix[i][j] != '\0')
                encryptedMessage += matrix[i][j];
        }
    }

    return encryptedMessage;
}

string decryptRailFence(string encryptedMessage, int rails)
{
    string decryptedMessage = "";

    char matrix[rails][encryptedMessage.length()];
    for (int i = 0; i < rails; i++)
    {
        for (int j = 0; j < encryptedMessage.length(); j++)
            matrix[i][j] = '\0';
    }

    int row = 0;
    int direction = 1;

    for (int i = 0; i < encryptedMessage.length(); i++)
    {
        matrix[row][i] = '#';
        if (row == 0)
            direction = 1;
        else if (row == rails - 1)
            direction = -1;

        row += direction;
    }

    int index = 0;
    for (int i = 0; i < rails; i++)
    {
        for (int j = 0; j < encryptedMessage.length(); j++)
        {
            if (matrix[i][j] == '#' && index < encryptedMessage.length())
            {
                matrix[i][j] = encryptedMessage[index];
                index++;
            }
        }
    }

    row = 0;
    direction = 1;
    for (int i = 0; i < encryptedMessage.length(); i++)
    {
        decryptedMessage += matrix[row][i];

        if (row == 0)
            direction = 1;
        else if (row == rails - 1)
            direction = -1;

        row += direction;
    }

    return decryptedMessage;
}

int main()
{
    string message = "HELLO";
    int rails = 3;

    string encrypted = encryptRailFence(message, rails);
    string decrypted = decryptRailFence(encrypted, rails);

    cout << "Original Message: " << message << endl;
    cout << "Encrypted Message: " << encrypted << endl;
    cout << "Decrypted Message: " << decrypted << endl;

    return 0;
}
