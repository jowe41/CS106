/*
 * File: grammarsolver.cpp
 * --------------------------
 * Name:
 * Section leader:
 * This file contains grammar generating code for CS106B.
 */

#include "grammarsolver.h"
#include "map.h"
#include "random.h"


using namespace std;

/**
 * Generates grammar for a given symbol a certain number of times given
 * a BNF input file.
 *
 * This will be called by grammarmain.cpp.
 *
 * @param input - Input stream of BNF file.
 * @param symbol - Symbol to generate
 * @param times - Number of times grammar is generated
 * @return Vector of strings of size times with random generations of symbol
 */
string grammarhelper(string s,Map<string,Vector<string>> dict){
    string result;
    if (s.find(" ")==string::npos){
        if (!dict.containsKey(s)){
            return s+" ";
        }
        else{
            int num=randomInteger(0,dict[s].size()-1);
            result=result+grammarhelper(dict[s][num],dict);
        }
    }
    else{
        Vector<string> rules=stringSplit(s," ");
        for(string rule:rules){
            result=result+grammarhelper(rule,dict);
        }
    }
    return result;
}

Vector<string> grammarGenerate(istream& input, string symbol, int times) {
    // TODO: write this function
    Vector<string> result;
    Map<string,Vector<string>> dict;
    string s;
    while(getline(input,s)){
        s=trim(s);
        Vector<string> line=stringSplit(s,"::=");
        dict[line[0]]=stringSplit(line[1],"|");
    }
    for (int i=0;i<times;i++){
        result.add(grammarhelper(symbol,dict));
    }
    return result;           // This is only here so it will compile
}


