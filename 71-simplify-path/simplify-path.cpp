class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int n = path.size();
        int i = 0;

        while (i < n) {

            // Skip consecutive slashes
            while (i < n && path[i] == '/') {
                i++;
            }

            // Extract one directory name
            string dir = "";

            while (i < n && path[i] != '/') {
                dir += path[i];
                i++;
            }

            // Ignore empty names and current directory
            if (dir == "" || dir == ".") {
                continue;
            }

            // Move to the parent directory
            else if (dir == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            }

            // Normal directory name
            else {
                st.push(dir);
            }
        }

        // Construct the simplified path
        string ans = "";

        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        // The root directory is represented by "/"
        if (ans == "") {
            return "/";
        }

        return ans;
    }
};