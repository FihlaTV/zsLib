/*

 Copyright (c) 2014, Robin Raymond
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 2. Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 The views and conclusions contained in the software and documentation are those
 of the authors and should not be interpreted as representing official policies,
 either expressed or implied, of the FreeBSD Project.

 */

#define ZS_DECLARE_TEMPLATE_GENERATE_IMPLEMENTATION

#include <zsLib/Proxy.h>
#include <zsLib/ProxySubscriptions.h>
#include <zsLib/IMessageQueueThread.h>
#include <zsLib/Stringize.h>
#include <iostream>


#include "testing.h"
#include "main.h"

using zsLib::ULONG;
using zsLib::IMessageQueue;

#   define _ZS_INTERNAL_ARGS_AUGMENTER(unused, ...) __VA_ARGS__

#define _ZS_INTERNAL_GET_ARG_COUNT_PRIVATE(_0, _1_, _2_, _3_, _4_, _5_, _6_, _7_, _8_, _9_, _10_, _11_, _12_, _13_, _14_, _15_, _16_, _17_, _18_, _19_, _20_, _21_, _22_, _23_, _24_, _25_, _26_, _27_, _28_, _29_, _30_, _31_, _32_, _33_, _34_, _35_, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, count, ...) count
#define _ZS_INTERNAL_MACRO_GET_ARG_ACOUNT(...) _ZS_INTERNAL_GET_ARG_COUNT_PRIVATE        (0, ## __VA_ARGS__, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#define _ZS_INTERNAL_MACRO_GET_ARG_ACOUNT_MINUS_2(...) _ZS_INTERNAL_GET_ARG_COUNT_PRIVATE(0, ## __VA_ARGS__, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#define _ZS_INTERNAL_MACRO_GET_ARG_ACOUNT_MINUS_3(...) _ZS_INTERNAL_GET_ARG_COUNT_PRIVATE(0, ## __VA_ARGS__, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#define _ZS_INTERNAL_MACRO_GET_ARG_ACOUNT_MINUS_4(...) _ZS_INTERNAL_GET_ARG_COUNT_PRIVATE(0, ## __VA_ARGS__, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#define _ZS_INTERNAL_EXPAND(x) x

#define _ZS_MACRO_SELECT_WITH_PROPERTY_2(NAME, ...) _ZS_INTERNAL_MACRO_VA_SELECT(NAME, _ZS_INTERNAL_MACRO_GET_ARG_ACOUNT_MINUS_2(__VA_ARGS__) )(__VA_ARGS__)
#define _ZS_MACRO_SELECT_WITH_PROPERTY_3(NAME, ...) _ZS_INTERNAL_MACRO_VA_SELECT(NAME, _ZS_INTERNAL_MACRO_GET_ARG_ACOUNT_MINUS_3(__VA_ARGS__) )(__VA_ARGS__)
#define _ZS_MACRO_SELECT_WITH_PROPERTY_4(NAME, ...) _ZS_INTERNAL_MACRO_VA_SELECT(NAME, _ZS_INTERNAL_MACRO_GET_ARG_ACOUNT_MINUS_4(__VA_ARGS__) )(__VA_ARGS__)
#define _ZS_INTERNAL_MACRO_CAT( A, B ) A ## B
#define _ZS_INTERNAL_MACRO_VA_SELECT( NAME, NUM ) _ZS_INTERNAL_MACRO_CAT( NAME ## _, NUM )
#define _ZS_INTERNAL_MACRO_SELECT_WITH_PROPERTY_1(NAME, ...) _ZS_INTERNAL_MACRO_VA_SELECT(NAME, _ZS_INTERNAL_MACRO_GET_ARG_ACOUNT_MINUS_1(__VA_ARGS__))(__VA_ARGS__)
#define _ZS_INTERNAL_MACRO_SELECT_WITH_PROPERTY_2(NAME, ...) _ZS_INTERNAL_MACRO_VA_SELECT(NAME, _ZS_INTERNAL_MACRO_GET_ARG_ACOUNT_MINUS_2(__VA_ARGS__))(__VA_ARGS__)
#define _ZS_INTERNAL_MACRO_SELECT_WITH_PROPERTY_3(NAME, ...) _ZS_INTERNAL_MACRO_VA_SELECT(NAME, _ZS_INTERNAL_MACRO_GET_ARG_ACOUNT_MINUS_3(__VA_ARGS__))(__VA_ARGS__)
#define _ZS_INTERNAL_MACRO_SELECT_WITH_PROPERTY_4(NAME, ...) _ZS_INTERNAL_MACRO_VA_SELECT(NAME, _ZS_INTERNAL_MACRO_GET_ARG_ACOUNT_MINUS_4(__VA_ARGS__))(__VA_ARGS__)

