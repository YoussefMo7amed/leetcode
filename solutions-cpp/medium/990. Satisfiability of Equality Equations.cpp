class Solution {
   private:
    bool isSameValue(vector<int> &values, vector<string> &equations) {
        for (int k = 0; k < equations.size(); k++) {
            if (!equals(equations[k][1])) {
                int i = equations[k][0] - 'a';
                int j = equations[k][3] - 'a';
                if (values[i] == values[j]) return false;
            }
        }
        return true;
    }

    void dfs(vector<vector<int>> &graph, int node, int currentValue,
             vector<int> &values) {
        if (values[node] != -1) {
            return;
        }
        values[node] = currentValue;
        for (auto child : graph[node]) {
            dfs(graph, child, currentValue, values);
        }
    }

    void initializeValues(vector<vector<int>> &graph, vector<int> &values) {
        int currentValue = 0;
        for (int node = 0; node < 26; node++) {
            if (values[node] == -1) {
                dfs(graph, node, currentValue, values);
                currentValue++;
            }
        }
    }

    bool equals(char sign) { return sign == '='; }

    void createGraph(vector<vector<int>> &graph, vector<string> &equations) {
        for (string eq : equations) {
            int i = eq[0] - 'a';
            int j = eq[3] - 'a';
            if (equals(eq[1])) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

   public:
    bool equationsPossible(vector<string> &equations) {
        vector<vector<int>> graph(26);
        createGraph(graph, equations);
        vector<int> values(26, -1);
        initializeValues(graph, values);
        return isSameValue(values, equations);
    }
};