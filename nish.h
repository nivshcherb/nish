/* -------------------------------------------------------------------------- *
 *  Macros
 * -------------------------------------------------------------------------- */
#include "nish_headers/macro.h"

/**
 *  Concatenate 2 values
 */
#define CONCAT2(x, y)   _CONCAT2(x, y)

/**
 *  Give value as string literal
 */
#define LITERAL(x)  _LITERAL(x)

/**
 *  Expand value (for macros)
 */
#define _(x)        _EXPAND(x)
#define EXPAND(x)   _EXPAND(x)

/**
 *  Wrap value in loop to avoid unwanted behavior
*/
#define DO(x)   _DO(x)

/**
 *  Unpack arguments given in the form (arg1, arg2, ...)
 *  Use as such: UNPACK args
 */
#define UNPACK(...) _UNPACK(__VA_ARGS__)

/**
 *  Evaluate 'call' with the given arguments
 */
#define EVAL(call, ...) _EVAL(call, __VA_ARGS__)

/**
 *  Give the number of arguments
 */
#define ARGN(...)   _ARGN(__VA_ARGS__, _ARGN_SEQ())

/**
 *  Evaluate 'call' on all arguments
 *  Use as suck: FOREACH(call, (arg1, ...), ...)
 */
#define FOREACH(call, ...)  _FOREACH(call, __VA_ARGS__)

/* -------------------------------------------------------------------------- *
 *  ANSI Escape Code
 * -------------------------------------------------------------------------- */
#include "nish_headers/ansi.h"

#define _ESC()      \033
#define _BEL()      \007
#define _CSI()      _ESC()_([)
#define _OSC()      _ESC()_(])
#define _SGR()      m

#define ANSI_BLACK   0
#define ANSI_RED     1
#define ANSI_GREEN   2  
#define ANSI_YELLOW  3
#define ANSI_BLUE    4
#define ANSI_MAGENTA 5
#define ANSI_CYAN    6
#define ANSI_WHITE   7

#define ANSI_RESET          LITERAL(_CSI()_(0)_SGR())
#define ANSI_BOLD           LITERAL(_CSI()_(1)_SGR())
#define ANSI_CURSOR_ON      LITERAL(_CSI()_(?25h))
#define ANSI_CURSOR_OFF     LITERAL(_CSI()_(?25l))
#define ANSI_CLEAR          LITERAL(_ESC()_(c))
#define ANSI_NEWLINE        LITERAL(_CSI()_(1E))

#define ANSI_FG(color)      LITERAL(_CSI()_(3)_(color)_SGR())
#define ANSI_BG(color)      LITERAL(_CSI()_(4)_(color)_SGR())
#define ANSI_TITLE(name)     LITERAL(_OSC()_(0;))_(name)LITERAL(_BEL())


/**
 * Allow the use of vaiables in ANSI code fuctions 
 * The return value is not ment to be stored, as it is changes every call
 */

inline const char *ANSI_RESIZE(unsigned short width_, unsigned short height_)
{
    static const char *pattern = LITERAL(_CSI()) "8;%d;%dt";
    static char buffer[32] = { 0 };

    sprintf(buffer, pattern, width_, height_);

    return buffer;
}

inline const char *ANSI_CURSOR(unsigned short width_, unsigned short height_)
{
    static const char *pattern = LITERAL(_CSI()) "%d;%dH";
    static char buffer[32] = { 0 };

    sprintf(buffer, pattern, width_, height_);

    return buffer;
}

inline const char *ANSI_FG_RGB(unsigned char red_, unsigned char green_, unsigned char blue_)
{
    static const char *pattern = LITERAL(_CSI()) "38;2;%d;%d;%dm";
    static char buffer[32] = { 0 };

    sprintf(buffer, pattern, red_, green_, blue_);

    return buffer;
}

inline const char *ANSI_BG_RGB(unsigned char red_, unsigned char green_, unsigned char blue_)
{
    static const char *pattern = LITERAL(_CSI()) "48;2;%d;%d;%dm";
    static char buffer[32] = { 0 };

    sprintf(buffer, pattern, red_, green_, blue_);

    return buffer;
}

/* -------------------------------------------------------------------------- *
 *  Math
 * -------------------------------------------------------------------------- */
#include <math.h>

inline float DegreesToRadians(float d_)
{
    return d_ * M_PI / 180;
}

inline float RadiansToDegrees(float r_)
{
    return r_ * 180 / M_PI;
}

/* -------------------------------------------------------------------------- *
 *  C++ Useful Macros
 * -------------------------------------------------------------------------- */
#ifdef __cplusplus

#define cpp98   199711L
#define cpp11   201103L
#define cpp14   201402L
#define cpp17   201703L
#define cpp20   202002L

#if __cplusplus >= cpp11
    #define uncopyable(class) \
        class (const class &) = delete; \
        class & operator=(const class &) = delete
#else
    #define uncopyable(class) \
        private: \
            class (const class &); \
            class & operator=(const class &)
#endif

#if __cplusplus >= cpp11
    #define cpp11only(x)    x
#else
    #define cpp11only(x)
#endif

#define interface(class) \
    public: \
        explicit class() = default; \
        virtual ~class() = 0

#define interface_requirements(class) \ 
    inline class::~class() {}

#define defaultcopy(class) \
    public: \
        class(const class &) = default; \
        class & operator=(const class &) = default; \
        cpp11only( \
            class(class &&) = default; \
            class & operator=(class &&) = default \
        );

#endif /* __cplusplus --------------------------------------------------- */
