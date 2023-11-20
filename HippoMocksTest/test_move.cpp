#include "hippomocks.h"
#include "gtest/gtest.h"
#include <string>

class INext {
public:
        virtual void doSomeThing(std::string&& arg) = 0;
};

TEST (TestMove, checkMoveAccepted)
{
    std::string test1("abcd");

    MockRepository mocks;
    INext *nextMock = mocks.Mock<INext>();
    mocks.ExpectCall(nextMock, INext::doSomeThing).With(test1);
    nextMock->doSomeThing("abcd");
}

TEST (TestMove, checkMoveChecked)
{
    std::string test1("abcd");

    MockRepository mocks;
    INext *nextMock = mocks.Mock<INext>();
    mocks.ExpectCall(nextMock, INext::doSomeThing).With(test1);
	EXPECT_THROW(nextMock->doSomeThing("abcd"), HippoMocks::ExpectationException);
}
