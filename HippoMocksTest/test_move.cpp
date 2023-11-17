#include "hippomocks.h"
#include "gtest/gtest.h"
#include <string>

class INext {
public:
        virtual void doSomeThing(std::string&& arg) = 0;
        virtual int doSomeThingEasy(double i) = 0;
};

TEST (TestMove, checkMoveAssignment)
{
    std::string test1("abcd");

    MockRepository mocks;
    INext *nextMock = mocks.Mock<INext>();
    mocks.ExpectCall(nextMock, INext::doSomeThing).With(test1);
    mocks.ExpectCall(nextMock, INext::doSomeThingEasy).With(0.4).Return(2);
    std::string value("abcd");
    nextMock->doSomeThing(std::move(value));
    nextMock->doSomeThingEasy(0.4);
}
