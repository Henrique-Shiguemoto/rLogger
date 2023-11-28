COMPILER=clang++
COMPILER_FLAGS=-Wall -Wextra -pedantic -std=c++11 -Wno-unused-parameter
SRC=main.cpp
BIN=main.exe
DEBUGGER=gdb

all:
	$(COMPILER) $(SRC) -o $(BIN) $(COMPILER_FLAGS)

run: all
	$(BIN)

debug: all
	$(DEBUGGER) $(BIN)

clean:
	del *.o *.exe rLog.txt rLog.log