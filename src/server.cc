#include <iostream>

using namespace std;

class Server {

    private:
        NitemanConfig* config;

    public:
        Server(NitemanConfig* cfg) {
            config = cfg;
        }

};
