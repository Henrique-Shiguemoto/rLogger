# rLogger.h

This is a simple header-only C/C++ logger for my projects.

## Technologies Used

- C11
- Sublime Text (no packages)
- Makefiles

## How to use

Just copy and paste the header file into your project, then you should be able to just write <code>#include "rLogger.h"</code> in your source file.

If you wish to use the function implementations already provided in rLogger.h, you need to add the line <code>#define RLOGGER_IMPLEMENTATION</code> before including rLogger.h (look at main.c or main.cpp). 
But if you want to implement your own versions of the interface, then you don't need to do that.

The output log file is called "rLog.log" by default. You can call it something else by writing the following code at the top of the source file:

<code>
	#undef LOG_FILE_NAME <br/></code>
<code>
	#define LOG_FILE_NAME "choose your custom name"
</code>