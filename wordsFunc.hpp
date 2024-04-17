#ifndef WORDSFUNC_H_INCLUDED
#define WORDSFUNC_H_INCLUDED

#include <string>
#include <vector>

bool isWord(std::string word);
void lower(std::string &word);
bool checkWin(std::vector<int> foundLetters);
std::string getHiddenWord(std::string word, std::vector<int> foundLetters);
bool letterInWord(char letter, std::string word);

#endif