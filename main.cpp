#include <iostream>
#include <fstream>
#include <vector>
#include "main.hpp"
#include "wordsFunc.hpp"

using namespace std;

int main()
{
    int choice(0);
    string word(getInitWord());
    bool playing(true);

    string inputWord;
    int coupRestant(10);
    vector<int> foundLetters(word.length(), 0);
    vector<string> triedWord;

    while (playing)
    {
        switch (choice)
        {

        // menu Home
        case 0:
            cout << endl
                 << "**** Bienvenue au Pendu ****" << endl
                 << endl
                 << endl
                 << "Que voulez vous faire ?" << endl
                 << "1. Choisir le mot" << endl
                 << "2. Deviner le mot" << endl
                 << "3. Quitter" << endl
                 << "Que choisissez-vous ? ";
            cin >> choice;
            break;

        // menu de choix du mot
        case 1:
            cout << endl
                 << "**** Choisir le mot ****" << endl
                 << "Quel est le nouveau mot ? ";
            cin >> word;

            while (!isWord(word))
            {
                cout << "Ce n'est pas un mot !" << endl
                     << "Quel est le nouveau mot ? ";
                cin >> word;
            }

            lower(word);

            cout << "Le nouveau mot est: " << word << endl
                 << endl;

            setInitWord(word);
            foundLetters.resize(word.length());

            choice = 0;
            break;

        // menu de jeu
        case 2:
            cout << endl
                 << "**** Deviner le mot ****" << endl;

            foundLetters.assign(foundLetters.size(), 0);

            while (coupRestant != 0 && !checkWin(foundLetters))
            {
                cout << endl
                     << "Devinez le mot: " << getHiddenWord(word, foundLetters) << endl
                     << "Vous avez essaye ces mots ou lettres: " << showTriedWords(triedWord) << endl
                     << "Il vous reste " << coupRestant << " coups" << endl
                     << "Quel mot ou lettre voulez-vous essayer ? ";
                cin >> inputWord;

                while (!isWord(inputWord))
                {
                    cout << "Ce n'est pas une lettre ni un mot" << endl
                         << "Quel mot ou lettre voulez vous essayer ? ";
                    cin >> inputWord;
                }

                triedWord.push_back(inputWord);

                if (inputWord.length() == 1)
                {
                    if (word.find(inputWord[0]) != -1)
                    {
                        for (long unsigned int i = 0; i < word.length(); i++)
                        {
                            if (word[i] == inputWord[0])
                            {
                                foundLetters[i] = 1;
                            }
                        }
                    }
                    else
                    {
                        coupRestant -= 1;
                    }
                }
                else
                {
                    if (word.compare(inputWord) != 0)
                    {
                        coupRestant -= 1;
                    }
                    else
                    {
                        for (long unsigned int i = 0; i < word.length(); i++)
                        {
                            foundLetters[i] = 1;
                        }
                    }
                }
            }

            if (coupRestant == 0)
            {
                choice = 2365;
            }
            else
            {
                choice = 7238;
            }

            break;

        case 3:
            playing = false;
            break;

        case 7238:

            cout << endl
                 << "Vous avez trouve le mot !" << endl
                 << "C'etais: " << word << endl;

            choice = 0;

            break;

        case 2365:
            cout << "Vous n'avez pas trouve le mot :(" << endl
                 << "C'etait: " << word << endl;

            choice = 0;

            break;

        default:
            cout << "Ce n'est pas dans les options" << endl
                 << "Que choisissez-vous ? ";
            cin >> choice;
            break;
        }
    }

    cout << "\n\n\n";
    return 1;
}

string getInitWord()
{
    ifstream saveFile("hiddenword.txt");
    string word;

    if (saveFile)
    {
        saveFile >> word;
    }
    else
    {
        setInitWord("magique");
        word = "magique";
    }
    return word;
}

void setInitWord(string word)
{
    ofstream saveFile("hiddenWord.txt");
    saveFile << word;
}

string showTriedWords(vector<string> triedWord)
{
    string str;

    for (long unsigned int i = 0; i < triedWord.size(); i++)
    {
        str += triedWord[i];
        if (i != triedWord.size() - 1)
        {
            str += ", ";
        }
    }

    return str;
}