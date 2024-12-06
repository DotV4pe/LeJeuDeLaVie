#include <gtest/gtest.h>

#include "./Menu/Menu.hpp"

using namespace std;

int main(int argc, char **argv) {
    Menu m;
    m.lancer();
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}