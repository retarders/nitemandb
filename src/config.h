#include <string>
#include "toml.hpp"

using namespace std;

class NitemanConfig {

    public:
        /* service section */
        string host;
        int port;

        /* authentication section */
        bool auth_enabled;
        string password;

};

static NitemanConfig loadConfig(string path) {
    NitemanConfig config;

    auto data = toml::parse(path);

    auto service = toml::find(data, "service");
    auto authentication = toml::find(data, "authentication");

    string host = toml::find<string>(service, "host");
    int port = toml::find<int>(service, "port");

    config.host = host;
    config.port = port;

    bool auth_enabled = toml::find<bool>(authentication, "enabled");
    config.auth_enabled = auth_enabled;

    if(auth_enabled) {
        string password = toml::find<string>(authentication, "password");

        config.password = password;
    }

    return config;
}
