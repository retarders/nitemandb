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
            file.close();
        }

        void load() {
            /* open file */
            ifstream file;
            file.open(path);

            if(!file.is_open()) return;

            /* read file */
            std::stringstream buffer;

            string line;

            while(getline(file, line)) {
                buffer << line;
            }

            /* unpack */
            auto const& str = buffer.str();
            auto unpacked = msgpack::unpack(str.data(), str.size(), 0);
            auto obj = unpacked.get();

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
