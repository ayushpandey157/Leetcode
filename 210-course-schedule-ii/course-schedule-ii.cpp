class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> courses;
        // if n is smaller than or equal to zero we will return the empty array
        if (n <= 0)
            return {};

        // a. Initialize the graph
        unordered_map<int, int>
            inDegree; // count of incoming prerequisites for every course
        unordered_map<int, vector<int>> graph; // adjacency list graph
        for (int i = 0; i < n; i++) {
            inDegree[i] = 0;
            graph[i] = {};
        }

        // b. Build the graph
        for (int i = 0; i < prerequisites.size(); i++) {
            int parent = prerequisites[i][1], child = prerequisites[i][0];
            graph[parent].push_back(
                child); // put the child into it's parent's list
            inDegree[child] = inDegree[child] + 1; // increment child's inDegree
        }

        // c. Find all sources i.e., all n with 0 in-degrees
        queue<int> sources;
        for (auto itr = inDegree.begin(); itr != inDegree.end(); itr++) {
            // itr works as a pointer to pair<int, int>
            // type itr->first stores the key part  and
            // itr->second stroes the value part
            if (itr->second == 0) {
                sources.push(itr->first);
            }
        }

        // d. For each source, add it to the courses and subtract one from all
        // of its children's in-degrees if a child's in-degree becomes zero, add
        // it to the sources queue
        while (!sources.empty()) {
            // pop an element from the start of the sources and store
            // the element in vertex
            int vertex = sources.front();
            sources.pop();
            // append the vertex at the end of the sorted_order
            courses.push_back(vertex);
            vector<int> children = graph[vertex]; // get the node's children to
                                                  // decrement their in-degrees
            // traverse in graph[vertex] using child
            //  get the node's children to decrement
            //  their in-degrees
            for (int child : children) {
                inDegree[child] = inDegree[child] - 1;
                if (inDegree[child] == 0) {
                    // if in_degree[child] is 0 append the child in the deque
                    // sources
                    sources.push(child);
                }
            }
        }

        if (courses.size() != n) {
            // topological sort is not possible as the graph has a cycle
            courses.clear();
        }
        return courses;
    }
};