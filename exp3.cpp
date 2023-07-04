#include "List.h"
#include "queue.h"
#include <time.h>
#include <iostream>
using namespace std;

double elapsed_time( clock_t start, clock_t finish){ 
    return (finish - start)/(double)(CLOCKS_PER_SEC/1000); 
}

int main ( int argc, char * const argv[] ){

    const int SIZE = 8000000;
    const unsigned int Capacity = 10000;

    Queue<Capacity> ulinkList;

    for (int i = 0; i < SIZE; i++)
    {
        ulinkList.enqueue(i);
    }

    List<int> linkList;
    for (int i = 0; i < SIZE; i++)
    {
        linkList.push_back(i);
    }

    int* array = new int [SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = i;
    }

    int* array_filler = new int [SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        array_filler[i] = i;
    }

    clock_t start1, finish1;
    start1 = clock();

    ulinkList.touch_all();

    finish1 = clock();
    double time_taken1 = elapsed_time(start1,finish1);
    cout << "Time taken by unrolled linked list: " << time_taken1 << " milliseconds." << endl << endl;

    clock_t start2, finish2;
    start2 = clock();

    linkList.touch_all();

    finish2 = clock();
    double time_taken2 = elapsed_time(start2,finish2);
    cout << "Time taken by linked list: " << time_taken2 << " milliseconds." << endl << endl;

    clock_t start3, finish3;
    start3 = clock();

    for (int i = 0; i < SIZE; i++)
    {
        array[i]++;
    }
    
    finish3 = clock();
    double time_taken3 = elapsed_time(start3,finish3);
    cout << "Time taken by array: " << time_taken3 << " milliseconds." << endl << endl;
}
