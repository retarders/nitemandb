#include "CLI/App.hpp"
#include "CLI/Formatter.hpp"
#include "CLI/Config.hpp"
#include "config.h"
#include "database.h"
#include <string>
#include <sys/stat.h>

using namespace CLI;
using namespace std;

NitemanConfig config;
Database* database;

int main(int argc, char** argv) {
    App app{"Starts the NitemanDB database"};

    string config_path = "niteman.toml";
    app.add_option("-c,--config", config_path, "Path to the config file");

    string data_path = "/var/lib/niteman/";
    app.add_option("-d,--data", data_path, "Path to the data directory");

    CLI11_PARSE(app, argc, argv);

    config = loadConfig(config_path);

    if(mkdir(data_path.c_str(), 0777) == -1) {
        perror("error");
        return 1;
    }

    database = new Database(data_path);

    return 0;
}
