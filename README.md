# rLogger

This is a simple header-only C/C++ logger for my projects.

## Technologies Used

- C11
- Sublime Text (no packages)
- Makefiles

## How to use

Just copy and paste the header file into your project, then you should be able to just write <code>#include "rLogger.h"</code> in your source file.

If you wish to use the function implementations already provided in rLogger.h, you need to add the line <code>#define RLOGGER_IMPLEMENTATION</code> before including rLogger.h.

But if you want to implement your own versions of the interface, then you don't need to do that.