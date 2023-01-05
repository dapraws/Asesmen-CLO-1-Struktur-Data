#include "clo1.h"

int main()
{
    list L;
    int N,i;
    address P,Q;
    job j;

    cout<<"~~~Selamat Datang~~~"<<endl<<endl;
    createList(L);
    cout<<"Masukan jumlah data yang akan diinput: ";
    cin>>N;
    i = 1;
    while(i<=N){
        P = createElement(j);
        cin>>info(P).jobCode;
        cin>>info(P).burstTime;
        insertLast(L, P);
        i++;
    }
    printAllJob(L);

    Q = shortestJob(L);
    printJob(Q);

    firstComeFirstServe(L);

}
