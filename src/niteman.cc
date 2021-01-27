#include "CLI/App.hpp"
#include "CLI/Formatter.hpp"
#include "CLI/Config.hpp"
#include "config.h"
#include <string>

using namespace CLI;
using namespace std;

NitemanConfig config;

int main(int argc, char** argv) {
    App app{"Starts the NitemanDB database"};

    string config_path = "niteman.toml";
    app.add_option("-c,--config", config_path, "Path to the config file");

    CLI11_PARSE(app, argc, argv);

    config = loadConfig(config_path);

    return 0;
}
