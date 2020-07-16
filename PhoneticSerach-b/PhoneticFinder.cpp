//
// Created by jblau on 7/15/2020.
//

#include <stdexcept>
#include <ctype.h>
#include "PhoneticFinder.hpp"

using namespace std;

string phonetic::find(string text,string word){
    string ans = "", tempS = "", tempW = "";
    int index = 0, indexI = 0, indexJ = 0;
    bool flag = false;

    for (int i = 0; i < text.size() ; ++i) {// goes through the text to make sure there is at least one word and not an empty string
        if(text[i] != ' '){
            flag = true;
        }
    }

    if(!flag || word == "" || word == " "){// if flag is false enters and means the string text is empty return exception also checks word is not empty
        throw exception();
    }
    text.erase(0, text.find_first_not_of(' '));// eraser all of spaces in beginning

    for (int j = 0; j < text.size(); ++j) {// goes through the text chars and ass them to tempS as lowercase
        tempS += tolower(text[j]);
    }
    for (int k = 0; k < word.size(); ++k) {
        tempW += tolower(word[k]);// puts all chars of word into tempW as lower case
    }

    while (indexI < tempS.size()){// goes through each char in temps
        if(sameChar(tempS[indexI], tempW[indexJ]) && tempS[indexI] != ' '){// if they are the same char and not empty char add the char to ans
            ans += text[indexI];// add original char
            indexI++;
            indexJ++;
            if(indexJ >= word.size()){// checks if at the end of word or more
                if(indexI >= tempS.size()){// checks if at the end of temps or more
                    return ans;// if so ans
                }
                else if(tempS[indexI] == ' '){// if temps next char is empty meaning finished a word
                    return ans;// if so ans
                }
            }
        }
        else{// if not same char or empty char
            ans = "";// refresh ans
            indexI = nextWord(tempS, indexI);// find index of next word
            indexJ = 0;// refresh word index
            if(indexI == -1 || indexI >= tempS.size()){// if index is larger than size or equal to or -1 meaning less than 0
                throw exception();// throw exception
            }
        }
    }
    return ans;// find returns ans if no exception was thrown
}
int phonetic::nextWord(string text, int i) {// finds next word from index i in text
    for (int j = ++i; j < text.size(); ++j) {// start from next index to end of text
        if(text[j] != ' '){// if we reached a char
            return j;// return start index of next word
        }
    }
    return -1;// if finished and didnt return means no next word
}
bool phonetic::sameChar(char x, char y) {// checks if the chars match including the rules or changing chars
    if (x == y){return true;}
    if ((x == 'v' && y == 'w') || (x == 'w' && y == 'v')) {return true;}
    if ((x == 'b' && y == 'p') || (x == 'p' && y =='b')) {return true;}
    if ((x == 'b' && y == 'f') || (x == 'f' && y == 'b')){return true;}
    if ((x == 'f' && y == 'p') || (x == 'p' && y =='f')) {return true;}
    if ((x == 'g' && y == 'j') || (x == 'j' && y =='g')) {return true;}
    if ((x == 'c' && y == 'k') || (x == 'k' && y =='c')) {return true;}
    if ((x == 'c' && y == 'q') || (x == 'q' && y =='c')) {return true;}
    if ((x == 'q' && y == 'k') || (x == 'k' && y =='q')) {return true;}
    if ((x == 's' && y == 'z') || (x == 'z' && y =='s')) {return true;}
    if ((x == 'd' && y == 't') || (x == 't' && y =='d')) {return true;}
    if ((x == 'o' && y == 'u') || (x == 'u' && y =='o')) {return true;}
    return (x == 'i' && y == 'y') || (x == 'y' && y == 'i');
}
