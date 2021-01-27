#include <CLI/App.hpp>
#include <CLI/Formatter.hpp>
#include <CLI/Config.hpp>
#include <string>

using namespace CLI;
using namespace std;

int main(int argc, char** argv) {
    App app{"Starts the NitemanDB database"};

    string config_path = "niteman.toml";
    app.add_option("-c,--config", config_path, "Path to the config file");

    CLI11_PARSE(app, argc, argv);
    return 0;
}
