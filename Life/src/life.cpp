// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header!

#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "console.h"
#include "filelib.h"
#include "grid.h"
#include "gwindow.h"
#include "simpio.h"
#include "lifegui.h"
using namespace std;

void displayBoard(Grid<string> Board,int Row, int Col){
    for(int i=0;i<Row;i++){
        string line;
        for (int j=0;j<Col;j++){
            line+=Board[i][j];
        }
        cout<<line<<endl;
    }
}


void updateGeneration(Grid<string> &Board,int Row, int Col,bool wrap){
    Grid<string> temp;
    temp.resize(Row,Col);
    temp.fill("-");
    for (int i=0;i<Row;i++){
        for (int j=0;j<Col;j++){
            int count=0;
            if (wrap==false){
                for (int k=max(i-1,0);k<min(i+2,Row);k++){
                    for (int l=max(j-1,0);l<min(j+2,Col);l++){
                        if (Board[k][l]=="X"&&(k!=i || j!=l)){
                            count++;
                        }
                    }
                }
            }
            if(wrap==true){
                for (int k=i-1;k<i+2;k++){
                    int real_k=k;
                    if (k<0){
                        real_k=(i-1+Row)%Row;
                    }
                    if(k==Row){
                        real_k=k-Row;
                    }
                    for (int l=j-1;l<j+2;l++){
                        int real_l=l;
                        if(l<0){
                            real_l=(j-1+Col)%Col;
                        }
                        if(l==Col){
                            real_l=l-Col;
                        }

                        if (Board[real_k][real_l]=="X"&&(real_k!=i || real_l!=j)){
                            count++;
                        }
                    }
                }
            }
            if (count==2&&Board[i][j]=="X"){
                temp.set(i,j,"X");
            }
            if(count==3){
                temp.set(i,j,"X");
            }
        }
    }
    Board=temp;
}

int main() {
    // TODO: Finish the program!
    cout<<"Welcome to the CS 106B Game of Life,"<<endl;
    cout<<"a simulation of the lifecycyle of a bacteria colony."<<endl;
    cout<<"Cells (X) live and die by the following rules:"<<endl;
    cout<<"- A cell with 1 or fewer neighbors dies."<<endl;
    cout<<"- Locations with 2 neighbors remain stable."<<endl;
    cout<<"- Locations with 3 neighbors will create life."<<endl;
    cout<<"- Locations with 4 or more neighbors dies.\n"<<endl;

    string s;
    int Row;
    int Col;
    int count=0;
    Grid <string> Board;
    string choice;

    ifstream stream;


    string filename= promptUserForFile("Grid input file name?",\
                                       "Unable to open that file. Try again.");
    openFile(stream,filename);

    while(getline(stream,s)){
        if (count==0){
            Row=stringToInteger(s);
        }
        if(count==1){
            Col=stringToInteger(s);
            Board.resize(Row,Col);
        }
        if (s==""){
            break;
        }
        if (count>1){
            for (int i=0;i<s.length();i++){
                Board[count-2][i]=s[i];
            }
        }

        count++;
    }
    stream.close();
    bool wrap=getYesOrNo("Should the simulation warp around the grid (y/n)?");
    displayBoard(Board,Row,Col);
    while(true){
        choice=getLine("a)nimate, t)ick, q)uit?");
        choice=toLowerCase(choice);
        if (choice!="a"&&choice!="t"&&choice!="q"){
            cout<<"Invalid choice; please try again."<<endl;
            continue;
        }

        if (choice=="q"){
            cout << "Have a nice Life!" << endl;
            return 0;
        }

        if (choice=="a"){
            int frame=getInteger("How many frames?");
            for (int i=0;i<frame;i++){
                clearConsole();
                updateGeneration(Board, Row, Col,wrap);
                displayBoard(Board,Row,Col);
                pause(50);
                }
            }
        if (choice=="t"){
            updateGeneration(Board, Row, Col,wrap);
            displayBoard(Board,Row,Col);
            }
    }

    return 0;
}
