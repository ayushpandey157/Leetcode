class MyCircularDeque {
    vector<int> d; int f, r, sz, cap;
public:
    MyCircularDeque(int k) : d(k), f(0), r(0), sz(0), cap(k) {}
    inline bool insertFront(int v) { if (isFull()) return false; f = (f - 1 + cap) % cap; d[f] = v; sz++; return true; }
    inline bool insertLast(int v) { if (isFull()) return false; d[r] = v; r = (r + 1) % cap; sz++; return true; }
    inline bool deleteFront() { if (isEmpty()) return false; f = (f + 1) % cap; sz--; return true; }
    inline bool deleteLast() { if (isEmpty()) return false; r = (r - 1 + cap) % cap; sz--; return true; }
    inline int getFront() { return isEmpty() ? -1 : d[f]; }
    inline int getRear() { return isEmpty() ? -1 : d[(r - 1 + cap) % cap]; }
    inline bool isEmpty() { return !sz; }
    inline bool isFull() { return sz == cap; }
};