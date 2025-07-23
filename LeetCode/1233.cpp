#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> folderSet(folder.begin(), folder.end());
        vector<string> result;

        for (const string& f : folder) {
            bool isSubFolder = false;
            string prefix = f;

            // Check all prefixes of the current folder path
            while (!prefix.empty()) {
                size_t pos = prefix.rfind('/');
                if (pos == string::npos)
                    break;

                // Reduce the prefix to its parent folder
                prefix = prefix.substr(0, pos);

                // If the parent folder exists in the set, mark as sub-folder
                if (folderSet.count(prefix)) {
                    isSubFolder = true;
                    break;
                }
            }

            if (!isSubFolder) {
                result.push_back(f);
            }
        }

        return result;
    }
};
