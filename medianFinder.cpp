#include "common.h"
//not checked yet


class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        auto minheapcmp = []( int x,  int y){return x > y;};
        if(upper.size() == 0)
            upper.push_back(num);
        else{
            if(num >= *upper.begin()) {
                upper.push_back(num);
                push_heap(upper.begin(), upper.end(), minheapcmp);
                if(upper.size() > lower.size()){
                    lower.push_back(*upper.begin());
                    push_heap(lower.begin(), lower.end());
                    pop_heap(upper.begin(), upper.end(), minheapcmp);
                    upper.pop_back();
                }
            }
            else {
                lower.push_back(num);
                push_heap(lower.begin(), lower.end());
                if (lower.size() > upper.size()) {
                    upper.push_back(*lower.begin());
                    push_heap(upper.begin(), upper.end(), minheapcmp);
                    pop_heap(lower.begin(), lower.end());
                    lower.pop_back();
                }
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if(upper.size() == lower.size()){
            if(upper.size() == 0){
                throw logic_error("uninitialized data");
            }
            return  (*lower.begin() + *upper.begin()) /2.0;
        }
        else {
            if(upper.size() < lower.size())
                return *lower.begin();
            else {
                return *upper.begin();
            }
        }
    }

    vector<int> upper; // min heap
    vector<int> lower; // max heap
};



int main() {

    MedianFinder m;
    m.addNum(2); m.addNum(3);
    cout << m.findMedian() << endl;
    //m.addNum(3);
    //cout << m.findMedian() << endl;

    return 1;
}