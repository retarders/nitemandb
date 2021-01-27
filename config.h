#include <string>

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
