extern "C"{
    // Add the header files required to run your main 
    #include "insertion_sort.h"
    #include "linked_list.h"
    #include "list_queue.h"

}

// File for sandboxing and trying out code
int main(int argc, char **argv)
{

    int testlist[] ={4,3,10,1,6};
    {
    linked_list* test = createLinkedList();
    for (int i = 0; i < 5; ++i)
    {
        insertFront(createNode(testlist[5-i-1]), test);
    }
    
    printLL(test);
    sort(test);
    printLL(test);
    queue q;
    init_queue(&q);
    printf("%d\n", empty(&q));

    //Above test is my test for sorting a list

   /* queue q;
    init_queue(&q);
    printf("%d\n", empty(&q));
    enqueue(&q, 10);
    enqueue(&q, 5);
    enqueue(&q, 15);
    printf("%d\n", empty(&q));
    printf("%d\n", q.front->data);
    //printf("%d", q.front->next->data);
    printf("%d", q.rear->data);
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d", empty(&q));*/
    return 0;

}
}