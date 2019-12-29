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
    ListNode* swapPairs(ListNode* head) {
        int i=2;
        ListNode *p0=NULL, *p1=head, *p2=head->next;
        head = head->next;
        while(i == 2){
            ListNode *p3 = p2->next; // 记录后续节点
            if(p0) p0->next = p2;
            p2->next = p1;
            p1->next = p3;
            // 后面的
            i=0;
            p0 = p1;
            if(p3){p1=p3; i++;}
            if(p3 && p3->next){p2=p3->next; i++;}
        }
        return head;
    }
};

int main(){
    ListNode l1(1),l2(2),l3(3),l4(4);
    l1.next = &l2; l2.next = &l3; l3.next = &l4;
   Solution solution;
    solution.swapPairs(&l1);
    return 0;
}
