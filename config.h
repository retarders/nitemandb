#include <string>
#include "toml.hpp"

using namespace std;

class NitemanConfig {

    public:
        /* service section */
        string host;
        int port;

        /* authentication section */
        bool authentication;
        string password;

};

static NitemanConfig loadConfig(string path) {
    NitemanConfig config;

    auto data = toml::parse(path);

    auto service = toml::find(data, "service");

    string host = toml::find<string>(service, "host");
    int port = toml::find<int>(service, "port");


    config.host = host;
    config.port = port;

    return config;
}
