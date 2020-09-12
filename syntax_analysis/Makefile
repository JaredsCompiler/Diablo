OBJS =  add.o
COMPILER = clang++
CFLAGS = -Wc++17-extensions -Wall
OUTPUT = sin
LIBNAME = sinLib

LIBPATH = -L bin/static/$(LIBNAME)
OUTERLIBS = -L ../lexical_analysis/bin/static/lexiLib

INC_PATH = -Iincludes
OUTERINC = -I../lexical_analysis/includes


all: sin run
build: $(OBJS)
test_static: create_static sin

create_static: $(OBJS)
	ar rcs bin/static/$(LIBNAME).a $(OBJS)
get_lexi:
	[[ ! -d "../lexical_analysis/build" ]] && mkdir ../lexical_analysis/build || echo "Already present"
	cd ../lexical_analysis/ && $(MAKE) create_static && cp ../lexical_analysis/*.o ../lexical_analysis/build
	mv ../lexical_analysis/build .

add.o: src/add.cpp includes/add.hpp
	$(COMPILER)	$(CFLAGS) -c -g src/add.cpp

sin: $(OBJS) create_static get_lexi
	$(COMPILER) $(CFLAGS) sin.cpp $(INC_PATH) $(OUTERINC) $(shell ls -d build/*) $(OBJS) $(LIBPATH) $(OUTERLIBS) -o $(OUTPUT)

sin.o: sin.cpp
	$(COMPILER) $(CFLAGS) -c sin.cpp

run:
	./$(OUTPUT)

clean: 
	rm -r build $(OUTPUT) $(OBJS)

debug: sin
	gdb $(OUTPUT)
