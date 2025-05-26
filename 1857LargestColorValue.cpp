class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        // Build graph and indegree array
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        // count[i][c] = max count of color 'c' (0-25) on a path ending at node i
        vector<vector<int>> count(n, vector<int>(26, 0));

        queue<int> q;

        // Push nodes with indegree 0
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int visited = 0;
        int maxColorValue = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visited++;

            int colorIndex = colors[node] - 'a';
            count[node][colorIndex]++;

            maxColorValue = max(maxColorValue, count[node][colorIndex]);

            for (int neighbor : graph[node]) {
                for (int c = 0; c < 26; ++c) {
                    count[neighbor][c] = max(count[neighbor][c], count[node][c]);
                }

                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        // If all nodes were not visited, there is a cycle
        return visited == n ? maxColorValue : -1;
    }
};
