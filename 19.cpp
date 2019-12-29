#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1, *p2, *p3;
        p1=head;
        int i=0;
        while(p1 != NULL){
            i++;
            if(i==n) p2=head;
            p1=p1->next;
            if(i>n) {p3=p2; p2=p2->next;}
        }
        if(i == n) return head->next;
        else{
            p3->next = p2->next;
            return head;
        }
    }
};
int main(){
   Solution solution;

    return 0;
}
