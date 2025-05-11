class MyStack {
private:
    queue<int> q1, q2;

public:
    MyStack() {}

    void push(int x) {
        q2.push(x);

        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }

    int pop() {
        if (!q1.empty()) {
            int top_element = q1.front();
            q1.pop();
            return top_element;
        }
        return -1;
    }

    int top() {
        if (!q1.empty()) {
            return q1.front();
        }
        return -1;
    }

    bool empty() {
        return q1.empty();
    }
};