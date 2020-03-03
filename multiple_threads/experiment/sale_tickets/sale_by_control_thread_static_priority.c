//
// Created by guangsujiqiang on 2/28/20.
// gcc -o sale -lpthread sale.c && ./sale
//
/*
    [guangsujiqiang@su-ct7 sale_tickets]$>gcc -o sale -lpthread sale.c && ./sale
    init tickets number：1000000
    expect values is 813849 ,final surplus tickets number ： 903849
    [guangsujiqiang@su-ct7 sale_tickets]$>gcc -o sale -lpthread sale.c && ./sale
    init tickets number：1000000
    expect values is 810000 ,final surplus tickets number ： 900000

*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <fcntl.h>

void * back();
void * sell();

sem_t* Sem = NULL;
int ticketCount=1000000;
const int cycle_sell = 100000;
const int cycle_back = 10000;

void * back()
{
    int temp;
    int i;
    for(i=0; i < cycle_back;i++)
    {
        //pthread_yield();
        int temp = ticketCount;
        temp = temp + 1;
        pthread_yield();
        ticketCount = temp;

    }
}

void * sell()
{
    int temp;
    int i;
    for(i = 0; i < cycle_sell; i++)
    {
        //pthread_yield();
        int temp = ticketCount;
        temp = temp - 1;
        pthread_yield();
        ticketCount = temp ;
    }

}

int main(int argc,char *argv[]){

    pthread_t p1,p2;
    int c_ret_1,c_ret_2;
    int tmp =  ticketCount;
    printf("init tickets number：%d \n",ticketCount);

    // ------------------------------
    //Sem = sem_open("sem", O_CREAT, 0666, 1);

    c_ret_1 = pthread_create(&p1,NULL,sell,"sell tickets");
    c_ret_2 = pthread_create(&p2,NULL,back,"back tickets");

    pthread_join(p1,NULL);
    pthread_join(p2,NULL);

    //sem_close(Sem);
    //sem_unlink("sem");
    // ------------------------------

    printf("expect values is %d ,final surplus tickets number ： %d \n",tmp - cycle_sell + cycle_back,ticketCount);
    return 0;
}