#define _ZS_INTERNAL_PROXY_NO_THROW_DECLARE _ZS_INTERNAL_PROXY_NO_DEFINITION
#define _ZS_INTERNAL_PROXY_NO_DEFINITION
#define _ZS_INTERNAL_PROXY_NO_CONST _ZS_INTERNAL_PROXY_NO_DEFINITION

#define _ZS_INTERNAL_DECLARE_PROXY_SUBSCRIPTIONS_METHOD_0(xConst,xThrow,xMethod)                                                                      \
    void xMethod() xConst xThrow override;                                                                                                     \

#define _ZS_INTERNAL_DECLARE_PROXY_SUBSCRIPTIONS_METHOD_1(xConst,xThrow,xMethod,t1)                                                                      \
    void xMethod(t1 v1) xConst xThrow override;                                                                                                     \

#define _ZS_INTERNAL_DECLARE_PROXY_SUBSCRIPTIONS_METHOD_2(xConst,xThrow,xMethod,t1,t2)                                                                      \
    void xMethod(t1 v1, t2 v2) xConst xThrow override;                                                                                                     \

#define _ZS_INTERNAL_DECLARE_PROXY_SUBSCRIPTIONS_METHOD_3(xConst,xThrow,xMethod,t1,t2,t3)                                                                   \
    void xMethod(t1 v1, t2 v2, t3 v3) xConst xThrow override;                                                                                              \

//#define _ZS_DECLARE_PROXY_SUBSCRIPTIONS_METHOD(xMethod,  ...) _ZS_INTERNAL_MACRO_SELECT_WITH_PROPERTY_3(_ZS_INTERNAL_DECLARE_PROXY_SUBSCRIPTIONS_METHOD, _ZS_INTERNAL_PROXY_NO_CONST, _ZS_INTERNAL_PROXY_NO_THROW_DECLARE, xMethod, __VA_ARGS__)
#define _ZS_DECLARE_PROXY_SUBSCRIPTIONS_METHOD(xMethod,  ...) _ZS_INTERNAL_MACRO_SELECT_WITH_PROPERTY_3(_ZS_INTERNAL_DECLARE_PROXY_SUBSCRIPTIONS_METHOD, _ZS_INTERNAL_PROXY_NO_CONST, _ZS_INTERNAL_PROXY_NO_THROW_DECLARE, xMethod,  ## __VA_ARGS__)

// _ZS_INTERNAL_MACRO_GET_ARG_ACOUNT(1, 2, 3, 4)
_ZS_INTERNAL_MACRO_GET_ARG_ACOUNT(1, 2, 3, 4)
// ZS_INTERNAL_MACRO_GET_ARG_ACOUNT(1, 2, 3, 4)
ZS_INTERNAL_MACRO_GET_ARG_ACOUNT(1, 2, 3, 4)

// _ZS_INTERNAL_MACRO_GET_ARG_ACOUNT_MINUS_3(1, 2, 3, 4)
_ZS_INTERNAL_MACRO_GET_ARG_ACOUNT_MINUS_3(1, 2, 3, 4)
// ZS_INTERNAL_MACRO_GET_ARG_ACOUNT_MINUS_3(1, 2, 3, 4)
ZS_INTERNAL_MACRO_GET_ARG_ACOUNT_MINUS_3(1, 2, 3, 4)

// _ZS_INTERNAL_MACRO_VA_SELECT(Method, _ZS_INTERNAL_MACRO_GET_ARG_ACOUNT_MINUS_3(b, c, d, bobo))(__VA_ARGS__)
_ZS_INTERNAL_MACRO_VA_SELECT(Method, _ZS_INTERNAL_MACRO_GET_ARG_ACOUNT_MINUS_3(b, c, d, bobo))(__VA_ARGS__)
// ZS_INTERNAL_MACRO_VA_SELECT(Method, ZS_INTERNAL_MACRO_GET_ARG_ACOUNT_MINUS_3(b, c, d, bobo))(__VA_ARGS__)
ZS_INTERNAL_MACRO_VA_SELECT(Method, ZS_INTERNAL_MACRO_GET_ARG_ACOUNT_MINUS_3(b, c, d, bobo))(__VA_ARGS__)

// _ZS_INTERNAL_MACRO_VA_SELECT(Method, _ZS_INTERNAL_MACRO_GET_ARG_ACOUNT_MINUS_3(b, c, d, bobo))(b, c, d, bobo)
_ZS_INTERNAL_MACRO_VA_SELECT(Method, _ZS_INTERNAL_MACRO_GET_ARG_ACOUNT_MINUS_3(b, c, d, bobo))(b, c, d, bobo)
// ZS_INTERNAL_MACRO_VA_SELECT(Method, ZS_INTERNAL_MACRO_GET_ARG_ACOUNT_MINUS_3(b, c, d, bobo))(b, c, d, bobo)
ZS_INTERNAL_MACRO_VA_SELECT(Method, ZS_INTERNAL_MACRO_GET_ARG_ACOUNT_MINUS_3(b, c, d, bobo))(b, c, d, bobo)

// _ZS_INTERNAL_ARGS_AUGMENTER(a, b, c, d)
_ZS_INTERNAL_ARGS_AUGMENTER(a, b, c, d)

// _ZS_INTERNAL_ARGS_AUGMENTER(b, c, d)
_ZS_INTERNAL_ARGS_AUGMENTER(b, c, d)

// _ZS_INTERNAL_ARGS_AUGMENTER(c, d)
_ZS_INTERNAL_ARGS_AUGMENTER(c, d)

// _ZS_INTERNAL_ARGS_AUGMENTER(d)
_ZS_INTERNAL_ARGS_AUGMENTER(d)

// _ZS_INTERNAL_MACRO_SELECT_WITH_PROPERTY_3(Method, b, c, d, bobo)
_ZS_INTERNAL_MACRO_SELECT_WITH_PROPERTY_3(Method, b, c, d, bobo)
// ZS_INTERNAL_MACRO_SELECT_WITH_PROPERTY_3(Method, b, c, d, bobo)
ZS_INTERNAL_MACRO_SELECT_WITH_PROPERTY_3(Method, b, c, d, bobo)

// _ZS_INTERNAL_MACRO_SELECT_WITH_PROPERTY_4(Method, b, c, d, bobo)
_ZS_INTERNAL_MACRO_SELECT_WITH_PROPERTY_4(Method, b, c, d, bobo)
// ZS_INTERNAL_MACRO_SELECT_WITH_PROPERTY_4(Method, b, c, d, bobo)
ZS_INTERNAL_MACRO_SELECT_WITH_PROPERTY_4(Method, b, c, d, bobo)

// _ZS_DECLARE_PROXY_SUBSCRIPTIONS_METHOD(bobo)
_ZS_DECLARE_PROXY_SUBSCRIPTIONS_METHOD(bobo)
// ZS_DECLARE_PROXY_SUBSCRIPTIONS_METHOD(bobo)
ZS_DECLARE_PROXY_SUBSCRIPTIONS_METHOD(bobo)

// _ZS_INTERNAL_MACRO_SELECT_WITH_PROPERTY_3(_ZS_INTERNAL_DECLARE_PROXY_SUBSCRIPTIONS_METHOD, Const, Throw, Method)
_ZS_INTERNAL_MACRO_SELECT_WITH_PROPERTY_3(_ZS_INTERNAL_DECLARE_PROXY_SUBSCRIPTIONS_METHOD, Const, Throw, Method)
// ZS_INTERNAL_MACRO_SELECT_WITH_PROPERTY_3(ZS_INTERNAL_DECLARE_PROXY_SUBSCRIPTIONS_METHOD, Const, Throw, Method)
ZS_INTERNAL_MACRO_SELECT_WITH_PROPERTY_3(ZS_INTERNAL_DECLARE_PROXY_SUBSCRIPTIONS_METHOD, Const, Throw, Method)

