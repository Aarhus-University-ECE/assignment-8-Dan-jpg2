#include "list_queue.h"
#include <assert.h>


void init_queue(queue *q)
{
  // Add your init_queue
  //Initialize of the queue
  q->front = NULL; //
  q->rear = NULL; //rear pointer has no value
  q->size = 0; //set size to 0
}

int empty(queue *q)
{
  // Add your empty function
  return(q -> size <= 0); //queue size has to be zero or less to be empty.
}

void enqueue(queue *q, int x)
{
  // Add your enqueue function
  qnode *new = malloc(sizeof(qnode)); //Creating new node 
  if(q -> rear == NULL) //if the end of node is undefined size
  {
    q -> rear = new; //new node points to  last node
    q -> rear -> data = x; //add data to new node 
    q -> size++;
  }
  else if(q -> front == NULL) //if front is some undefined size 
  {
    q -> front = new; //new node becomes q's first node.
    q -> front -> data = x; //add data to new node
    q -> rear -> next = q -> front;  //makes the front and last node the same 
    q -> size++;
  }
  else
  {
    q -> front -> next = new; //New next front node
    q -> front = new; //new front node
    q -> front -> data = x; //add data to new node
    q -> size++;
  }

}
int dequeue(queue *q)
{
  // Add your dequeue function
  int return_value = q -> rear -> data;
  qnode *temp = q -> rear; //starting at rear of queue
  q -> rear = q -> rear -> next; 
  q -> size = q -> size - 1; //after dequeue removing 1 from size
  free(temp);
  return return_value;
}

