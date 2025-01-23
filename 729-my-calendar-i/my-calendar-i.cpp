class MyCalendar {
public:
    set<pair<int,int>>st;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        auto it =st.lower_bound({startTime,endTime});
        //next comparision
        if(it!=st.end() && it->first < endTime) return false;
        //prev comparison
        if(it!=st.begin()){
            auto prevIT=prev(it);
            if(prevIT->second > startTime) return false;
        }
        st.insert({startTime,endTime});
        return true;
    }
};
