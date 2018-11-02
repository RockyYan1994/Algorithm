/*
	HashTable + DoubleLinkedList
*/

//version 1(56 ms)
class LRUCache {
    private int capacity;
    
    private class DoubleLinkedList {
        int key;
        int val;
        DoubleLinkedList pre;
        DoubleLinkedList post;
        public DoubleLinkedList(int key, int val) {
            this.key = key;
            this.val = val;
        }
        public DoubleLinkedList() {}
    }

    DoubleLinkedList head, tail;
    private Map<Integer, DoubleLinkedList> cache;
    
    public LRUCache(int capacity) {
        this.capacity = capacity;
        cache = new HashMap<>();
        head = new DoubleLinkedList();
        tail = new DoubleLinkedList();
        head.pre = null;
        head.post = tail;
        tail.pre = head;
        tail.post = null;
    }
    
    private void insertNode(DoubleLinkedList node) {
        node.pre = head;
        node.post = head.post;
        head.post.pre = node;
        head.post = node;
    }
    
    private DoubleLinkedList removeNode(DoubleLinkedList node) {
        node.pre.post = node.post;
        node.post.pre = node.pre;
        return node;
    }
    
    private DoubleLinkedList removeTail() {
        DoubleLinkedList res = tail.pre;
        res.pre.post = tail;
        tail.pre = res.pre;
        return res;
    }
    
    public int get(int key) {
        if (!cache.containsKey(key)) return -1;
        DoubleLinkedList node = cache.get(key);
        removeNode(node);
        insertNode(node);
        return node.val;
    }
    
    public void put(int key, int value) {
        DoubleLinkedList node;
        if (cache.containsKey(key)) {
            node = cache.get(key);
            node.val = value;
            removeNode(node);
            insertNode(node);
        } else {
            if (cache.size() == capacity) {
                DoubleLinkedList rem = removeTail();
                cache.remove(rem.key);
            }
            node = new DoubleLinkedList(key, value);
            insertNode(node);
            cache.put(key, node);
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */