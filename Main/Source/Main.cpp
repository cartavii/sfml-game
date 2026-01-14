#include "Application.hpp"

int main() {
    try {
        Application app;
        return app.run();
    } catch (const std::exception& e) {
        return -1;
    }
}