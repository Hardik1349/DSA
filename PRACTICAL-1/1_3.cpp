#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str;
    cout << "Enter a sentence: ";
    getline(cin, str);

    string word = "";
    string longestWord = "";
    int maxLength = 0;

    for(int i = 0; i <= str.length(); i++)
    {
        if(i == str.length() || str[i] == ' ')
        {
            if(word.length() > maxLength)
            {
                maxLength = word.length();
                longestWord = word;
            }

            word = "";
        }
        else
        {
            word += str[i];
        }
    }

    cout << "Longest word: " << longestWord << endl;
    cout << "Length: " << maxLength << endl;

    return 0;
}