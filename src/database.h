#include <string>
#include <map>
#include <msgpack.hpp>

using namespace std;

class Database {

    private:
        string path;
        map<string, string> data;

    public:
        string name;

        Database(string dbname, string dbpath) {
            path = dbpath;
            name = dbname;
        }

        void save() {

        }

        void load() {

        }

        void put(string key, string value) {
            data.insert(pair<string, string>(key, value));
        }

        string get(string key) {
            return data[key];
        }

        map<string, string> all() {
            return data;
        }

};
