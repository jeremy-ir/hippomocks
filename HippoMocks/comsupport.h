#pragma once
#if 0
#ifdef _MSC_VER
#include <hippomocks.h>
#include <winerror.h>

template <typename T>
void AddComExpectations(HM_NS MockRepository& mocks, T* m)
{
	mocks.OnCall(m, T::AddRef)
		.Return(1);
	mocks.OnCall(m, T::Release)
		.Return(1);
	mocks.OnCall(m, T::QueryInterface)
		.With(__uuidof(T), Out((void**)m))
		.Return(S_OK);

	mocks.OnCall(m, T::QueryInterface)
		.With(__uuidof(IUnknown), Out((void**)m))
		.Return(S_OK);

}

template <typename T1, typename T2>
void ConnectComInterfaces(HM_NS MockRepository& mocks, T1* m1, T2* m2)
{
	//from T1 to T2
	mocks.OnCall(m1, T1::QueryInterface)
		.With(__uuidof(T2), Out((void**)m2))
		.Return(S_OK);
	//from T2 to T1
	mocks.OnCall(m2, T2::QueryInterface)
		.With(__uuidof(T1), Out((void**)m1))
		.Return(S_OK);

	AddComExpectations(mocks, m1);
	AddComExpectations(mocks, m2);

	//no support for interface hierarchies
	//no Base IUnknown -> do it yourself if you really need that special case
}
#endif
#endif