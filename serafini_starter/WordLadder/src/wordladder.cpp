// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include "stack.h"
#include "queue.h"
#include "filelib.h"
#include "console.h"
#include "simpio.h"
#include "lexicon.h"

using namespace std;

Stack<string> findladder(Queue<Stack<string>> Q,Stack<string> &ladder, Lexicon dic,string word2){
    Set<string> seen_word;
    Stack<string> empty;
    Q.enqueue(ladder);
    while(!Q.isEmpty()){
        ladder=Q.dequeue();
        string word=ladder.top();
        if (word==word2){
            return ladder;
        }
        else{
            for(int i=0;i<word.length();i++){
                for (char j='a';j<='z';j++){
                    string cp_word=word;
                    cp_word[i]=j;
                    if(!seen_word.contains(cp_word)&&dic.contains(cp_word)){
                        Stack<string> cp_l=ladder;
                        cp_l.push(cp_word);
                        Q.enqueue(cp_l);
                        seen_word.add(cp_word);
                    }
                }

            }

        }
    }
    return empty;
}
int main() {
    // TODO: Finish the program!
    Stack<string> ladder;
    Queue<Stack<string>> Q;

    cout<<"Welcome to CS 106B Word Ladder."<<endl;
    cout<<"Please give me two English words, and I will change the"<<endl;
    cout<<"first into the second by changing one letter at a time.\n"<<endl;


    string filename= promptUserForFile("Dictionary file name?");
    Lexicon dic(filename);

    while(true){
        cout<<""<<endl;
        string word1=getLine("Word #1 (or Enter to quit):");
        word1=toLowerCase(word1);
        if(word1==""){
            break;
        }
        string word2=getLine("Word #2 (or Enter to quit):");
        word2=toLowerCase(word2);
        if (word2==""){
            break;
        }
        if (word1.length()!=word2.length()){
            cout<<"The two words must be the same length."<<endl;
            continue;
        }
        if (word1==word2){
            cout<<"The two words must be different."<<endl;
            continue;
        }
        if (dic.contains(word1)==false or dic.contains(word2)==false){
            cout<<"The two words must be found in the dictionary."<<endl;
            continue;
        }
        ladder.push(word1);
        ladder=findladder(Q,ladder,dic,word2);
        if (ladder.size()>0){
            cout<<"A ladder from "<<word2<<" back to "<<word1<<":"<<endl;
            while (!ladder.isEmpty()){
                cout<<ladder.pop()+" ";
            }
            cout<<endl;
        }
        else{
            cout<<"No word ladder found from "<<word2<<" back to "<<word1<<"."<<endl;
        }
    }
    cout << "Have a nice day." << endl;
    return 0;
}
