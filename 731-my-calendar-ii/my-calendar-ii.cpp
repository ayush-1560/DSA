class MyCalendarTwo {
public:
    vector<pair<int,int>>doubleOverLap;
    vector<pair<int,int>>bookings;

    bool isOverLap(int start1, int end1, int start2, int end2){
        return (max(start1,start2)<min(end1,end2));
    }
    pair<int,int> findOverLapRegion(int start1, int end1, int start2, int end2){
        return {max(start1,start2),min(end1,end2)};
    }
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(auto region : doubleOverLap){
            if(isOverLap(region.first,region.second,start,end)){
                return false;
            }
        }
        for(auto booking : bookings){
            if(isOverLap(booking.first,booking.second,start,end)){
                doubleOverLap.push_back(findOverLapRegion(booking.first,booking.second,start,end));
            }
        }
        bookings.push_back({start,end});
        return true;
    }
};
