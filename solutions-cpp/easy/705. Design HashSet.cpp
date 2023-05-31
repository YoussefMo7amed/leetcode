class MyHashSet
{
public:
    vector<bool> arr;

    MyHashSet()
    {
        arr = vector<bool>(1000001);
    }

    void add(int i)
    {
        arr[i] = true;
    }

    void remove(int i)
    {
        arr[i] = false;
    }

    bool contains(int i)
    {
        return arr[i];
    }
};