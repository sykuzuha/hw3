#include "llrec.h"
#include <iostream>
using namespace std;

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot)
{
    if (head == nullptr)
    {
        cout << "return";
        return;
    }
    Node* next = head->next;
    if(head->val < pivot)
    {

        head->next = smaller;
        smaller = head;
        cout << "adding " << head->val << " to smaller" << endl;
        llpivot (next, smaller, larger, pivot);
    }
    else if(head->val >= pivot)
    {
        head->next = larger;
        larger = head;
        cout << "adding " << head->val << " to larger" << endl;
        llpivot (next, smaller, larger, pivot);
    }
}
