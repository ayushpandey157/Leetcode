// Assuming the NestedInteger class is defined like this:
// class NestedInteger {
// public:
//     NestedInteger() {};                     // Initializes an empty list
//     NestedInteger(int value) {};            // Initializes a single integer
//     bool isInteger() const;                 // Returns true if this NestedInteger holds a single integer
//     int getInteger() const;                 // Returns the single integer that this NestedInteger holds
//     void setInteger(int value);             // Set this NestedInteger to hold a single integer
//     void add(const NestedInteger &ni);      // Adds a NestedInteger element to this NestedInteger
//     const std::vector<NestedInteger> &getList() const; // Returns the nested list
// };

class Solution {
public:
    NestedInteger deserialize(const std::string &s) {
        std::istringstream iss(s);
        return parse(iss);
    }

private:
    NestedInteger parse(std::istringstream &iss) {
        if (iss.peek() == '[') {
            iss.get(); // Skip '['
            NestedInteger ni;
            while (iss.peek() != ']') {
                ni.add(parse(iss));
                if (iss.peek() == ',') {
                    iss.get(); // Skip ','
                }
            }
            iss.get(); // Skip ']'
            return ni;
        } else {
            int num;
            iss >> num;
            return NestedInteger(num);
        }
    }
};