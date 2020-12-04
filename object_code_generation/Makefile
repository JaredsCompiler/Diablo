OBJS = command.o  DiabloExceptions.o # include balancer.o after, needed for synthetic.cpp
COMPILER = clang++
CFLAGS = -Wc++17-extensions -Wall
OUTPUT = synthetic
LIBNAME = syntheticLib

LIBPATH = -L bin/static/$(LIBNAME)
#OUTERLIBS = -L ../lexical_analysis/bin/static/lexiLib

INC_PATH = -Iincludes
#OUTERINC = -I../lexical_analysis/includes


all: scanner parser synthetic run
bisonBuild: scanner parser $(OBJS)
	$(COMPILER) $(CFLAGS) main.cpp $(INC_PATH) $(OBJS) $(LIBPATH) src/maths.cpp src/stack_operations.cpp src/scanner.cpp src/parser.cpp src/interpreter.cpp -o $(OUTPUT)

build: $(OBJS)
test_static: create_static synthetic

create_static: $(OBJS)
	ar rcs bin/static/$(LIBNAME).a $(OBJS)
get_lexi:
	[[ ! -d "../lexical_analysis/build" ]] && mkdir ../lexical_analysis/build || echo "Already present"
	cd ../lexical_analysis/ && $(MAKE) create_static && cp ../lexical_analysis/*.o ../lexical_analysis/build
	mv ../lexical_analysis/build .

scanner: src/scanner.l
	flex -o src/scanner.cpp src/scanner.l

parser: src/parser.y
	bison -o src/parser.cpp src/parser.y

command.o: includes/command.h src/command.cpp
	$(COMPILER) $(CFLAGS) -c src/command.cpp

templateCommand.o: src/templateCommand.cpp
	$(COMPILER) $(CFLAGS) -c src/templateCommand.cpp

synthetic: scanner parser $(OBJS) create_static get_lexi
	$(COMPILER) $(CFLAGS) main.cpp $(INC_PATH) $(OUTERINC) $(shell ls -d build/*) $(OBJS) $(LIBPATH) $(OUTERLIBS) src/maths.cpp src/stack_operations.cpp src/scanner.cpp src/parser.cpp src/interpreter.cpp -o synthetic

balancer.o: src/balancer.cpp includes/balancer.hpp
	$(COMPILER) $(CFLAGS) -c src/balancer.cpp

synthetic.o: synthetic.cpp
	$(COMPILER) $(CFLAGS) -c synthetic.cpp

DiabloExceptions.o: src/DiabloExceptions.cpp includes/DiabloExceptions.hpp
	$(COMPILER) $(CFLAGS) -c src/DiabloExceptions.cpp

run:
	./$(OUTPUT) -h

clean: 
	rm $(OUTPUT) $(OBJS) src/scanner.cpp src/parser.cpp src/parser.hpp src/*.hh

debug: synthetic
	gdb $(OUTPUT)
