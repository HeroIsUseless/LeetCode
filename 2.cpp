struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = NULL;
        ListNode* l3 = NULL;
        int carry = 0; // 进位标志
        while((carry!=0) || (l1!=NULL) || (l2!=NULL)){
            ListNode* t_node = new ListNode(0);
            t_node->val = carry + (l1?l1->val:0) + (l2?l2->val:0);
            if(l1) l1 = l1->next; if(l2) l2 = l2->next; // 向下一位移动
            if(t_node->val > 9){ // 判断是不是需要进位，修改进位标志
                t_node->val -= 10;
                carry = 1;
            }
            else carry = 0;

            if(l3 == NULL){ // 第一个要特殊处理
                l3 = t_node;
                res = l3;
            } 
            else{
                l3->next = t_node;
                l3 = l3->next;
            } 
        }
        return res;
    }
};