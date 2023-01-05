#ifndef CLO1_H_INCLUDED
#define CLO1_H_INCLUDED
#include <iostream>

using namespace std;

#define info(P) (P)->info
#define next(P) (P)->next
#define first(L) ((L).first)
#define nil NULL

struct job{
    string jobCode;
    int burstTime;
    int waitingTime;
    int turnAroundTime;
};

typedef struct element *address;

struct element{
    job info;
    address next;
};

struct list{
    address first;
};

void createList(list &L);
address createElement(job j);
void insertLast(list &L, address P);
void deleteLast(list &L, address &P);
address shortestJob(list L);
void printJob(address P);
void printAllJob(list L);
void firstComeFirstServe(list &L);
void shortestJobFirst(list &L);




#endif // CLO1_H_INCLUDED
