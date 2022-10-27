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
  if(q -> rear == NULL)
  {
    q -> rear = new; //new node is q's last node
    q -> rear -> data = x; //add data to new node 
    q -> size++;
  }
  else if(q -> front == NULL)
  {
    q -> front = new;
    q -> front -> data = x; //add data to new node
    q -> rear -> next = q -> front; 
    q -> size++;
  }
  else
  {
    q -> front -> next = new; 
    q -> front = new;
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

