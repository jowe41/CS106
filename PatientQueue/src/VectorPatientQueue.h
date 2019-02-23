// This is the H file you will edit and turn in. (TODO: Remove this comment!)

#pragma once

#include <iostream>
#include <string>
#include "patientqueue.h"
#include "vector.h"
using namespace std;

class VectorPatientQueue : public PatientQueue {
public:
    VectorPatientQueue();
    ~VectorPatientQueue();
    string frontName();
    void clear();
    int frontPriority();
    bool isEmpty();
    void newPatient(string name, int priority);
    string processPatient();
    void upgradePatient(string name, int newPriority);
    string toString();

private:
    // TODO: add specified member variable(s)
    // TODO: add any member functions necessary
    void expand();
    int count;
    int capacity;
    int time;
    struct patient{
        string na;
        int pr;
        int timestamp;
    };
    patient *elements;
};
