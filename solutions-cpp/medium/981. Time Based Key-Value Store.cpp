struct values {
    vector<int> ts;
    vector<string> s;
    int size = 0;
    values() {}
    values(int timestamp, string value) { add(timestamp, value); }
    void add(int timestamp, string value) {
        ts.push_back(timestamp);
        s.push_back(value);
        size++;
    }
    // 3 cases:
    // 1 - size = 0 -> (empty)
    // 2 - size < index -> Not found then index > size, should be size - 1
    // 3 - ts[index] > timestamp -> should be <= timestamp
    // 3.1 if the value <= timestamp return it
    // 3.2 if the lowest value > timestamp return empty string
    string find(int timestamp) {
        if (size == 0)
            return "";
        else {
            int index =
                lower_bound(ts.begin(), ts.end(), timestamp) - ts.begin();
            if (index >= size) index = size - 1;

            while (index > 0 && ts[index] > timestamp) index--;

            if (ts[index] <= timestamp)
                return s[index];
            else
                return "";
        }
    }
};

class TimeMap {
   public:
    map<string, values> mp;
    TimeMap() {}
    void set(string key, string value, int timestamp) {
        mp[key].add(timestamp, value);
    }
    string get(string key, int timestamp) { 
        return mp[key].find(timestamp); 
    }
};