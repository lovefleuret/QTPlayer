#ifndef LOG_H
#define LOG_H

/***
 *
 * 主要用来打印显示数据
 *
 */

#include <string>



void LogInit();
void Serialize(const char* fmt, ...);

#define DEBUG

#ifdef DEBUG

#define __FILENAME__ (strrchr(__FILE__, '/') ? (strrchr(__FILE__, '/') + 1):__FILE__)
#define makePrefix(fmt) std::string(__FUNCTION__).append("() - ").append(fmt).c_str()

#define LogDebug(fmt, ...)	Serialize(makePrefix(fmt), ##__VA_ARGS__)
#define LogInfo(fmt, ...)	Serialize(makePrefix(fmt), ##__VA_ARGS__)
#define LogNotice(fmt, ...)	Serialize(makePrefix(fmt), ##__VA_ARGS__)
#define LogError(fmt, ...)	Serialize(makePrefix(fmt), ##__VA_ARGS__)


#define FunEntry(...) LogDebug(" Entry... " ##__VA_ARGS__)
#define FunExit(...) LogDebug(" Exit... " ##__VA_ARGS__)

#else 
#define __FILENAME__ do{}while(0)
#define makePrefix(fmt) do{}while(0)

#define LogDebug(fmt, ...) do{}while(0)
#define LogInfo(fmt, ...) do{}while(0)
#define LogNotice(fmt, ...) do{}while(0)
#define LogError(fmt, ...) do{}while(0)

#define FunEntry(...) do{}while(0)
#define FunExit(...) do{}while(0)

#endif

#endif // LOG_H

