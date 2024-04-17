#include <vector>
#include "wordsFunc.hpp"

using namespace std;

bool isWord(string word)
{
    bool valid(true);

    for (long unsigned int i = 0; i < word.size(); i++)
    {
        if (word[i] < 'A' || (word[i] > 'Z' && word[i] < 'a') || word[i] > 'z')
        {
            valid = false;
        }
    }

    return valid;
}

void lower(string &word)
{
    for (long unsigned int i = 0; i < word.length(); i++)
    {
        if (word[i] < 'Z' && word[i] > 'A')
        {
            word[i] += 'a' - 'A';
        }
    }
}

bool checkWin(vector<int> foundLetters)
{
    bool win(true);

    for (long unsigned int i = 0; i < foundLetters.size(); i++)
    {
        if (!foundLetters[i])
        {
            win = false;
        }
    }
    return win;
}

string getHiddenWord(string word, vector<int> foundLetters)
{
    string hiddenWord;

    for (long unsigned int i = 0; i < word.length(); i++)
    {
        if (foundLetters[i])
        {
            hiddenWord += word[i];
        }
        else
        {
            hiddenWord += "_";
        }
    }

    return hiddenWord;
}

bool letterInWord(char letter, string word)
{
    bool inWord(false);

    for (long unsigned int i = 0; i < word.length(); i++)
    {
        if (word[i] == letter)
        {
            inWord = true;
        }
    }

    return inWord;
}