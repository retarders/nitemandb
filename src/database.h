#include <string>
#include <map>

using namespace std;

class Database {

    private:
        string path;

    public:
        string name;

        Database(string dbname, string dbpath) {
            path = dbpath;
            name = dbname
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
