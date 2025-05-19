class PriorityQueue {
    vector<int> q;
private:
    int parent(int idx) { return (idx - 1) / 2; }

    int left(int parent) { return parent * 2 + 1; }

    int right(int parent) { return parent * 2 + 2; }

    void upHeap(int idx) {
        int p = parent(idx);
        if (p >= 0 && q[p] < q[idx]) {
            swap(q[p], q[idx]);
            upHeap(p);
        }
    }

    void maxHeapify(int parent) {
        int l = left(parent), r = right(parent), maxi = parent;
        if (l < q.size() && q[l] > q[parent]) {
            maxi = l;
        }
        if (r < q.size() && q[r] > q[maxi]) {
            maxi = r;
        }
        if (maxi != parent) {
            swap(q[parent], q[maxi]);
            maxHeapify(maxi);
        }
    }

public:
    void push(int& elem) {
        q.push_back(elem);
        upHeap(q.size()-1);
    }

    int pop() {
        if (q.size() > 0) {
            int top = q[0];
            q[0]=q[q.size()-1];
            q.pop_back();
            maxHeapify(0);
            return top;
        }
        return 0;
    }
    int size() { return q.size(); }
};

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });
        int daysPassed = 0;
        PriorityQueue q;
        
        for (auto &course : courses) {
            daysPassed += course[0];
            q.push(course[0]);
            if (daysPassed > course[1]) {
                daysPassed-= q.pop();
            }
        }
        return q.size();
    }
};