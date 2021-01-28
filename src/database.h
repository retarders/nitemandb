#include <string>
#include <map>

using namespace std;

class Database {

    private:
        string path;

    public:

        Database(string path_a) {
            path = path_a;
        }

        int save() {
            return 0;
        }

        int load() {
            return 0;
        }

        void put(string key, string value);

        string get(string key);

        map<string, string> all();

};
