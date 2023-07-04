all: exp1 exp2 exp3 exp4

exp1: exp1.o
	g++ -Wall -o exp1 exp1.o
	
exp1.o: exp1.cpp
	g++ -Wall -o exp1.o -c exp1.cpp

exp2: exp2.o
	g++ -Wall -o exp2 exp2.o
	
exp2.o: exp2.cpp
	g++ -Wall -o exp2.o -c exp2.cpp
	
exp3: exp3.o
	g++ -Wall -o exp3 exp3.o
	
exp3.o: exp3.cpp queue.h List.h dsexceptions.h
	g++ -Wall -o exp3.o -c exp3.cpp
	
exp4: exp4.o 
	g++ -Wall -o exp4 exp4.o
	
exp4.o: exp4.cpp btree.h btree_set.h btree_container.h AvlTree.h dsexceptions.h
	g++ -Wall -o exp4.o -c exp4.cpp

clean:
	rm -f exp1 exp2 exp3 exp4 *.o
