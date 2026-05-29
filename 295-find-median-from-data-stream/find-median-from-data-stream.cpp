class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> minh;
    priority_queue<int> maxh;
    MedianFinder() {}
    
    void addNum(int num) {
        if(maxh.empty() || maxh.top() > num)
            maxh.push(num);
        else
            minh.push(num);

        if(maxh.size() > minh.size() + 1){
            minh.push(maxh.top());
            maxh.pop();
        }
        else if(minh.size() > maxh.size() +1){
            maxh.push(minh.top());
            minh.pop();
        }
    }
    
    double findMedian() {
        if(maxh.size() == minh.size()){
            if(maxh.empty()){
                return 0.0;
            }
            else{
                return ((double)maxh.top() + (double)minh.top())/2;
            }
        }
        else
            return maxh.size() > minh.size() ? maxh.top() : minh.top();
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */