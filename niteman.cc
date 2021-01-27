#include "CLI/App.hpp"
#include "CLI/Formatter.hpp"
#include "CLI/Config.hpp"

using namespace CLI;

int main(int argc, char** argv) {
    App app{"Starts the NitemanDB database"};

    CLI11_PARSE(app, argc, argv);
    return 0;
}
