class MovingAverage {

private:
    int size;
    vector<int> queue;

public:
    MovingAverage(int size) {
        this->size=size;
    }
    
    double next(int val) {
        queue.push_back(val);
        int windowSum = 0;
        for(int i  = max(0,(int)queue.size()-size);i< queue.size();i++)
            windowSum += queue[i];

        return windowSum * 1.0/ min((int)queue.size(),size);
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */