//
// Created by jblau on 7/15/2020.
//

#ifndef PHONETICSEARCH_PHONETICFINDER_HPP
#define PHONETICSEARCH_PHONETICFINDER_HPP

#include <iostream>

using namespace std;

namespace phonetic{
    string find(string text,string word);
    int nextWord(string text, int i);
    bool sameChar(char x, char y);

}
#endif //PHONETICSEARCH_PHONETICFINDER_HPP
