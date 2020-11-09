OBJS =  balancer.o command.o DiabloExceptions.o
COMPILER = clang++
CFLAGS = -Wc++17-extensions -Wall
OUTPUT = synthetic
LIBNAME = syntheticLib

LIBPATH = -L bin/static/$(LIBNAME)
OUTERLIBS = -L ../lexical_analysis/bin/static/lexiLib

INC_PATH = -Iincludes
OUTERINC = -I../lexical_analysis/includes


all: scanner parser synthetic run
bGane: scanner parser $(OBJS) create_static get_lexi
	$(COMPILER) $(CFLAGS) main.cpp $(INC_PATH) $(OUTERINC) $(shell ls -d build/*) $(OBJS) $(LIBPATH) $(OUTERLIBS) -o bisonGang
build: $(OBJS)
test_static: create_static synthetic

create_static: $(OBJS)
	ar rcs bin/static/$(LIBNAME).a $(OBJS)
get_lexi:
	[[ ! -d "../lexical_analysis/build" ]] && mkdir ../lexical_analysis/build || echo "Already present"
	cd ../lexical_analysis/ && $(MAKE) create_static && cp ../lexical_analysis/*.o ../lexical_analysis/build
	mv ../lexical_analysis/build .

scanner: scanner.l
	flex -o scanner.cpp scanner.l

parser: parser.y
	bison -o parser.cpp parser.y

command.o: includes/command.h src/command.cpp
	$(COMPILER) $(CFLAGS) -c src/command.cpp

synthetic: $(OBJS) create_static get_lexi
	$(COMPILER) $(CFLAGS) synthetic.cpp $(INC_PATH) $(OUTERINC) $(shell ls -d build/*) $(OBJS) $(LIBPATH) $(OUTERLIBS) -o $(OUTPUT)

balancer.o: src/balancer.cpp includes/balancer.hpp
	$(COMPILER) $(CFLAGS) -c src/balancer.cpp

synthetic.o: synthetic.cpp
	$(COMPILER) $(CFLAGS) -c synthetic.cpp

DiabloExceptions.o: src/DiabloExceptions.cpp includes/DiabloExceptions.hpp
	$(COMPILER) $(CFLAGS) -c src/DiabloExceptions.cpp

run:
	./$(OUTPUT)

clean: 
	rm -r build $(OUTPUT) $(OBJS) *.hh

debug: synthetic
	gdb $(OUTPUT)
