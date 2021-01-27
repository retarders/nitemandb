#include <string>

using namespace std;

namespace config {

    class Config {

        public:
            /* service section */
            string host;
            int port;

            /* authentication section */
            bool authentication;
            string password;

    };

}
