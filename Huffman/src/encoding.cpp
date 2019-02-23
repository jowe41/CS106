// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own, along with
// comments on every function and on complex code sections.
// TODO: remove this comment header

#include "encoding.h"
#include "pqueue.h"
// TODO: include any other headers you need

Map<int, int> buildFrequencyTable(istream& input) {
    // TODO: implement this function
    Map<int, int> freqTable;   // this is just a placeholder so it will compile
    string s;
    while(getline(input,s,'\0')){
        for(char i:s){
            freqTable[i]++;
        }
    }
    freqTable[PSEUDO_EOF]++;
    return freqTable;          // this is just a placeholder so it will compile
}

HuffmanNode* buildEncodingTree(const Map<int, int>& freqTable) {
    PriorityQueue<HuffmanNode*> pq;
    for(int key:freqTable.keys()){
        HuffmanNode *Node=new HuffmanNode;
        Node->character=key;
        Node->count=freqTable[key];
        pq.enqueue(Node,freqTable[key]);
    }
    while(pq.size()>1){
        HuffmanNode* Left=pq.dequeue();
        HuffmanNode* Right=pq.dequeue();
        HuffmanNode* Node=new HuffmanNode(NOT_A_CHAR,Left->count+Right->count,Left,Right);
        pq.enqueue(Node,Node->count);
    }
    // TODO: implement this function
    HuffmanNode* Node=pq.dequeue();
    return Node;   // this is just a placeholder so it will compile
}

void buildEncodingMap(Map<int,string> &map, HuffmanNode* tree,string s){
    if (tree==nullptr){
        return;
    }
    s+="0";
    buildEncodingMap(map,tree->zero,s);
    s=s.substr(0,s.length()-1);
    s+="1";
    buildEncodingMap(map,tree->one,s);
    s=s.substr(0,s.length()-1);
    if(tree->character!=NOT_A_CHAR){
        map[tree->character]=s;
    }
}

Map<int, string> buildEncodingMap(HuffmanNode* encodingTree) {
    // TODO: implement this function
    Map<int, string> encodingMap;
    string s;
    buildEncodingMap(encodingMap,encodingTree,s);
    return encodingMap;             // this is just a placeholder so it will compile
}

void encodeData(istream& input, const Map<int, string>& encodingMap, obitstream& output) {
    string s;
    string result;
    while(getline(input,s,'\0')){
        for(char c:s){
            result+=encodingMap[c];
        }
    }
    result+=encodingMap[PSEUDO_EOF];
    for (char c:result){
        output.writeBit(stringToInteger(charToString(c)));
    }
    // TODO: implement this function
}

void decodeData(ibitstream& input, HuffmanNode* encodingTree, ostream& output) {
    string s;
    while(input){
        int num=input.readBit();
        if (num==-1){
            break;
        }
        s+=integerToString(num);
    }
    HuffmanNode *curr=encodingTree;
    for (char c:s){
        if(curr->character!=NOT_A_CHAR){
            if(curr->character==PSEUDO_EOF){
                break;
            }
            char cc=curr->character;
            output<<cc;
            curr=encodingTree;
        }
        if(c=='0'){
            curr=curr->zero;
        }
        else if(c=='1'){
            curr=curr->one;
        }

    }
    // TODO: implement this function
}

void compress(istream& input, obitstream& output) {
    Map<int,int> Fmap=buildFrequencyTable(input);
    HuffmanNode *Tree=buildEncodingTree(Fmap);
    Map<int,string> encodemap=buildEncodingMap(Tree);
    output<<encodemap;
    encodeData(input,encodemap,output);
}

void decompress(ibitstream& input, ostream& output) {
    Map<int,int> Fmap=buildFrequencyTable(input);
    HuffmanNode *Tree=buildEncodingTree(Fmap);
    decodeData(input,Tree,output);
    // TODO: implement this function
}

void freeTree(HuffmanNode* node) {
    // TODO: implement this function
}
