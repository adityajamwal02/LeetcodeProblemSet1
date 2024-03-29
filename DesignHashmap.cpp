/*
Design a HashMap without using any built-in hash table libraries.
Implement the MyHashMap class:
MyHashMap() initializes the object with an empty map.
void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.
*/

/// Map using

class MyHashMap {
public:
    unordered_map<int, int> mp;

    MyHashMap() {

    }

    void put(int key, int value) {
        mp[key]=value;
    }

    int get(int key) {
        if(mp.count(key)==true)
            return mp[key];
        else
            return -1;
    }

    void remove(int key) {
         if(mp.count(key)==true)
            mp.erase(key);
    }
};


/// Vector Using
   vector<int> mp;

MyHashMap() {

    mp.resize(1e6+1,-1);
}

void put(int key, int value) {

    mp[key]=value;
}

int get(int key) {

    if(mp[key] != -1)
        return mp[key];

    return -1;
}

void remove(int key) {

    mp[key]=-1;
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
