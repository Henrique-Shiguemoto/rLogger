# rLogger.h

This is a simple C/C++ logger for my projects.

## Features

- Minimal Standard output logging
- Minimal File logging
- Functional in C and C++

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

Obs: The clang++ compiler warns of the usage of a .c file (<code>rlogger.c</code>) as input for the compiler (it says it is deprecated), since it is a C++ compiler. In my tests, nothing out of the ordinary seems to be happening (tests were made with gcc, clang, g++ and clang++, clang++ seems to be the only one complaining), but beware, maybe clang++ one day will start not allowing .c files as input, who knows.