/**
 *  This file is used to define the behavior of the defined macros in utility.h
 *  The main function forward their arguments to allow expansion of said args
 *  It also contains heling macros
 */

#define _CONCAT2(x, y)      x ## y
#define _LITERAL(x)         #x
#define _EXPAND(x)          x
#define _DO(x)              do { x; } while(0)
#define _UNPACK(...)        __VA_ARGS__
#define _EVAL(call, ...)   call(__VA_ARGS__)

#define _ARGN_LITERAL( \
    _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, \
    _11, _12, _13, _14, _15, N, ... ) N

#define _ARGN_SEQ() \
    15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0

#define _ARGN(...) _ARGN_LITERAL(__VA_ARGS__)

#define _FOREACH1(call, args) \
    EVAL(call, UNPACK args)

#define _FOREACH2(call, args, ...) \
    _FOREACH1(call, args); \
    _FOREACH1(call, __VA_ARGS__)

#define _FOREACH3(call, args, ...) \
    _FOREACH1(call, args); \
    _FOREACH2(call, __VA_ARGS__)

#define _FOREACH4(call, args, ...) \
    _FOREACH1(call, args); \
    _FOREACH3(call, __VA_ARGS__)

#define _FOREACH5(call, args, ...) \
    _FOREACH1(call, args); \
    _FOREACH4(call, __VA_ARGS__)

#define _FOREACH6(call, args, ...) \
    _FOREACH1(call, args); \
    _FOREACH5(call, __VA_ARGS__)

#define _FOREACH7(call, args, ...) \
    _FOREACH1(call, args); \
    _FOREACH6(call, __VA_ARGS__)

#define _FOREACH8(call, args, ...) \
    _FOREACH1(call, args); \
    _FOREACH7(call, __VA_ARGS__)

#define _FOREACH9(call, args, ...) \
    _FOREACH1(call, args); \
    _FOREACH8(call, __VA_ARGS__)

#define _FOREACH10(call, args, ...) \
    _FOREACH1(call, args); \
    _FOREACH9(call, __VA_ARGS__)

#define _FOREACH11(call, args, ...) \
    _FOREACH1(call, args); \
    _FOREACH10(call, __VA_ARGS__)

#define _FOREACH12(call, args, ...) \
    _FOREACH1(call, args); \
    _FOREACH11(call, __VA_ARGS__)

#define _FOREACH13(call, args, ...) \
    _FOREACH1(call, args); \
    _FOREACH12(call, __VA_ARGS__)

#define _FOREACH14(call, args, ...) \
    _FOREACH1(call, args); \
    _FOREACH13(call, __VA_ARGS__)

#define _FOREACH15(call, args, ...) \
    _FOREACH1(call, args); \
    _FOREACH14(call, __VA_ARGS__)

#define _FOREACH16(call, args, ...) \
    _FOREACH1(call, args); \
    _FOREACH15(call, __VA_ARGS__)

#define _FOREACH(call, ...) CONCAT2(_FOREACH, ARGN(__VA_ARGS__)) (call, __VA_ARGS__)