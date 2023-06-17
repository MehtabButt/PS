#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {
    priority_queue<int> *lt_nums;
    priority_queue<int, vector<int>, greater<int>> *gt_nums;

    int getAbs(int n) {
        return n < 0 ? -n : n;
    }
public:
    MedianFinder() {
        lt_nums = new priority_queue<int>();
        gt_nums = new priority_queue<int, vector<int>, greater<int>>();
    }

    void addNum(int num) {
        lt_nums->push(num);
        if(getAbs(lt_nums->size() - gt_nums->size()) > 1) {
            gt_nums->push(lt_nums->top());
            lt_nums->pop();
        }
        if(!lt_nums->empty() && !gt_nums->empty() && lt_nums->top() > gt_nums->top()) {
            lt_nums->push(gt_nums->top());
            gt_nums->pop();
            gt_nums->push(lt_nums->top());
            lt_nums->pop();
        }
    }

    double findMedian() {
        if(lt_nums->size() > gt_nums->size()) {
            return lt_nums->top();
        }
        else if(lt_nums->size() < gt_nums->size()) {
            return gt_nums->top();
        }
        else {
            return (lt_nums->top()+gt_nums->top())/2.0;
        }
    }
};

int main() {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout <<mf.findMedian() <<endl;
    mf.addNum(1);
    cout <<mf.findMedian() <<endl;

    return 0;
}
