# This Makefile attempts to create a components that all can be linked together to create a compiler
#

COMPILER = clang++
CFLAGS = -Wc++17-extensions -Wall
OUTPUT = diablo
OBJS := $(shell ls -d build/*)
INCS = -Ilexical_analysis/includes
LIBS = -L lexical_analysis/bin/static/lexiLib


all: prereqs lexical collate

run: lexical collate
	./$(OUTPUT)
collate:
	$(COMPILER) $(CFLAGS) diablo.cpp $(INC_PATH) $(OBJS) $(LIBS) -o $(OUTPUT)
clean:
	rm -rf build $(OUTPUT)
prereqs:
	mkdir build 2>/dev/null || echo "Already present"

# LEXI

lexical:
	cd lexical_analysis/ && $(MAKE) create_static
	cp lexical_analysis/*.o build
