#include "insertion_sort.h"
#include "linked_list.h"



void sort(linked_list *llPtr)
{
    node_t *pointer = llPtr->head;
    node_t *temporary;
    node_t *temporary_pointer = llPtr->head;

    while(pointer -> next != NULL) //Loop runs as long as there is a value to allocate
    {
        if(pointer -> data >= (pointer -> next -> data)) //if current data is bigger find place
        {
            temporary = pointer -> next;
            printLL(llPtr); 
            pointer -> next = pointer -> next -> next;
            while(temporary_pointer != pointer -> next)
            {
                if(temporary -> data <= temporary_pointer -> data)
                {
                    temporary -> next = temporary_pointer;
                    llPtr -> head = temporary;
                    break;
                }
                else if ((temporary -> data) <= (temporary_pointer -> next -> data))
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
            pointer = pointer -> next; 
    }
}
    /*/ Add your sort function here
node_t *temp = NULL;
node_t *temp_next = NULL;
node_t *previous = llPtr->head;
node_t *current = previous->next;

if(llPtr->head == NULL)
    {
        printf("list is empty");
        return; 
    }


while (previous->next != NULL) //Loop runs as long as there is a next node to allocate
{
    if(current->data < previous->data) // If current node is less or equal than previous, find place. 
    {
        temp = current; 
        temp_next = current->next;
        previous->next = current->next; 

        node_t *placement = llPtr->head;
        while(placement->next->data < temp->data)
        {
            placement = placement->next;
        }
        if(llPtr->head == placement)
        {
            temp->next = llPtr->head;
            llPtr->head = temp;

        }
            else 
            {
                temp_next->next = placement->next;
                placement->next = temp;
            }
    }
    
    previous = current;
    current = previous->next;
    } */
