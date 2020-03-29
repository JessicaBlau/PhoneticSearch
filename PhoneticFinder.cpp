
#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <stdexcept>
#include "PhoneticFinder.hpp"

string phonetic::find(string text, string word) {
    bool flag= true;
    for (int m = 0; m <text.size() ; ++m) {
        if(text[m]!=' '){
            flag=false;
        }
    }
    if (flag){
        throw std::exception();
    }


    string ans="";
    int i=0,j=0;
    int counter=0;
    if (word=="" || word==" "){
        throw exception();
    }
    string texttemp=text;
    text="";
    for (int k = 0; k <texttemp.size() ; ++k) {
        if(texttemp[k]==' '){
            counter++;
        }
        if (texttemp[k]>='A'){
            break;
        }
    }
    for (int l = counter; l <texttemp.size() ; ++l) {
        text+=texttemp[l];
    }
    string text_source=text;
    int index=0;
    string temp=text;
    text="";
    for (int i = 0; i <temp.size() ; ++i) {
        text+=tolower(temp[i]);
    }
    temp=word;
    word="";
    for (int j = 0; j <temp.size() ; ++j) {
        word+=tolower(temp[j]);
    }
    while (i<text.size()) {
        if (same_Char(text[i], word[j]) && text[i] != ' ') {
            ans += text_source[i];
            j++;
            i++;
            index = i;
            if (j >= word.size()) {
                if (index >= text.size()) {
                    return ans;
                } else if (text[i] == ' ') {
                    return ans;
                }
            }

        } else {
            ans = "";
            j = 0;
            i = next_Word(text, i);
            if (i == -1 || i >= text.size()) {
                throw exception();
            }
        }

    }
    return ans;
}
string phonetic::chack_Word(string text, string ans,int index) {
    string answer="";
    for (int i = index; i <index+ans.size() ; ++i) {
        if(char(ans[i]+32)==text[i] || char(ans[i]-32)==text[i]|| ans[i]==text[i]){
            ans+=text[i];
        } else{
            return "";
        }
    }
    return ans;
}
int phonetic::next_Word(string text, int i){
    for (int j = i+1; j <text.size() ; j++) {
        if(text[j]!=' '){
            return (j);
        }
    }
    return -1;

}
bool phonetic::same_Char(char x , char y){
    if (x==y){
        return true;
    }
    if ((((x == 'v') && (y == 'w')) || (((x == 'w' )) && (y == 'v')))) {
        return true;
    }
    if ((((x == 'b')) && (y == 'p' ))|| ((x == 'p' ) && (y =='b'))) {
        return true;
    }
    if((((x == 'b')) && (y == 'f')) || (((x == 'f')) && (y == 'b'))){
        return true;
    }
    if ((((x == 'f')) && (y == 'p' ))|| (((x == 'p')) && (y =='f'))) {
        return true;
    }
    if (((((x == 'g')) && (y == 'j'))|| ((x == 'j') && (y =='g')))) {
        return true;
    }
    if ((((x == 'c') && (y == 'k' ))|| ((x == 'k') && (y =='c')))) {
        return true;
    }
    if (((x == 'c' ) && (y == 'q'))|| ((x == 'q') && (y =='c'))) {
        return true;
    }
    if ((((x == 'q' ) && (y == 'k'))|| ((x == 'k' ) && (y =='q')))) {
        return true;
    }
    if ((((x == 's') && (y == 'z'))|| ((x == 'z') && (y =='s')))) {
        return true;
    }
    if ((((x == 'd' ) && (y == 't' ))|| ((x == 't') && (y =='d' )))) {
        return true;
    }
    if ((((x == 'o' ) && (y == 'u'))|| ((x == 'u') && (y =='o')))) {
        return true;
    }
    if ((((x == 'i' ) && (y == 'y' ))|| ((x == 'y') && (y =='i')))) {
        return true;
    }
    return false;

}

