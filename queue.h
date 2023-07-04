/* File: queue.h       
 *
 *   Simle Unrolled-linked-list implementation of a Queue class.
 *   Templated lNode-capacity  Unrollowed 
 *   Header file for very basic unrolled-linked-list implementation of a Queue class.
 *
 *   */
#include <cstring> // For declaration of NULL
#include <iostream>
using namespace std;

template <unsigned int NodeCapacity>
class Queue
{
  public:

    Queue(); // Constructs a new empty queue.
//    ~Queue();// Destructor.

    void enqueue( int item ); // Enqueues <item>.
    int dequeue();  // Dequeues the front item.
    int front();  // Returns the front item without dequeuing it.
    int size();  // Returns the current number of items in the queue.
    void display(); // Print a representaiton of the queue to stdout.
    void touch_all(); // add 3 to each array element in the list.

  private:
    class Node  // node type for the linked list 
    {
       // Node instances are essentially queues implemented with 
       // partially-filled arrays, but they do not use the "circular
       // array" method - once the n_rear index reaches the end, 
       // no more insertions can be made - we just hae to use 
       // a new node instance for further insertions.
       public:
           Node(){
              next = NULL ; // pointer to next node in linked list.
              n_size = 0 ; // number of elements currently in node.
              n_front = 0 ;// index of first element of queue, if n_size>0.
              n_rear = 0 ;// index where next element will be inserted,
                          // or NodeCapacity.
           }

           void insert(int item){
              // We only execute insert if there is space.
              data[n_rear] = item ;   
              n_rear ++ ;
              n_size ++ ;
           }

           int remove(){
              // We only execute remove if the node is non-empty.
              int temp = data[n_front] ;
              n_size -- ;
              n_front ++ ;
              return temp ;
           }

           int front(){
              return data[n_front];
           }

           bool isEmpty(){
              return n_size == 0 ;
           }

           bool hasSpace(){
              return n_rear < static_cast<int>(NodeCapacity) ;
           }
 
           void display(){
             std::cout << "[" << n_size << "(" << n_front << "," << n_rear << "):" << data[0] ;
             for( int i = 1 ; i < NodeCapacity ; i++ ){
                std::cout << ", " << data[i] ;
             } 
             std::cout << "]" ;
           }

           void touch_all(){
             // implement this
             //
             //
             for( int i = 1 ; i < static_cast<int>(NodeCapacity) ; i++ ){
                data[i] = data[i] + 3;
             } 
           }

           Node * next ;
           int n_front ;
           int n_rear ;
           int n_size;
           int data[NodeCapacity] ;
    };

    int q_size ;     // current number of elements in the queue.
    Node * front_p ; // pointer to the first node in the linked list.
                     // will never be null (even for an empty queue).
    Node * rear_p ;  // pointer to the last node in the linked list.
                     // will never be null (even for an empty queue).
                     // will sometimes be the same node as front_p.
};

// constructor
template<unsigned int NodeCapacity> Queue<NodeCapacity>::Queue(){
   front_p = new Node() ;
   rear_p = front_p ;
   q_size = 0 ;
} 

// enqueue
template<unsigned int NodeCapacity> void Queue<NodeCapacity>::enqueue( int item ){
   if( ! rear_p->hasSpace() ){
      rear_p->next = new Node();
      rear_p = rear_p->next ;
   }
   rear_p->insert(item);
   q_size++;
}

// dequeue
template<unsigned int NodeCapacity> int Queue<NodeCapacity>::dequeue(){
   q_size-- ;
   int temp = front_p->remove();
   if( front_p->isEmpty() ){
      if( front_p->next == NULL ){
         // there is an empty front node and no following node.
         // the queue is empty.
         // if there is no space remaining in the fron node,
         // replace it with a new one.
         if( !front_p->hasSpace() ){
            Node * temp = front_p ;
            front_p = temp->next ;
            delete temp ;
            front_p = new Node();
            rear_p = front_p;
         } 
      }else{
         // front_p->next!=NULL 
         // there is an empty front node and a following node.
         // delete the empty front node.
         Node * temp = front_p ;
         front_p = temp->next ;
         delete temp ;
      }
   }
   return temp ;
}

// front
template<unsigned int NodeCapacity> int Queue<NodeCapacity>::front(){
// returns the front item without dequeuing it.
   return front_p->front();
}

// size
template<unsigned int NodeCapacity> int Queue<NodeCapacity>::size(){
// the current number of items in the queue.
   return q_size;
}

// display
template<unsigned int NodeCapacity> void Queue<NodeCapacity>::display(){
   int s = 0 ;
   Node * p = front_p ;
   while( p != NULL ){
      std::cout << "<" << s << ":" ;
      p->display();
      std::cout << ">" ;
      p = p->next ;
      s++ ;
   }
   std::cout << std::endl ;
}

// touch_all
template<unsigned int NodeCapacity> void Queue<NodeCapacity>::touch_all(){
   // implement this
   //
   //
   Node * p = front_p ;
   while( p != NULL ){
      p->touch_all();
      p = p->next ;
   }
}


