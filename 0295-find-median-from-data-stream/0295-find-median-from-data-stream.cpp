class MedianFinder {
private:
    vector<float> arr;
public:
    MedianFinder() {
        
    }
    
    void addNum(float num) {
        // Insert the number into the sorted array
        int i = 0;
        while (i < arr.size() && num > arr[i]) {
            i++;
        }
        arr.insert(arr.begin() + i, num);
    }
    
    double findMedian() {
        int n = arr.size();
        if (n % 2 == 0) {
            return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
        } else {
            return arr[n / 2];
        }        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */