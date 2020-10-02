objects = reader.o lexer_rules.o lexeme.o lexer.o
COMPILER = clang++
CFLAGS = -Wc++17-extensions -Wall
OUTPUT = lexi
LIBNAME = lexiLib
LIBPATH = -L bin/static$(LIBNAME)
INC_PATH = -Iincludes

all: lexi run
build: $(objects)
test_static: create_static lexi

create_static: $(objects)
	ar rcs bin/static/$(LIBNAME).a $(objects)
lexi: $(objects) create_static
	$(COMPILER) $(CFLAGS) lexi.cpp $(INC_PATH) $(objects) $(LIBPATH) -o $(OUTPUT)
lexi.o: lexi.cpp
	$(COMPILER) $(CFLAGS) lexi.cpp
reader.o: src/reader.cpp includes/reader.hpp
	$(COMPILER) $(CFLAGS) -c -g src/reader.cpp
lexer.o: src/lexer.cpp includes/lexer.hpp
	$(COMPILER) $(CFLAGS) -c -g src/lexer.cpp
lexer_rules.o: src/lexer_rules.cpp includes/lexer_rules.hpp
	$(COMPILER) $(CFLAGS) -c -g src/lexer_rules.cpp
lexeme.o: src/lexeme.cpp includes/lexeme.hpp
	$(COMPILER) $(CFLAGS) -c -g src/lexeme.cpp
run:
	./$(OUTPUT) inputs/1_line.txt
clean: object_clean
	rm $(OUTPUT)
object_clean:
	rm $(objects)
debug: lexi
	gdb $(OUTPUT)
