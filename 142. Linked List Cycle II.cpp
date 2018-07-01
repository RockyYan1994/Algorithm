/*
	主要利用数学性质，
	假设fast路径：sum_fast = m + k + a * l;
		slow:   sum_slow = m + k + b * l;
				sum_fast = 2 * sum_slow
	m 进入循环开始节点前的路径
	k 从循环开始到当前位置距离
	l 循环长度
	a，b分别为fast和slow在循环中经过的圈数
	根据上面的三个公式，解得：m = (b - 2a)l - k
	可以知道从head到当前位置的距离为l的整数倍。
	因此只需要让slow和一个指向头节点的指针同时后移，当他们相同时，就是开始节点。
*/

//version 1(12 ms)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        ListNode *slow = head, *fast = head;
        while(fast && fast -> next ){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast ) break;
        }
        if(!fast || !fast->next) return NULL;
        fast = head;
        while(slow != fast) {
            slow = slow -> next;
            fast = fast -> next;
        }
        return slow;
    }
};

//version 2(11 ms)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        ListNode *slow = head, *fast = head;
        while(fast && fast -> next ){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast ) {
                fast = head;
                while(slow != fast){
                    slow = slow -> next;
                    fast = fast -> next;
                }
                return slow;
            }
        }
        return NULL;
    }
};