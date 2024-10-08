#include <bits/stdc++.h>
using namespace std;
void generateCipherMatrix(string key, vector<vector<int>> &CipherMatrix)
{
    vector<int> index(26, 0);
    string new_key = "";
    int n = key.size();
    for (int i = 0; i < n; i++)
    {
        if ((key[i] - 'a' == 8 || key[i] - 'a' == 9) && index[key[i] - 'a'] == 0)
        {
            new_key += key[i];
            index[8] = 1;
        }
        else if (index[key[i] - 'a'] == 0)
        {
            new_key += key[i];
            index[key[i] - 'a'] = 1;
        }
    }

    int k = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            if (k < new_key.size())
            {
                CipherMatrix[i][j] = new_key[k] - 'a';
                k++;
            }
    }

    for (int i = 0; i < 26; i++)
    {
        if (i == 9)
            continue; // Skip 'j' or handle 'i' and 'j' as the same
        if (index[i] == 0)
        {
            CipherMatrix[k / 5][k % 5] = i;
            k++;
        }
    }
}
// Helper function to find the position of a character in the cipher matrix
pair<int, int> findPosition(vector<vector<int>> &CipherMatrix, char ch)
{
    if (ch == 'j')
        ch = 'i'; // Treat 'i' and 'j' as the same
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (CipherMatrix[i][j] == (ch - 'a'))
            {
                return {i, j};
            }
        }
    }
    return {-1, -1}; // Should never happen if input is valid
}

// Encrypt the message using the CipherMatrix
string encryptMessage(string new_msg, vector<vector<int>> &CipherMatrix)
{
    string encrypted_text = "";
    for (int i = 0; i < new_msg.size(); i += 2)
    {
        char first = new_msg[i];
        char second = new_msg[i + 1];

        // Find the positions of the two characters in the matrix
        pair<int, int> pos1 = findPosition(CipherMatrix, first);
        pair<int, int> pos2 = findPosition(CipherMatrix, second);

        if (pos1.first == pos2.first)
        { // Same row
            encrypted_text += (char)((CipherMatrix[pos1.first][(pos1.second + 1) % 5]) + 'a');
            encrypted_text += (char)((CipherMatrix[pos2.first][(pos2.second + 1) % 5]) + 'a');
        }
        else if (pos1.second == pos2.second)
        { // Same column
            encrypted_text += (char)((CipherMatrix[(pos1.first + 1) % 5][pos1.second]) + 'a');
            encrypted_text += (char)((CipherMatrix[(pos2.first + 1) % 5][pos2.second]) + 'a');
        }
        else
        { // Rectangle swap
            encrypted_text += (char)(CipherMatrix[pos1.first][pos2.second] + 'a');
            encrypted_text += (char)(CipherMatrix[pos2.first][pos1.second] + 'a');
        }
    }
    return encrypted_text;
}
int main()
{
    vector<vector<int>> CipherMatrix(5, vector<int>(5));
    string key, msg;
    cout << "Enter the key that is used for encription" << endl;
    cin >> key;
    cout << "Enter the msg that you want to encript" << endl;
    cin >> msg;
    generateCipherMatrix(key, CipherMatrix);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << CipherMatrix[i][j] << " ";
        }
        cout << endl;
    }

    string new_msg = "";
    int m = msg.size();
    int i = 0;
    while (i < m - 1)
    {
        if (msg[i] != msg[i + 1])
        {
            new_msg += msg.substr(i, 2);
            i = i + 2;
        }
        else
        {
            new_msg += msg[i];
            new_msg += 'x';
            i++;
        }
        if (i == m - 1)
        {
            new_msg += msg[i];
            new_msg += 'x';
            break;
        }
    }
    cout << "new_msg is " << new_msg << endl;
    // Encrypt the new_msg using the cipher matrix
    string encrypted_text = encryptMessage(new_msg, CipherMatrix);
    cout << "Encrypted message: " << encrypted_text << endl;
    return 0;
}