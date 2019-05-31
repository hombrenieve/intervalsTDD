#include "IntervalBuilder.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

class OpenIntervalTest : public Test {
protected:
    Interval* one;
    Interval* another;

    OpenIntervalTest() : 
        one(nullptr),
        another(nullptr)
    { }

    ~OpenIntervalTest() {
        if(this->one)
            delete one;
        if(this->another)
            delete another;
    }
};


TEST_F(OpenIntervalTest, isIntersectedOverlappingLeft) {
    one = IntervalBuilder().min(3).max(14).open().build();
    another = IntervalBuilder().min(1).max(7).open().build();
    EXPECT_TRUE(one->isIntersected(*another));
}

TEST_F(OpenIntervalTest, isIntersectedOverlappingLeftEqualMin) {
    one = IntervalBuilder().min(3).max(14).open().build();
    another = IntervalBuilder().min(3).max(7).open().build();
    EXPECT_TRUE(one->isIntersected(*another));
}

TEST_F(OpenIntervalTest, isIntersectedOverlappingEquals) {
    one = IntervalBuilder().min(3).max(14).open().build();
    another = IntervalBuilder().min(3).max(14).open().build();
    EXPECT_TRUE(one->isIntersected(*another));
}

TEST_F(OpenIntervalTest, isIntersectedOverlappingByRight) {
    one = IntervalBuilder().min(3).max(14).open().build();
    another = IntervalBuilder().min(7).max(17).open().build();
    EXPECT_TRUE(one->isIntersected(*another));
}

TEST_F(OpenIntervalTest, isIntersectedOverlappingByBoth) {
    one = IntervalBuilder().min(3).max(14).open().build();
    another = IntervalBuilder().min(0).max(17).open().build();
    EXPECT_TRUE(one->isIntersected(*another));
}

TEST_F(OpenIntervalTest, isIntersectedOverlappingByInside) {
    one = IntervalBuilder().min(3).max(14).open().build();
    another = IntervalBuilder().min(5).max(10).open().build();
    EXPECT_TRUE(one->isIntersected(*another));
}

TEST_F(OpenIntervalTest, isIntersectedNotOverlappingByLeft) {
    one = IntervalBuilder().min(3).max(14).open().build();
    another = IntervalBuilder().min(0).max(2).open().build();
    EXPECT_FALSE(one->isIntersected(*another));
}