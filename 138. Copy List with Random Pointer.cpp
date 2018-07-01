/*
	通过三个循环实现，空间O(1)，时间O(n)：
	1，复制每个节点并且链接到原节点后；
	2，复制每个节点的random指针；
	3，分开copy节点和原节点。
*/

//version 1(43 ms)
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;
        RandomListNode *cur = head, *next;
        while(cur){
            next = cur -> next;
            RandomListNode* copy = new RandomListNode(cur->label);
            copy -> next = next;
            cur -> next = copy;
            cur = next;
        }
        
        cur = head;
        while(cur){
            if(cur -> random)cur ->next ->random = cur -> random -> next;
            cur = cur -> next -> next;
        }
        
        RandomListNode* copyHead = new RandomListNode(0);
        cur = head;
        RandomListNode *copy ,*copyLast = copyHead;
        while(cur){
            next = cur -> next -> next;
            
            copy = cur -> next;
            copyLast -> next = copy;
            copyLast = copy;
            
            cur -> next = next;
            cur = next;
        }
        return copyHead -> next;
    }
};