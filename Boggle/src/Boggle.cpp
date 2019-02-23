// This is a .cpp file you will edit and turn in.
// We have provided a skeleton for you,
// but you must finish it as described in the spec.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include "Boggle.h"
#include "grid.h"

// letters on all 6 sides of every cube
static string CUBES[16] = {
    "AAEEGN", "ABBJOO", "ACHOPS", "AFFKPS",
    "AOOTTW", "CIMOTU", "DEILRX", "DELRVY",
    "DISTTY", "EEGHNW", "EEINSU", "EHRTVW",
    "EIOSST", "ELRTTY", "HIMNQU", "HLNNRZ"
};

// letters on every cube in 5x5 "Big Boggle" version (extension)
static string BIG_BOGGLE_CUBES[25] = {
   "AAAFRS", "AAEEEE", "AAFIRS", "ADENNN", "AEEEEM",
   "AEEGMU", "AEGMNN", "AFIRSY", "BJKQXZ", "CCNSTW",
   "CEIILT", "CEILPT", "CEIPST", "DDLNOR", "DDHNOT",
   "DHHLOR", "DHLNOR", "EIIITT", "EMOTTT", "ENSSSU",
   "FIPRSY", "GORRVW", "HIPRRY", "NOOTUW", "OOOTTU"
};

Boggle::Boggle(Lexicon& dictionary, string boardText) {
    // TODO: implement
    dict=dictionary;
    Board.resize(4,4);
    if (boardText.empty()){
        for (int i=0;i<4;i++){
            for (int j=0;j<4;j++){
                int num=randomInteger(0,5);
                Board[i][j]=CUBES[4*i+j][num];
            }
        }
    }
    else{
        for(int i=0;i<boardText.length();i++){
            Board[i/4][i%4]=boardText[i];
        }
    }
}

char Boggle::getLetter(int row, int col) {
    if (!Board.inBounds(row,col)){
        throw "It is not in Bounds.";
    }
    return Board[row][col];   // remove this
}

bool Boggle::checkWord(string word) {
    word=toLowerCase(word);
    if(word.size()<4){
        return false;
    }
    else if(!dict.contains(word)){
        return false;
    }
    else if(humanWordSearch(word)){
        return false;
    }
    return true;   // remove this
}

bool Boggle::humanWordSearch(string word) {
    if (seenword.contains(word)){
        return  true;
    }
    // TODO: implement
    return false;   // remove this
}

int Boggle::getScoreHuman() {
    // TODO: implement
    return humanscore;   // remove this
}

Set<string> Boggle::computerWordSearch() {
    // TODO: implement
    Set<string> result;
    // remove this
    return result;        // remove this
}

int Boggle::getScoreComputer() {
    // TODO: implement
    return 0;   // remove this
}

ostream& operator<<(ostream& out, Boggle& boggle) {
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            out<<boggle.Board[i][j];
        }
        out<<endl;
    }
    return out;
}

void Boggle::addHumanScore(string word){
    humanscore+=word.length()-3;
}

void Boggle::addComputerScore(string word){
    computerscore+=word.length()-3;
}
