#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
    /// Take one array for storing the original message and one for storing the coded message.
    /// decide whether to use DAL or SAL for each array

    int choice;

    cout << "\t\t\tCSE 204 Online 1 Q1 - My Enigma Machine" << endl;
    cout << "\t\t\tCoded by 202214027" << endl;
    vector<char> message;
    vector<int> cipher;
    while (1)
    {
        cout << "\n1. Enter Message to be sent \n2. Delete a letter from your message \n3. Cipher (code) the message \n4. Show both arrays (c=original and coded message) \n5.Exit " << endl;
        cout << "\nEnter Choice:";

        cin >> choice;

        if (choice == 1)
        {
            /// Take input and Store the original message
            string s;
            cin >> s;
            for (auto i : s)
            {
                message.push_back(i);
            }
        }

        else if (choice == 2)
        {
            char c;
            cout << "Enter the char to delete all occurrences of: ";
            cin >> c;
            /// find all occurrences of of input char in the original message's array and delete them
            for (int i = 0; i < message.size(); i++)
            {
                if (message[i] == c)
                {
                    message.erase(message.begin() + i);
                }
            }
        }

        else if (choice == 3)
        {
            /// cipher the current message after taking input using option 1.
            /// append it into the coded message's array.
            for (auto i : message)
            {
                cipher.push_back((i + 27) % 20);
                cout << cipher.back() << " ";
            }
            cout << endl;
        }

        else if (choice == 4)
        {
            /// show the full coded msg array and current original message array
            for (auto i : message)
            {
                cout << i;
            }
            cout << endl;
            for (auto i : cipher)
            {
                cout << i;
            }
            cout << endl;
        }
        else if (choice == 5)
        {
            break;
        }

        else
            cout << "\n\nInvalid choice, enter again\n\n";
    }
}
