#define RLOGGER_IMPLEMENTATION
#include "rLogger.h"

// this is an example code of how to use the library.

int main(void){
	rLogger_init(RLOG_FILE_MODE);

	RLOGGER_WARN("Hello %s, this is %f", "World", 42.0f);
	RLOGGER_ERROR("Hello %s, this is %f", "World", 42.0f);
	RLOGGER_INFO("Hello %s, this is %f", "World", 42.0f);
	RLOGGER_DEBUG("Hello %s, this is %f", "World", 42.0f);

	rLogger_set_mode(RLOG_TERMINAL_MODE);

	RLOGGER_WARN("Hello %s, this is %f", "World", 3.14f);
	RLOGGER_ERROR("Hello %s, this is %f", "World", 3.14f);
	RLOGGER_INFO("Hello %s, this is %f", "World", 3.14f);
	RLOGGER_DEBUG("Hello %s, this is %f", "World", 3.14f);

	rLogger_set_mode(RLOG_TERMINAL_MODE | RLOG_FILE_MODE);

	RLOGGER_WARN("Hello %s, this is %f", "World", 42.0f);
	RLOGGER_ERROR("Hello %s, this is %f", "World", 42.0f);
	RLOGGER_INFO("Hello %s, this is %f", "World", 42.0f);
	RLOGGER_DEBUG("Hello %s, this is %f", "World", 42.0f);

	rLogger_set_mode(RLOG_TERMINAL_AND_FILE_MODE);

	RLOGGER_WARN("Hello %s, this is %f", "World", 100.0f);
	RLOGGER_ERROR("Hello %s, this is %f", "World", 100.0f);
	RLOGGER_INFO("Hello %s, this is %f", "World", 100.0f);
	RLOGGER_DEBUG("Hello %s, this is %f", "World", 100.0f);

	rLogger_quit();
	return 0;
}
