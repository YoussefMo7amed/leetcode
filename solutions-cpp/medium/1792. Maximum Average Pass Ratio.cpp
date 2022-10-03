// The idea is to increase the lowest average class each time.
struct klass {
    int pass;
    int total;
    double ratio;
    klass() {}
    klass(int pass, int total) {
        this->pass = pass;
        this->total = total;
        update_ratio();
    }
    void update_ratio() { ratio = pass * 1.0 / total; }
    void increase(int by = 1) {
        pass += by;
        total += by;
        update_ratio();
    }
    double delta() {
        return (pass + 1) * 1.0 / (total + 1) - (pass)*1.0 / (total);
    }
    bool operator()(klass &a, klass &b) { return a.delta() < b.delta(); }
};

class Solution {
   public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents) {
        priority_queue<klass, vector<klass>, klass> pq;
        int total = classes.size();
        double sum = 0;
        klass k;
        for (auto i : classes) {
            k = klass(i[0], i[1]);
            pq.push(k);
        }
        while (extraStudents--) {
            k = pq.top();
            pq.pop();
            k.increase();
            pq.push(k);
        }
        while (pq.size()) {
            cout << sum << endl;
            sum += pq.top().ratio;
            pq.pop();
        }
        return sum / total;
    }
};