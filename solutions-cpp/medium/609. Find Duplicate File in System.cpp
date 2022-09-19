class Solution {
   public:
    string extractFileName(string &file) {
        size_t parIndex = file.find("(");
        return file.substr(0, parIndex);
    }
    string extract_content(string &s) {
        size_t parIndex = s.find("(");
        return s.substr(parIndex, s.size() - parIndex);
    }
    string concatPathFile(string path, string file) {
        return path + "/" + file;
    }
    vector<vector<string>> findDuplicate(vector<string> &paths) {
        // content, paths that contains that content
        map<string, vector<string>> contentMap;
        for (string path : paths) {
            size_t spaceIndex = path.find(" ");
            string currentPath = path.substr(0, spaceIndex);
            stringstream files(path.substr(spaceIndex + 1));
            string file;
            while (getline(files, file, ' ')) {
                string fileContent = extract_content(file);
                string fileName = extractFileName(file);
                string filePath = concatPathFile(currentPath, fileName);
                contentMap[fileContent].push_back(filePath);
            }
        }
        vector<vector<string>> ans;
        for (auto i : contentMap) {
            if (i.second.size() > 1) ans.push_back(i.second);
        }
        return ans;
    }
};
