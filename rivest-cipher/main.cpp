#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

// Function for encryption
void encryption(string plain_text, string key, int n)
{
    // The initial state vector array
    vector<int> S(1 << n);
    for (int i = 0; i < (1 << n); i++)
    {
        S[i] = i;
    }

    cout << "S: ";
    for (int i : S)
    {
        cout << i << " ";
    }
    cout << endl;

    vector<string> key_list;
    for (int i = 0; i < key.length(); i += n)
    {
        key_list.push_back(key.substr(i, n));
    }

    // Convert key_list to decimal
    for (string &k : key_list)
    {
        k = bitset<8>(k).to_string();
    }

    vector<string> pt;
    for (int i = 0; i < plain_text.length(); i += n)
    {
        pt.push_back(plain_text.substr(i, n));
    }

    // Convert plain_text to decimal
    for (string &p : pt)
    {
        p = bitset<8>(p).to_string();
    }

    cout << "Plain text (in array form): ";
    for (const string &p : pt)
    {
        cout << p << " ";
    }
    cout << endl;

    // Making key_list equal to the length of state vector
    int diff = S.size() - key_list.size();
    if (diff != 0)
    {
        for (int i = 0; i < diff; i++)
        {
            key_list.push_back(key_list[i]);
        }
    }

    cout << "Key list: ";
    for (const string &k : key_list)
    {
        cout << k << " ";
    }
    cout << endl
         << endl;

    // KSA algorithm
    int j = 0;
    int N = S.size();
    for (int i = 0; i < N; i++)
    {
        j = (j + S[i] + stoi(key_list[i], nullptr, 2)) % N;
        swap(S[i], S[j]);

        // Print the current state vector during each iteration
        cout << "KSA Iteration " << i + 1 << ": ";
        for (int s : S)
        {
            cout << s << " ";
        }
        cout << endl;
    }

    cout << "Final KSA array: ";
    for (int s : S)
    {
        cout << s << " ";
    }
    cout << endl
         << endl;

    // PGRA algorithm
    int i = 0, k = 0;
    vector<int> key_stream;

    for (int k = 0; k < pt.size(); k++)
    {
        i = (i + 1) % N;
        j = (j + S[i]) % N;
        swap(S[i], S[j]);
        int t = (S[i] + S[j]) % N;
        key_stream.push_back(S[t]);
    }

    cout << "Key stream: ";
    for (int k : key_stream)
    {
        cout << k << " ";
    }
    cout << endl
         << endl;

    // Performing XOR between generated key stream and plain text
    vector<int> cipher_text;
    for (int i = 0; i < pt.size(); i++)
    {
        int c = key_stream[i] ^ stoi(pt[i], nullptr, 2);
        cipher_text.push_back(c);
    }

    cout << "Cipher text: ";
    for (int c : cipher_text)
    {
        cout << bitset<8>(c).to_string() << " ";
    }
    cout << endl;
}

int main()
{

    string plain_text = "001010010010";
    string key = "101001000001";
    int n = 3;

    cout << "Plain text: " << plain_text << endl;
    cout << "Key: " << key << endl;
    cout << "n: " << n << endl;
    cout << endl;

    encryption(plain_text, key, n);
    return 0;
}
