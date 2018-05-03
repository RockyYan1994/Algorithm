/*
输入两个链表，找出它们的第一个公共结点。
第一个算法主要根据只要有一个公共节点，那么从公共节点开始往后就一定是相同的，这样可以去除前面的一段，让两个链表的长度相等，然后同时往后遍历。
第二个算法不用纪录长度，具体的解释根据评论

        假定 List1长度: a+n  List2 长度:b+n, 且 a<b
        那么 p1 会先到链表尾部, 这时p2 走到 a+n位置,将p1换成List2头部
        接着p2 再走b+n-(n+a) =b-a 步到链表尾部,这时p1也走到List2的b-a位置，还差a步就到可能的第一个公共节点。
        将p2 换成 List1头部，p2走a步也到可能的第一个公共节点。如果恰好p1==p2,那么p1就是第一个公共节点。  
		或者p1和p2一起走n步到达列表尾部，二者没有公共节点，退出循环。 同理a>=b.
        时间复杂度O(n+a+b)
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int l1=0,l2=0;
        ListNode *cur = pHead1;
        while(cur){
            l1++;
            cur = cur->next;
        }
        cur = pHead2;
        while(cur){ l2++; cur = cur->next; }
        while(l1 != l2){
            if(l1>l2){l1--;pHead1 = pHead1->next;}
            else if(l1<l2){l2--;pHead2 = pHead2->next;}
        }
        while(pHead1 != pHead2){
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return pHead1;
    }
};


链接：https://www.nowcoder.com/questionTerminal/6ab1d9a29e88450685099d45c9e31e46
来源：牛客网

class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode *pHead1, ListNode *pHead2) {
        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;
        while(p1!=p2){
            p1 = (p1==NULL ? pHead2 : p1->next);
            p2 = (p2==NULL ? pHead1 : p2->next);
        }
        return p1;
    }
};