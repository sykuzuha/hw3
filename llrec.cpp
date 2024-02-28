#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot)
{
    if (head == nullptr)
    {
        //cout << "return" << endl;
        smaller = nullptr;
        larger = nullptr;
        return;
    }
    Node* next = head->next;
    llpivot (next, smaller, larger, pivot);
    if(head->val <= pivot)
    {

        head->next = smaller;
        smaller = head;
        head = nullptr;
        //cout << "adding " << head->val << " to smaller" << endl;      
    }
    else if(head->val > pivot)
    {
        head->next = larger;
        larger = head;
        head = nullptr;
        //cout << "adding " << head->val << " to larger" << endl;
    }
}
