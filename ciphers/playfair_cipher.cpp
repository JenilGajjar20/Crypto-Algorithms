#include <bits/stdc++.h>
using namespace std;
#define SIZE 30

void toLowerCase(char plain[], int ps)
{
    for (int i = 0; i < ps; i++)
    {
        if (plain[i] >= 'A' && plain[i] <= 'Z')
        {
            plain[i] += 'a' - 'A';
        }
    }
}

int removeSpaces(char *plain, int ps)
{
    int count = 0;
    for (int i = 0; i < ps; i++)
        if (plain[i] != ' ')
            plain[count++] = plain[i];

    plain[count] = '\0';
    return count;
}

void generateKeyTable(char key[], int ks, char keyT[5][5])
{
    int dicty[26] = {0};
    int i = 0, j = 0;

    for (int k = 0; k < ks; k++)
    {
        if (key[k] != 'j')
            dicty[key[k] - 'a'] = 2;
    }

    dicty['j' - 'a'] = 1;

    for (int k = 0; k < ks; k++)
    {
        if (dicty[key[k] - 'a'] == 2)
        {
            dicty[key[k] - 'a'] -= 1;
            keyT[i][j] = key[k];
            j++;
            if (j == 5)
            {
                i++;
                j = 0;
            }
        }
    }

    for (int k = 0; k < 26; k++)
    {
        if (dicty[k] == 0)
        {
            keyT[i][j] = (char)(k + 'a');
            j++;
            if (j == 5)
            {
                i++;
                j = 0;
            }
        }
    }
}

void search(char keyT[5][5], char a, char b, int arr[])
{
    for (int i = 0; i < 5; i++)
    {

        for (int j = 0; j < 5; j++)
        {

            if (keyT[i][j] == a)
            {
                arr[0] = i;
                arr[1] = j;
            }
            else if (keyT[i][j] == b)
            {
                arr[2] = i;
                arr[3] = j;
            }
        }
    }
}

int e_mod5(int a) { return (a % 5); }

int d_mod5(int a)
{
    if (a < 0)
        a += 5;
    return (a % 5);
}

int prepare(char str[], int ptrs)
{
    if (ptrs % 2 != 0)
    {
        str[ptrs] = 'x';
        str[ptrs + 1] = '\0';
        ptrs++;
    }
    return ptrs;
}

void encrypt(char str[], char keyT[5][5], int ps)
{

    for (int i = 0; i < ps; i += 2)
    {
        int a[4];
        search(keyT, str[i], str[i + 1], a);

        if (a[0] == a[2])
        {
            str[i] = keyT[a[0]][e_mod5(a[1] + 1)];
            str[i + 1] = keyT[a[0]][e_mod5(a[3] + 1)];
        }
        else if (a[1] == a[3])
        {
            str[i] = keyT[e_mod5(a[0] + 1)][a[1]];
            str[i + 1] = keyT[e_mod5(a[2] + 1)][a[1]];
        }
        else
        {
            str[i] = keyT[a[0]][a[3]];
            str[i + 1] = keyT[a[2]][a[1]];
        }
    }
}

void encryptByPlayfairCipher(char str[], char key[])
{
    char ps, ks, keyT[5][5];

    ks = strlen(key);
    ks = removeSpaces(key, ks);
    toLowerCase(key, ks);

    ps = strlen(str);
    toLowerCase(str, ps);
    ps = removeSpaces(str, ps);

    ps = prepare(str, ps);

    generateKeyTable(key, ks, keyT);

    encrypt(str, keyT, ps);
}

void decrypt(char str[], char keyT[5][5], int ps)
{
    for (int i = 0; i < ps; i += 2)
    {
        int a[4];
        search(keyT, str[i], str[i + 1], a);
        if (a[0] == a[2])
        {
            str[i] = keyT[a[0]][d_mod5(a[1] - 1)];
            str[i + 1] = keyT[a[0]][d_mod5(a[3] - 1)];
        }
        else if (a[1] == a[3])
        {
            str[i] = keyT[d_mod5(a[0] - 1)][a[1]];
            str[i + 1] = keyT[d_mod5(a[2] - 1)][a[1]];
        }
        else
        {
            str[i] = keyT[a[0]][a[3]];
            str[i + 1] = keyT[a[2]][a[1]];
        }
    }
}

void decryptByPlayfairCipher(char str[], char key[])
{
    char ps, ks, keyT[5][5];

    ks = strlen(key);
    ks = removeSpaces(key, ks);
    toLowerCase(key, ks);

    ps = strlen(str);
    toLowerCase(str, ps);
    ps = removeSpaces(str, ps);

    generateKeyTable(key, ks, keyT);

    decrypt(str, keyT, ps);
}

int main()
{
    char str[SIZE], key[SIZE];

    strcpy(key, "SEMESTER");
    cout << "Key text: " << key << "\n";

    strcpy(str, "UNIVERSITY");
    cout << "Plain text: " << str << "\n";

    encryptByPlayfairCipher(str, key);

    cout << "Cipher text: " << str << "\n";

    decryptByPlayfairCipher(str, key);

    cout << "Decrypted text: " << str << endl;

    return 0;
}