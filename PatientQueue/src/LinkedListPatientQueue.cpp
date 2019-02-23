// This is the CPP file you will edit and turn in. (TODO: Remove this comment!)

#include "LinkedListPatientQueue.h"

LinkedListPatientQueue::LinkedListPatientQueue() {
    front=new PatientNode;
    // TODO: write this constructor
}

LinkedListPatientQueue::~LinkedListPatientQueue() {
    while(front->next!=nullptr){
        PatientNode *next=front->next;
        front->next=next->next;
        next=front->next;
        delete next;
    }
    // TODO: write this destructor
}

void LinkedListPatientQueue::clear() {
    while(front->next!=nullptr){
        PatientNode *next=front->next;
        front->next=next->next;
        next=front->next;
        delete next;
    }
    // TODO: write this function
}

string LinkedListPatientQueue::frontName() {
    if (front->next==nullptr){
        throw "The queue is empty";
    }

    // TODO: write this function
    return front->next->name;   // this is only here so it will compile
}

int LinkedListPatientQueue::frontPriority() {
    if (front->next==nullptr){
        throw "The queue is empty";
    }
    return front->next->priority;   // this is only here so it will compile
}

bool LinkedListPatientQueue::isEmpty() {
    if (front->next==nullptr){
        return true;
    }
    // TODO: write this function
    return false;   // this is only here so it will compile
}

void LinkedListPatientQueue::newPatient(string name, int priority) {
    PatientNode* newP=new PatientNode(name,priority);
    if (front->next==nullptr){
        front->next=newP;
    }
    else{
        PatientNode* curr=front->next;
        while(curr->priority<=newP->priority){
            if(curr->next==nullptr){
                break;
            }
            if(curr->next->priority<=priority){
                curr=curr->next;
            }
            else{
                break;
            }
        }
        if(curr->next==nullptr and curr->priority<=priority){
            curr->next=newP;
        }
        else if(curr->priority>priority){
            newP->next=curr;
            front->next=newP;
        }
        else{
            newP->next=curr->next;
            curr->next=newP;
        }
    }

    // TODO: write this function
}

string LinkedListPatientQueue::processPatient() {
    if (front->next==nullptr){
        throw "The queue is empty";
    }
    PatientNode* result=front->next;
    front->next=result->next;
    string name=result->name;
    delete result;
    // TODO: write this function
    return name;   // this is only here so it will compile
}

void LinkedListPatientQueue::upgradePatient(string name, int newPriority) {
    PatientNode *patient=front;
    PatientNode *curr=front;
    while(patient->next!=nullptr){
        if(patient->next->name==name){
            if(patient->next->priority<=newPriority){
                throw "You can only increase the priotity.";
            }
            else{
                patient->next->priority=newPriority;
                break;
            }
        }
        else{
            patient=patient->next;
        }
        if(curr->next!=nullptr and curr->next->priority<=newPriority){
            curr=curr->next;
        }
    }
    if(patient->next->next==nullptr){
        patient->next->next=curr->next;
        curr->next=patient->next;
        patient->next=nullptr;
    }
    else{
        PatientNode *temp=patient->next;
        patient->next=patient->next->next;
        temp->next=curr->next;
        curr->next=temp;

    }
}


string LinkedListPatientQueue::toString() {
    string line;
    if (front->next==nullptr){
        line="{}";
    }
    else{
        PatientNode *curr=front->next;
        line+="{";
        while(curr!=nullptr){
            line=line+to_string(curr->priority)+":"+curr->name;
            if(curr->next!=nullptr){
                line+=", ";
            }
            curr=curr->next;
        }
        line+="}";
    }
    // TODO: write this function
    return line; // this is only here so it will compile
}
