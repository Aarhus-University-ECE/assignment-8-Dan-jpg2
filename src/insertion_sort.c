#include "insertion_sort.h"
#include "linked_list.h"



void sort(linked_list *llPtr)
{
    node_t *pointer = llPtr->head; //keeping track of current node
    node_t *temporary; 
    node_t *temporary_pointer = llPtr->head;

    while(pointer -> next != NULL) //Loop runs as long as we are not at the end of list
    {
        if(pointer -> data >= (pointer -> next -> data)) //if current data is bigger than next move along
        {
            temporary = pointer -> next;
            printLL(llPtr); 
            pointer -> next = pointer -> next -> next;
            while(temporary_pointer != pointer -> next) //
            {
                if(temporary -> data <= temporary_pointer -> data) //If current data is less than what we want to move then stop
                {
                    temporary -> next = temporary_pointer;
                    llPtr -> head = temporary;
                    break;
                }
                else if ((temporary -> data) <= (temporary_pointer -> next -> data)) //If current data is less than the next data we want to move stop
                {
                    temporary -> next = temporary_pointer -> next;
                    temporary_pointer -> next = temporary;
                    break;
                }
                temporary_pointer = temporary_pointer -> next;
            }
            temporary_pointer = llPtr -> head;
        }
        else 
            pointer = pointer -> next; //If next node is larger than the current. 
    }
}
