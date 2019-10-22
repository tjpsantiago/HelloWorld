#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__

#include <LogLevel.hpp>
#include <LogMacroData.hpp>

template<typename T, typename... Args>
void log(Args... args)
{
    printf(T()().fmt_str, args...);
}

#define LOG_INFO(format, ...)                                                                       \
do {                                                                                                \
    static constexpr const char* anonymous_function{__FUNCTION__};                                  \
    struct {                                                                                        \
        constexpr LogMacroData operator()() const noexcept {                                        \
            return LogMacroData{format, __FILE__, anonymous_function, __LINE__, LogLevel::INFO};    \
        }                                                                                           \
    } anonymous_meta_data;                                                                          \
    log<decltype(anonymous_meta_data)>(__VA_ARGS__);                                                \
} while(false)

#define LOG_DEBUG(format, ...)                                                                      \
do {                                                                                                \
    static constexpr const char* anonymous_function{__FUNCTION__};                                  \
    struct {                                                                                        \
        constexpr LogMacroData operator()() const noexcept {                                        \
            return LogMacroData{format, __FILE__, anonymous_function, __LINE__, LogLevel::DEBUG};   \
        }                                                                                           \
    } anonymous_meta_data;                                                                          \
    log<decltype(anonymous_meta_data)>(__VA_ARGS__);                                                \
} while(false)

#define LOG_WARN(format, ...)                                                                       \
do {                                                                                                \
    static constexpr const char* anonymous_function{__FUNCTION__};                                  \
    struct {                                                                                        \
        constexpr LogMacroData operator()() const noexcept {                                        \
            return LogMacroData{format, __FILE__, anonymous_function, __LINE__, LogLevel::WARN};    \
        }                                                                                           \
    } anonymous_meta_data;                                                                          \
    log<decltype(anonymous_meta_data)>(__VA_ARGS__);                                                \
} while(false)

#define LOG_ERROR(format, ...)                                                                      \
do {                                                                                                \
    static constexpr const char* anonymous_function{__FUNCTION__};                                  \
    struct {                                                                                        \
        constexpr LogMacroData operator()() const noexcept {                                        \
            return LogMacroData{format, __FILE__, anonymous_function, __LINE__, LogLevel::ERROR};   \
        }                                                                                           \
    } anonymous_meta_data;                                                                          \
    log<decltype(anonymous_meta_data)>(__VA_ARGS__);                                                \
} while(false)

// using TypeDescriptors = int32_t;

// struct LogStatementMetaData {
//     LogMacroData macro_data;
//     TypeDescriptors descriptors;
// };

#endif // __LOGGER_HPP__