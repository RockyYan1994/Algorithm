/*
	利用一个list和一个unordered_map来实现，unordered_map采用的是unordered_map<int,pair<int,list<int>::iterator> >结构，
	这个问题主要需要熟悉STL数据结构的操作，比如list的操作，索引，erase等。
*/


//version 1(84 ms)
class LRUCache {
public:
    LRUCache(int capacity):_capacity(capacity) {
    }
    
    int get(int key) {
        auto it = _cache.find(key);
        if(it == _cache.end()) return -1;
        
        touch(it);
        return it->second.first;
    }
    
    void put(int key, int value) {
        auto it = _cache.find(key);
        if(it == _cache.end()){
            if(_lru.size() == _capacity){
                _cache.erase(_lru.back());
                _lru.pop_back();
            }
            _lru.push_front(key);
            _cache[key] = {value, _lru.begin()};
        }
        else{
            touch(it);
            _cache[key] = {value, _lru.begin()};
        }
    }
private:
    list<int> _lru;
    unordered_map<int,pair<int,list<int>::iterator> > _cache;
    const int _capacity;
    
    void touch(unordered_map<int, pair<int, list<int>::iterator> >::iterator& it){
        _lru.erase(it->second.second);
        _lru.push_front(it->first);
        it->second.second = _lru.begin();
    }
};