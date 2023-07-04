#include <iostream>
#include <time.h>
using namespace std;

double elapsed_time( clock_t start, clock_t finish){ // returns elapsed time in milliseconds 
    return (finish - start)/(double)(CLOCKS_PER_SEC/1000); 
} 

int main(int argc, char * const argv[])
{
    const int SIZE = 6400000;
    cout << "Array a, b, c and d have the same number of elements, which is: " << SIZE << endl;
    
    int* a = new int [SIZE];
    int* b = new int [SIZE];
    int* c = new int [SIZE];
    int* d = new int [SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        a[i] = 2;
        b[i] = 3;
        c[i] = 4;
    }

    // Last loop is separated to make sure that cache is filled with elements of array d
    // and this stage won't affect testing of array a
    for (int i = 0; i < SIZE; i++)
    {
        d[i] = 5;
    }

    clock_t start1, finish1, start2, finish2;

    start1 = clock(); 
    for (int i = 0; i < SIZE-15; i = i+64)
    {
            for (int j = 0; j < 16; j++)
            {
            a[i+j] *= 2;
            }
    }  
    finish1 = clock(); 
    double time_taken1 = elapsed_time(start1,finish1);
    cout << "Array a traverses elements with a step of 64 and" << 
    " contains inner loop that makes 16 extra multiplications each step." << endl;
    cout << "Time taken by array a: " << time_taken1 << " milliseconds." << endl << endl;

    start2 = clock();
    for (int i = 0; i < SIZE; i = i+64)
    {
        b[i] *= 2;
    }
    finish2 = clock();
    double time_taken2 = elapsed_time(start2, finish2);
    cout << "Array b traverses elements with a step of 64." << endl;
    cout << "Time taken by array b: " << time_taken2 << " milliseconds." << endl << endl;

    clock_t start3, finish3;

    start3 = clock(); 
    for (int i = 0; i < SIZE-16; i = i+64)
    {
            c[i] *= 2;
            c[i+1] *= 2;
            c[i+2] *= 2;
            c[i+3] *= 2;
            c[i+4] *= 2;
            c[i+5] *= 2;
            c[i+6] *= 2;
            c[i+7] *= 2;
            c[i+8] *= 2;
            c[i+9] *= 2;
            c[i+10] *= 2;
            c[i+11] *= 2;
            c[i+12] *= 2;
            c[i+13] *= 2;
            c[i+14] *= 2;
            c[i+15] *= 2;
            c[i+16] *= 2;
    } 
    finish3 = clock(); 
    double time_taken3 = elapsed_time(start3,finish3);
    cout << "Array c traverses elements with a step of 64 and" << 
    " contains 16 extra multiplications each step." << endl;
    cout << "Time taken by array c: " << time_taken3 << " milliseconds." << endl << endl;

    double cache_miss = (time_taken2)/100000;
    double cache = (time_taken3 - time_taken2)/(1600000);

    cout << "Average time of element access without a cache miss (+ time of 1 multiplication, which is negligible): " << cache << " milliseconds." << endl;
    cout << "Average time of element access with a cache miss (+ time of 1 multiplication, which is negligible): " << cache_miss << " milliseconds." << endl << endl;
}
