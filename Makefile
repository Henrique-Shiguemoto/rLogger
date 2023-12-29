COMPILER=gcc
COMPILER_FLAGS=-Wall -Wextra -pedantic -std=c11 -Wno-unused-parameter
SRC=main.c rlogger.c
BIN=main.exe
DEBUGGER=gdb

all:
	$(COMPILER) $(SRC) -o $(BIN) $(COMPILER_FLAGS)

run: 
	$(BIN)

debug: 
	$(DEBUGGER) $(BIN)

clean:
	del *.o *.exe rLog.txt rLog.log