class MovingAverage {

private: 
    int size, windowSum = 0, count = 0;
    deque<int> queue;

public:
    MovingAverage(int size){this->size=size;}

    double next(int val){
        count++;
        queue.push_back(val);
        int tail = count>size ? queue.front():0;
        if(count>size) queue.pop_front();

        windowSum = windowSum - tail + val;
        return static_cast<double>(windowSum)/min(size,count);
    }




// private:
//     int size;
//     vector<int> queue;

// public:
//     MovingAverage(int size) {
//         this->size=size;
//     }
    
//     double next(int val) {
//         queue.push_back(val);
//         int windowSum = 0;
//         for(int i  = max(0,(int)queue.size()-size);i< queue.size();i++)
//             windowSum += queue[i];

//         return windowSum * 1.0/ min((int)queue.size(),size);
    // }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */