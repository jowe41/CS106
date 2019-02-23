// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include "console.h"
#include "filelib.h"
#include "simpio.h"
#include "map.h"
#include "random.h"
#include "vector.h"

using namespace std;
Map<Vector<string>,Vector<string>> dict;

string generateword(int N,int num_w){
    Vector<Vector<string>> key;
    string line="...";
    key=dict.keys();
    Vector<string> window=key[randomInteger(0,key.size()-1)];
    for (int i=0;i<window.size();i++){
        line=line+" "+window[i];
    }
    for (int i=0;i<num_w-N+1;i++){
        string value=dict[window][randomInteger(0,dict[window].size()-1)];
        line=line+" "+value;
        window.remove(0);
        window.add(value);
    }
    line=line+" ...";
    return line;
}

Map<Vector<string>,Vector<string>> createMap(int N,string filename){
    Map<Vector<string>,Vector<string>> dict;
    Vector<string> all;
    Vector<string> key;
    ifstream stream;
    openFile(stream,filename);
    string word;
    int k;
    while(stream>>word){
        all.add(word);
    }
    for (int i=0;i<all.size();i++){
        key.clear();
        for (int j=0;j<N;j++){
            k=i+j;
            if (k>all.size()-1){
                k=k%all.size();
            }
            key.add(all[k]);
        }
        if(k==all.size()-1){
            k=k-all.size();
        }
        if (!dict.containsKey(key)){
            Vector<string> value;
            value.add(all[k+1]);
            dict.put(key,value);
        }
        else{
            dict[key].add(all[i+N]);
        }

    }

    return dict;
}

int main() {
    // TODO: Finish the program!


    cout<<"Welcome to Cs 106B Random Writer ('N-Grams')."<<endl;
    cout<<"This program makes random text based on a document"<<endl;
    cout<<"Give me an input file and an 'N' value for groups"<<endl;
    cout<<"of words, and I'll create random text for you.\n"<<endl;
    int N;
    string filename=promptUserForFile("Input file name?");
    while (true){
        N=getInteger("Value of N?");
        if(N<2){
            cout<<"N must be 2 or greater."<<endl;
            continue;
        }
        break;
    }
    while(true){
        string line;
        cout<<endl;
        int num_w=getInteger("# of random words to generate (0 to quit)?");
        if (num_w==0){
            cout << "Exiting." << endl;
            return 0;
        }
        if(num_w<3){
            cout<<"Must be at least 4 words.\n"<<endl;
            continue;
        }
        dict=createMap(N-1,filename);
        cout<<generateword(N-1, num_w)<<endl;
    }
}
