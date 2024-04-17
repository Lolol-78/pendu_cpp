#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <string>
#include <vector>

void showHome();
std::string getInitWord();
void setInitWord(std::string word);
std::string showTriedWords(std::vector<std::string> triedWord);

#endif