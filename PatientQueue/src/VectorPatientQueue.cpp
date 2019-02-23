// This is the CPP file you will edit and turn in. (TODO: Remove this comment!)

#include "VectorPatientQueue.h"

VectorPatientQueue::VectorPatientQueue() {
    capacity=4;
    elements=new patient[capacity];
    count=0;
    time=1;

    // TODO: write this constructor
}

VectorPatientQueue::~VectorPatientQueue() {
    delete [] elements;
    // TODO: write this destructor
}

void VectorPatientQueue::clear() {
    count=0;
    // TODO: write this function
}

string VectorPatientQueue::frontName() {
    if (count==0){
        throw "The queue is empty";
    }
    patient front=elements[0];
    for (int i=0;i<count;i++){
        if(elements[i].pr<front.pr){
            front=elements[i];
        }
        if(elements[i].pr==front.pr and elements[i].timestamp<=front.timestamp){
            front=elements[i];
        }
    }
    return front.na;
}

int VectorPatientQueue::frontPriority() {
    if (count==0){
        throw "The queue is empty";
    }
    patient front=elements[0];
    for (int i=0;i<count;i++){
        if(elements[i].pr<front.pr){
            front=elements[i];
        }
        if(elements[i].pr==front.pr and elements[i].timestamp<=front.timestamp){
            front=elements[i];
        }
    }
    return front.pr;
}

bool VectorPatientQueue::isEmpty() {
    if (count==0){
        return true;
    }
    // TODO: write this function
    return false;   // this is only here so it will compile
}

void VectorPatientQueue::newPatient(string name, int priority) {
    if (count==capacity){
        expand();
    }
    patient newP;
    newP.na=name;
    newP.pr=priority;
    newP.timestamp=time;
    elements[count]=newP;
    count++;
    time++;

    // TODO: write this function
}

string VectorPatientQueue::processPatient() {
    if (count==0){
        throw "There is no top. I must abort. I never learned how to love...";
    }
    int pa=0;
    string patientname;
    patient front=elements[0];
    for (int i=0;i<count;i++){
        if(elements[i].pr<front.pr){
            front=elements[i];
            pa=i;
            patientname=elements[i].na;
        }
        if(elements[i].pr==front.pr and elements[i].timestamp<=front.timestamp){
            front=elements[i];
            pa=i;
            patientname=elements[i].na;
        }
    }
    for (int i=pa;i<count;i++){
        elements[i]=elements[i+1];
    }
    count--;
    return patientname;   // this is only here so it will compile
}

void VectorPatientQueue::upgradePatient(string name, int newPriority) {
    patient front=elements[0];
    int pa=0;
    for(int i=0;i<count;i++){
        if(elements[i].na==name){
            if(front.na!=elements[i].na){
                front=elements[i];
                pa=i;
            }
            else{
                if (front.pr==elements[i].pr and front.timestamp>elements[i].timestamp){
                    front=elements[i];
                    pa=i;
                }
                if(front.pr>elements[i].pr){
                    front=elements[i];
                    pa=i;
                }
            }
        }
    }
    if (elements[pa].pr<=newPriority){
        throw "You can only increase the priotity.";
    }
    else if(elements[pa].na!=name){
        throw "There is no such patient";
    }
    else{
        elements[pa].pr=newPriority;
    }
    // TODO: write this function
}

string VectorPatientQueue::toString() {
    if(count==0){
        return "{}";
    }
    string queue="{";
    for (int i=0;i<count;i++){
        queue+=elements[i].na+":"+integerToString(elements[i].pr);
        if(i!=count-1){
            queue+=", ";
        }
    }
    queue+="}";
    // TODO: write this function
    return queue; // this is only here so it will compile
}

void VectorPatientQueue::expand(){
    patient *newE=new patient[2*capacity];
    for(int i=0;i<capacity;i++){
        newE[i]=elements[i];
    }
    delete [] elements;
    elements=newE;
    capacity*=2;
}
