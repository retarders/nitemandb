#include <string>
#include <map>
#include "proto/data.pb.h"

using namespace std;

class Database {

    private:
        string path;

    public:

        data::Database db;

        Database(string path_a) {
            path = path_a;
            db.set_name("default");
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
