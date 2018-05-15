#include "tst_test1.h"
#include "fibonachi_test.h"
#include <gtest/gtest.h>
#include "text/text.h"
#include "text/_text.h"
#include "common.h"

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
