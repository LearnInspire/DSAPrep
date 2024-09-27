class MyCalendarTwo {
    map<int,int> stops;
public:
    MyCalendarTwo() {
    }
    
    bool book(int start, int end) {
        //Include the interval by default
        stops[start]++;
        stops[end]--;

        int booked = 0; //Count of number of overlaps
        for(auto& stop: stops){ //Check with all bookings already done
            booked += stop.second;
            if(booked>2){       //No available seat
                stops[start]--;
                stops[end]++;

                //Remove unnecessary entries
                if(stops[start]==0)
                    stops.erase(start);
                if(stops[end]==0)
                    stops.erase(end);
                
                return false;
            }
        }
        return true;
    }
};