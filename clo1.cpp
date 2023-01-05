#include "clo1.h"

void createList(list &L){
    first(L) = nil;
}
address createElement(job j){
    address P = new element;

    info(P) = j;
    next(P) = nil;
    return P;
}
void insertLast(list &L, address P){
    address Q = first(L);

    if (first(L) == nil){
        first(L) = P;
    }else{
        while(next(Q) != nil){
        Q = next(Q);
        }
        next(Q) = P;
    }
}
void deleteLast(list &L, address &P){
    address Q = first(L);

    while(next(Q)!= nil){
        Q = next(Q);
    }
    P = next(Q);
    next(Q) = nil;
}
address shortestJob(list L){
    address P = first(L);
    address Q;
    int shortest = 999;

    while(P != nil){
        if (info(P).burstTime < shortest){
            shortest = info(P).burstTime;
            Q = P;
        }
        P = next(P);
    }
    return Q;
}
void printJob(address P){
    cout<<endl<<"=======PrintJob========"<<endl;
    cout<<"jobCode dengan burst time terkecil adalah"<<endl;
    cout<<info(P).jobCode<<"\t"<<info(P).burstTime<<endl;
    cout<<endl;
}
void printAllJob(list L){
    address P = first(L);
    cout<<endl<<"=======PrintAllJob========"<<endl;
    cout<<"jobCode\t\t"<<"burstTime"<<endl;
    if (first(L) != nil){
        while (P!=nil){
        cout<<info(P).jobCode<<"\t\t"<<info(P).burstTime<<endl;
        P=next(P);
        }
    }else{
        cout<<"List Kosong"<<endl;
    }
    cout<<endl;
}
void firstComeFirstServe(list &L){
    address P = first(L);
    int tempWT = 0;
    int tempTAT = 0;
    int totalWT = 0;
    int totalTAT = 0;
    float averageWT;
    float averageTAT;

    cout<<"waiting time dari ";
    while(P!=nil){
        if (P == first(L)){
            info(P).waitingTime = 0;
            tempWT = tempWT + info(P).burstTime;
            totalWT = totalWT + info(P).waitingTime;
            cout<<info(P).jobCode<<"="<<info(P).waitingTime;
        }else{
            info(P).waitingTime = tempWT;
            tempWT = tempWT + info(P).burstTime;
            totalWT = totalWT + info(P).waitingTime;
            cout<<info(P).jobCode<<"="<<info(P).waitingTime;
        }
        if(next(P)!=nil){
            cout<<",";
        }
        P = next(P);
    }
    cout<<endl;


    int N = 1;
    P = first(L);
    cout<<"average time dari waiting time adalah = ";
    while(P!=nil){
        if (P == first(L)){
            cout<<"("<<info(P).waitingTime;
        }else{
            cout<<info(P).waitingTime;
        }
        if(next(P)!=nil){
            cout<<"+";
        }
        N++;
        P = next(P);
    }
    averageWT = float(totalWT) / float(N);
    cout<<") / "<<N<<" = "<<averageWT<<endl;

    P = first(L);
    cout<<"turn around time dari ";
    while(P!=nil){
        if (P == first(L)){
            info(P).turnAroundTime = info(P).burstTime;
            tempTAT = tempTAT + info(P).burstTime;
            totalTAT = totalTAT + info(P).turnAroundTime;
            cout<<info(P).jobCode<<"="<<info(P).turnAroundTime;
        }else{
            info(P).turnAroundTime = tempTAT + info(P).burstTime;
            tempTAT = tempTAT + info(P).burstTime;
            totalTAT = totalTAT + info(P).turnAroundTime;
            cout<<info(P).jobCode<<"="<<info(P).turnAroundTime;
        }
        if(next(P)!=nil){
            cout<<",";
        }
        P = next(P);
    }
    cout<<endl;

    N = 1;
    P = first(L);
    cout<<"average time dari turn around time adalah = ";
    while(P!=nil){
        if (P == first(L)){
            cout<<"("<<info(P).turnAroundTime;
        }else{
            cout<<info(P).turnAroundTime;
        }
        if(next(P)!=nil){
            cout<<"+";
        }
        N++;
        P = next(P);
    }
    averageTAT = float(totalTAT) / float(N);
    cout<<") / "<<N<<" = "<<averageTAT<<endl;

}
void shortestJobFirst(list &L);

