OBJS =  add.o
COMPILER = clang++
CFLAGS = -Wc++17-extensions -Wall
OUTPUT = synthetic
LIBNAME = syntheticLib

LIBPATH = -L bin/static/$(LIBNAME)
OUTERLIBS = -L ../lexical_analysis/bin/static/lexiLib

INC_PATH = -Iincludes
OUTERINC = -I../lexical_analysis/includes


all: synthetic run
build: $(OBJS)
test_static: create_static synthetic

create_static: $(OBJS)
	ar rcs bin/static/$(LIBNAME).a $(OBJS)
get_lexi:
	[[ ! -d "../lexical_analysis/build" ]] && mkdir ../lexical_analysis/build || echo "Already present"
	cd ../lexical_analysis/ && $(MAKE) create_static && cp ../lexical_analysis/*.o ../lexical_analysis/build
	mv ../lexical_analysis/build .

synthetic: $(OBJS) create_static get_lexi
	$(COMPILER) $(CFLAGS) synthetic.cpp $(INC_PATH) $(OUTERINC) $(shell ls -d build/*) $(OBJS) $(LIBPATH) $(OUTERLIBS) -o $(OUTPUT)

add.o: src/add.cpp includes/add.hpp
	$(COMPILER) $(CFLAGS) -c src/add.cpp

synthetic.o: synthetic.cpp
	$(COMPILER) $(CFLAGS) -c synthetic.cpp

ASTNode.o: src/ASTNode.cpp includes/ASTNode.hpp
	$(COMPILER) $(CFLAGS) -c -g src/ASTNode.cpp

run:
	./$(OUTPUT)

clean: 
	rm -r build $(OUTPUT) $(OBJS)

debug: synthetic
	gdb $(OUTPUT)
