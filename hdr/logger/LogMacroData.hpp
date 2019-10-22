#ifndef __LOG_MACRO_DATA__
#define __LOG_MACRO_DATA__

#include <LogLevel.hpp>

struct LogMacroData {
    constexpr LogMacroData(const char* fmt, const char* f, const char* fnc, int32_t l, LogLevel lvl) :
        fmt_str(fmt), file(f), function(fnc), line(l), level(lvl)
    {}
    const char* fmt_str{};
    const char* file{};
    const char* function{};
    int32_t line{};
    LogLevel level{};
};

#endif // __LOG_MACRO_DATA__