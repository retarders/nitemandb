#include <string>
#include <toml.hpp>

using namespace std;
using namespace toml;

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
    auto data = parse(path);

    auto service = find(data, "service");

    auto string host = find<string>(service, "host");
    auto int port = find<int>(service, "port");

    NitemanConfig config;

    config.host = host;
    config.port = port;

    return config;
}
