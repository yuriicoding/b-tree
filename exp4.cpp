#include <time.h>
#include <iostream>
#include "AvlTree.h"
#include "btree_set.h"
using namespace std;

double elapsed_time( clock_t start, clock_t finish){ 
    return (finish - start)/(double)(CLOCKS_PER_SEC/1000); 
}

int main( int argc, char * const argv[] ){

    const int fill = 8000000;
    const int search = 3000000;

    srand(time(NULL));
    int* searchArr = new int [search];
    for (int i = 0; i < search; i++)
    {
        int nodeVal = rand()%fill;
        searchArr[i] = nodeVal;
    }

    int* nodes = new int [fill];

    for (int i = 0; i < fill; i++)
    {
        nodes[i] = i;
    }

    random_shuffle(nodes, nodes + fill);

    AvlTree<int> avl;

    for (int i = 0; i < fill; i++)
    {
        avl.insert(nodes[i]);
    }

    btree::btree_set<int,std::less<int>,std::allocator<int>, 128> b1;

    for (int i = 0; i < fill; i++)
    {
        b1.insert(i);
    }

    clock_t start1, finish1;

    start1 = clock();

    for (int i = 0; i < search; i++)
    {
        avl.contains(searchArr[i]);
    }

    finish1 = clock();
    double time_taken1 = elapsed_time(start1,finish1);
    cout << "Time taken by AvlTree: " << time_taken1 << " milliseconds." << endl << endl;

    clock_t start2, finish2;

    start2 = clock();

    for (int i = 0; i < search; i++)
    {
        b1.find(searchArr[i]);
    }

    finish2 = clock();
    double time_taken2 = elapsed_time(start2,finish2);
    cout << "Time taken by B-Tree: " << time_taken2 << " milliseconds." << endl << endl;

    return 0;

}
