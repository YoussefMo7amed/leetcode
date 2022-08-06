class MyCalendar {
public:
    vector<pair<int,int> > v;
    MyCalendar() {

    }

    bool book(int start, int end) {
        for(auto p :v){
            if(p.first < end && p.second > start)
                return false;
        }
        v.push_back(make_pair(start, end));
        return true;
    }
};
