#include <string>
#include <map>
#include <msgpack.hpp>
#include <sstream>
#include <fstream>
#include <iostream>

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
            /* create the buffer */
            std::stringstream buffer;

            /* pack all the data to the buffer */
            msgpack::pack(buffer, data);

            /* save the buffer to the file */
            ofstream file;
            file.open(path);

            // file << buffer.rdbuf();
            auto const& str = buffer.str();
            file << str;
            cout << str << endl;

            file.close();
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
