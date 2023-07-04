#include <time.h>
#include <iostream>
using namespace std;
   
double elapsed_time( clock_t start, clock_t finish){ 
    return (finish - start)/(double)(CLOCKS_PER_SEC/1000); 
} 
   
int main (int argc, char * const argv[]) {
    //Size of one integer variable is 4 bytes
    //L1d cache:                       288 KiB
    //L1i cache:                       192 KiB
    //L2 cache:                        7.5 MiB
    //L3 cache:                        144 MiB
    //2.1 milliseconds up to 4000000 size of array
    //
    const int SIZE1 = 50000000;
    const int STEP = 100000;

    int* a = new int [SIZE1];

    for (int i = 0; i < SIZE1; i++)
    {
        a[i] = i;
    }
    double sum = 0;
    for (int i = 0; i < 50; i++)
    {
        clock_t start1, finish1; 
        start1 = clock(); 

        for (int i = 0; i < STEP; i++)
        {
            a[(i*256)%SIZE1]++;
        }
        finish1 = clock(); 
        double time_taken1 = elapsed_time(start1,finish1); 
        sum = sum + time_taken1;
    }
    cout << "Average processing time of a given array: " << sum/50 << " milliseconds." << endl;
}