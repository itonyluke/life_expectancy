CXX = g++

CXXFLAGS = -g -Wall -Werror -Wextra -Wfloat-equal -Wundef -pedantic -pedantic-errors -D_FORTIFY_SOURCE=2 -D_GLIBCXX_ASSERTIONS -fstack-protector-all -grecord-gcc-switches -pipe
# -g						Builds executable with debugging symbols for GDB GNU Debugger or LLDB Clang/LLVM Debugger.
# 							It should only be used during development for debugging builds.
# W							stands for warning
# -Wall						Turns on -Waddress, -Wcomment, -Wformat, -Wbool-compare, -Wuninitialized,
# 							-Wunknown-pragmas, -Wunused-value, -Wunused-value
# -Werror					Turn any warning into a compilation error.
# -Wextra					Enables -Wsign-compare, -Wtype-limits, -Wuninitialized …
# -pedantic					Issue all warning required by ISO C and ISO C++ standard, it issues warning whenever there
# 							are compiler extensions non compliant to ISO C or C++ standard.
# -D_FORTIFY_SOURCE=2 		Run-time buffer overflow detection	
# -D_GLIBCXX_ASSERTIONS 	Run-time bounds checking for C++ strings and containers
# -fstack-protector-all 	Stack smashing protector
# -grecord-gcc-switches		Store compiler flags in debugging information
# -pipe						$Avoid temporary files, speeding up builds
# -Wfloat-equal				Warn if floating-point values are used in equality comparisons.
# -Wundef					Warn if an undefined identifier is evaluated in an #if directive. Such identifiers are replaced with zero.
# pedantic 					Issue all the warnings demanded by strict ISO C and ISO C++.
# pedantic-errors			Give an error whenever the base standard requires a diagnostic, in some
#							cases where there is undefined behavior at compile-time and in some other cases that do not
#							prevent compilation of programs that are valid according to the standard.

# Get a list of all .cpp files in the current directory
source_files := $(wildcard *.cpp)

# Create a list of executable names by replacing the .cpp extension with .exe
executable_names := $(patsubst %.cpp,%.exe,$(source_files))

# Default target: build all executables
all: $(executable_names)

# Rule to build each executable
%.exe: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# Clean up all executables
clean:
	rm -f $(executable_names)
