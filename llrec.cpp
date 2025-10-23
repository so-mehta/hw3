#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************



void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot){

    if (head == NULL){ //have reached end of list
        smaller = NULL;
        larger = NULL;
        return;
    }
   

    // Node* rest = head->next;
    // head->next = nullptr;
    // llpivot(rest, smaller, larger, pivot);
    llpivot(head -> next, smaller, larger, pivot);

    if (head -> val <= pivot){
        head -> next = smaller;
        smaller = head;
    } else if (head -> val > pivot){
        head -> next = larger;
        larger = head;
    }


    head = NULL;    


}
