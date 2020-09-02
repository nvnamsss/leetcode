public class MyHashSet {
    private int[] array;
    private int bucket = 1000000;
    /** Initialize your data structure here. */
    public MyHashSet() {
        array = new int[bucket];
    }

    private int Hash(int key)
    {
        return ((key*3) & (1<<16) - 1)>>(16-14) % bucket;
    }

    private void Collision()
    {

    }
    
    public void Add(int key) {
        int index = Hash(key);
        array[index] = key;

    }
    
    public void Remove(int key) {
        int index = Hash(key);
        array[index] = 0;
    }
    
    /** Returns true if this set contains the specified element */
    public bool Contains(int key) {
        int index = Hash(key);
        return array[index] == key;        
    }
}
