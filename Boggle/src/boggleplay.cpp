// This is a .cpp file you will edit and turn in.
// We have provided a skeleton for you,
// but you must finish it as described in the spec.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include "lexicon.h"
#include "Boggle.h"
#include "simpio.h"
#include "console.h"

void play(Lexicon& dictionary,string in){
    Boggle boggle=Boggle(dictionary,in);
    clearConsole();
    cout<<"It's your turn!"<<endl;
    while (true){

        cout<<boggle<<endl;
        cout<<"Your words ("<<boggle.seenword.size()<<"):"<<boggle.seenword.toString()<<endl;
        cout<<"Your score: "<<boggle.getScoreHuman()<<endl;
        string word=getLine("Type a word (or Enter to stop):");
        if(word==""){
            break;
        }
        if (boggle.checkWord(word)){
            boggle.seenword.add(word);
            boggle.addHumanScore(word);
        }
    }
}

void playOneGame(Lexicon& dictionary) {
    // TODO: implement
    string s;
    string in;
    if(!getYesOrNo("Do you want to generate a random board?")){
        while(true){
            s="";
            in=getLine("Type the 16 letters to appear on the board:");
            for (char c:in){
                if (in.length()!=16||!isalpha(c)){
                    s="off";
                    break;
                }
            }
            if (s=="off"){
                cout<<"That is not a valid 16-letter board string. Try again.";
                continue;
            }
            else{
                in=toUpperCase(in);
                break;
            }
        }
        play(dictionary,in);
    }
    else{
        play(dictionary,in);
    }
}


