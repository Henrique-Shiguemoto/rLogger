// You may write #define RLOGGER_IMPLEMENTATION in one source file to get the default implementations 
// 		of the function definitions, which use stdio.h, stdarg.h and string.h

// if you wish to implement your own interface, then don't write that line!

#ifndef RLOGGER_H
#define RLOGGER_H

#define LOG_FILE_NAME 			"rLog.txt"
#define OUTPUT_BUFFER_SIZE 		16384

static int _rlog_initialized = 0;

typedef enum rLogger_mode {
	RLOG_TERMINAL_MODE 		= 1,
	RLOG_FILE_MODE 			= 2,
	RLOG_TERMINAL_AND_FILE_MODE = 3,
} rLogger_mode;

typedef enum rLog_level {
	RLOG_DEBUG = 0,
    RLOG_INFO,
    RLOG_WARNING,
    RLOG_ERROR,
    RLOG_LEVEL_COUNT
} rLog_level;

static rLogger_mode current_rLogger_mode = RLOG_TERMINAL_MODE;

int rLogger_init(rLogger_mode mode);
void rLogger_set_mode(rLogger_mode mode);
void rLogger_message(rLog_level level, const char* format, ...);
void rLogger_quit(void);

#define RLOGGER_DEBUG(message, ...) rLogger_message(RLOG_DEBUG, message, __VA_ARGS__);
#define RLOGGER_INFO(message, ...)  rLogger_message(RLOG_INFO, message, __VA_ARGS__);
#define RLOGGER_WARN(message, ...)  rLogger_message(RLOG_WARNING, message, __VA_ARGS__);
#define RLOGGER_ERROR(message, ...) rLogger_message(RLOG_ERROR, message, __VA_ARGS__);

#endif // RLOGGER_H



/*

FUNCTION IMPLEMENTAITONS

*/

#ifdef RLOGGER_IMPLEMENTATION

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

static FILE* log_file_handle = NULL;

int rLogger_init(rLogger_mode mode){
	if(_rlog_initialized) return 1;
	_rlog_initialized = 1;

	int result = 0;
	switch(mode){
		case RLOG_TERMINAL_MODE:
		{
			current_rLogger_mode = RLOG_TERMINAL_MODE;
			printf("[INFO]: Succesfully initialized for terminal logging.\n");
			break;
		} 
		case RLOG_FILE_MODE: 
		{
			current_rLogger_mode = RLOG_FILE_MODE;
			log_file_handle = fopen(LOG_FILE_NAME, "w+");
			if(!log_file_handle){
				printf("[WARNING]: Could'n open log file.\n");
				result = 1;
			}
			printf("[INFO]: Succesfully initialized for file logging.\n");
			break;
		}
		case RLOG_TERMINAL_AND_FILE_MODE:
		{
			current_rLogger_mode = RLOG_TERMINAL_AND_FILE_MODE;
			log_file_handle = fopen(LOG_FILE_NAME, "w+");
			if(!log_file_handle){
				printf("[WARNING]: Could'n open log file.\n");
				result = 1;
			}
			printf("[INFO]: Succesfully initialized for text and file logging.\n");
			break;
		}
		default: 
		{
			result = 1;
			break;
		}
	}
	return result;
}

void rLogger_set_mode(rLogger_mode mode){
	if(mode >= RLOG_TERMINAL_MODE && mode <= RLOG_TERMINAL_AND_FILE_MODE){
		current_rLogger_mode = mode;
	}else{
		current_rLogger_mode = RLOG_TERMINAL_MODE;
	}
}

void rLogger_message(rLog_level level, const char* format, ...){
	if(level < 0 || level > RLOG_LEVEL_COUNT || !_rlog_initialized) return;
	const char* message_prefixes[RLOG_LEVEL_COUNT] = {"[DEBUG]: ", "[INFO]:  ", "[WARN]:  ", "[ERROR]: "};
	char output_buffer[OUTPUT_BUFFER_SIZE];
	memset(output_buffer, 0, OUTPUT_BUFFER_SIZE);

	va_list args;
	va_start(args, format);
	vsnprintf(output_buffer, OUTPUT_BUFFER_SIZE, format, args);
	va_end(args);

	char output_buffer_aux[OUTPUT_BUFFER_SIZE];
	snprintf(output_buffer_aux, OUTPUT_BUFFER_SIZE, "%s%s\n", message_prefixes[level], output_buffer);

	if((current_rLogger_mode & RLOG_TERMINAL_MODE) != 0) 
		printf("%s", output_buffer_aux);
	if((current_rLogger_mode & RLOG_FILE_MODE) != 0)
	 	fwrite(output_buffer_aux, strlen(output_buffer_aux), 1, log_file_handle);
}

void rLogger_quit(void){
	if(_rlog_initialized) {
		printf("[INFO]: Quit from terminal logging.\n");
		if(log_file_handle) fclose(log_file_handle);
	}
}

#endif //RLOGGER_IMPLEMENTATION
