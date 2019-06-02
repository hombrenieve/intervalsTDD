#include "IntervalBuilder.h"
#include "EndPointBuilder.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

class ConflictingEndPointsIntervalTest: public ::testing::TestWithParam<std::tuple<bool, bool, bool, bool>> {
protected:
    IntervalBuilder intervalBuilder;
    EndPointBuilder endPointBuilder;
};

class ConflictingEndPointsLeftClosedIntervalTest: public ConflictingEndPointsIntervalTest { };

class ConflictingEndPointsLeftOpenIntervalTest: public ConflictingEndPointsIntervalTest { };

class ConflictingEndPointsRightClosedIntervalTest: public ConflictingEndPointsIntervalTest { };

class ConflictingEndPointsRightOpenIntervalTest: public ConflictingEndPointsIntervalTest { };

TEST_P(ConflictingEndPointsLeftClosedIntervalTest, isIntersectedNotOverlappingByLeftSamePoint) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).included(std::get<0>(this->GetParam())).buildFrom())
        .until(endPointBuilder.point(14).included(std::get<1>(this->GetParam())).buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(0).included(std::get<2>(this->GetParam())).buildFrom())
        .until(endPointBuilder.point(3).included(std::get<3>(this->GetParam())).buildUntil()).build());
    EXPECT_TRUE(one.isIntersected(another));
}

INSTANTIATE_TEST_SUITE_P(ExpectTrue,
                        ConflictingEndPointsLeftClosedIntervalTest,
                        Combine(Values(true), Bool(), Bool(), Values(true)));

TEST_P(ConflictingEndPointsLeftOpenIntervalTest, isIntersectedNotOverlappingByLeftSamePoint) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).included(std::get<0>(this->GetParam())).buildFrom())
        .until(endPointBuilder.point(14).included(std::get<1>(this->GetParam())).buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(0).included(std::get<2>(this->GetParam())).buildFrom())
        .until(endPointBuilder.point(3).included(std::get<3>(this->GetParam())).buildUntil()).build());
    EXPECT_FALSE(one.isIntersected(another));
}

INSTANTIATE_TEST_SUITE_P(ExpectFalse,
                        ConflictingEndPointsLeftOpenIntervalTest,
                        Combine(Values(true), Bool(), Bool(), Values(false)));

INSTANTIATE_TEST_SUITE_P(ExpectFalse2,
                        ConflictingEndPointsLeftOpenIntervalTest,
                        Combine(Values(false), Bool(), Bool(), Values(true)));

INSTANTIATE_TEST_SUITE_P(ExpectFalse3,
                        ConflictingEndPointsLeftOpenIntervalTest,
                        Combine(Values(false), Bool(), Bool(), Values(false)));


TEST_P(ConflictingEndPointsRightClosedIntervalTest, isIntersectedNotOverlappingByRightSamePoint) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).included(std::get<0>(this->GetParam())).buildFrom())
        .until(endPointBuilder.point(14).included(std::get<1>(this->GetParam())).buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(14).included(std::get<2>(this->GetParam())).buildFrom())
        .until(endPointBuilder.point(19).included(std::get<3>(this->GetParam())).buildUntil()).build());
    EXPECT_TRUE(one.isIntersected(another));
}

INSTANTIATE_TEST_SUITE_P(ExpectTrue,
                        ConflictingEndPointsRightClosedIntervalTest,
                        Combine(Bool(), Values(true), Values(true), Bool()));

TEST_P(ConflictingEndPointsRightOpenIntervalTest, isIntersectedNotOverlappingByRightSamePoint) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).included(std::get<0>(this->GetParam())).buildFrom())
        .until(endPointBuilder.point(14).included(std::get<1>(this->GetParam())).buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(14).included(std::get<2>(this->GetParam())).buildFrom())
        .until(endPointBuilder.point(19).included(std::get<3>(this->GetParam())).buildUntil()).build());
    EXPECT_FALSE(one.isIntersected(another));
}

INSTANTIATE_TEST_SUITE_P(ExpectFalse,
                        ConflictingEndPointsRightOpenIntervalTest,
                        Combine(Bool(), Values(true), Values(false), Bool()));

INSTANTIATE_TEST_SUITE_P(ExpectFalse2,
                        ConflictingEndPointsRightOpenIntervalTest,
                        Combine(Bool(), Values(false), Values(true), Bool()));

INSTANTIATE_TEST_SUITE_P(ExpectFalse3,
                        ConflictingEndPointsRightOpenIntervalTest,
                        Combine(Bool(), Values(false), Values(false), Bool()));