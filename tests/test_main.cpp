#include <gtest/gtest.h>
#include "ParameterParser.h"

int main(int argc, char** argv)
{
    frs::ParameterParser parser;

    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}