// _ZS_INTERNAL_MACRO_SELECT_WITH_PROPERTY_3(_ZS_INTERNAL_DECLARE_PROXY_SUBSCRIPTIONS_METHOD, Const, Throw, Method, Arg1)
_ZS_INTERNAL_MACRO_SELECT_WITH_PROPERTY_3(_ZS_INTERNAL_DECLARE_PROXY_SUBSCRIPTIONS_METHOD, Const, Throw, Method, Arg1)
// ZS_INTERNAL_MACRO_SELECT_WITH_PROPERTY_3(ZS_INTERNAL_DECLARE_PROXY_SUBSCRIPTIONS_METHOD, Const, Throw, Method, Arg1)
ZS_INTERNAL_MACRO_SELECT_WITH_PROPERTY_3(ZS_INTERNAL_DECLARE_PROXY_SUBSCRIPTIONS_METHOD, Const, Throw, Method, Arg1)

// _ZS_INTERNAL_MACRO_SELECT_WITH_PROPERTY_3(_ZS_INTERNAL_DECLARE_PROXY_SUBSCRIPTIONS_METHOD, Const, Throw, Method, Arg1, Arg2)
_ZS_INTERNAL_MACRO_SELECT_WITH_PROPERTY_3(_ZS_INTERNAL_DECLARE_PROXY_SUBSCRIPTIONS_METHOD, Const, Throw, Method, Arg1, Arg2)
// ZS_INTERNAL_MACRO_SELECT_WITH_PROPERTY_3(ZS_INTERNAL_DECLARE_PROXY_SUBSCRIPTIONS_METHOD, Const, Throw, Method, Arg1, Arg2)
ZS_INTERNAL_MACRO_SELECT_WITH_PROPERTY_3(ZS_INTERNAL_DECLARE_PROXY_SUBSCRIPTIONS_METHOD, Const, Throw, Method, Arg1, Arg2)

// _ZS_

namespace testing
{
  struct check {
    check()
    {
      mCalledFunc1 = false;
      mCalledFunc2 = 0;
      mCalledSub1 = false;
      mDestroyedTestProxyCallback = false;
    }
    bool mCalledFunc1;
    ULONG mCalledFunc2;
    zsLib::String mCalledFunc3;
    int mCalledFunc4;

    bool mCalledSub1;
    zsLib::String mCalledSub2;

    bool mDestroyedTestProxyCallback;
  };

  static check &getCheck()
  {
    static check gCheck;
    return gCheck;
  }

  ZS_DECLARE_INTERACTION_PTR(Subscription)
  ZS_DECLARE_INTERACTION_PTR(ITestProxyDelegate)

  interaction ITestProxyDelegate
  {
    virtual void func1() {};
    virtual void func2() {};
    virtual void func3(zsLib::String) {};
    virtual void func4(int value) noexcept {};
    virtual zsLib::String func5(ULONG value1, ULONG value2) noexcept { return ""; };
  };

  interaction ITestSubscriptionProxyDelegate
  {
    virtual void sub1() {};
    virtual void sub2(zsLib::String) {};
  };

  interaction Subscription
  {
    virtual void cancel() noexcept {};
  };

  ZS_DECLARE_INTERACTION_PROXY(ITestProxyDelegate)

  ZS_DECLARE_INTERACTION_PROXY(ITestSubscriptionProxyDelegate)
  ZS_DECLARE_INTERACTION_PROXY_SUBSCRIPTION(Subscription, ITestSubscriptionProxyDelegate)

}


	// 15
ZS_DECLARE_PROXY_BEGIN(testing::ITestProxyDelegate)
// 4
ZS_DECLARE_PROXY_METHOD(func1)
// 5
ZS_DECLARE_PROXY_METHOD(func2)
// 6
ZS_DECLARE_PROXY_METHOD(func3, zsLib::String)
// 7
ZS_DECLARE_PROXY_METHOD_SYNC(func4, int)
// 8
ZS_DECLARE_PROXY_METHOD_SYNC_RETURN(func5, zsLib::String, ULONG, ULONG)
// 9
ZS_DECLARE_PROXY_END()

// 11
ZS_DECLARE_PROXY_BEGIN(testing::ITestSubscriptionProxyDelegate)
// 10
ZS_DECLARE_PROXY_METHOD(sub1)
	// 13
ZS_DECLARE_PROXY_END()

	// 14
ZS_DECLARE_PROXY_SUBSCRIPTIONS_BEGIN(testing::ITestSubscriptionProxyDelegate, testing::Subscription)
// 1
_ZS_DECLARE_PROXY_SUBSCRIPTIONS_METHOD(sub1)
// 2
ZS_DECLARE_PROXY_SUBSCRIPTIONS_METHOD(sub2, zsLib::String)
// 3
ZS_DECLARE_PROXY_SUBSCRIPTIONS_END()
