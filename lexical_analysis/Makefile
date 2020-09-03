objects = reader.o lexi.o lexer_rules.o
COMPILER = clang++
OUTPUT = lexi

all: lexi run

lexi: $(objects)
	$(COMPILER) -o $(OUTPUT) $(objects)
lexi.o: lexi.cpp
	$(COMPILER) -c lexi.cpp
reader.o: src/reader.cpp includes/reader.hpp
	$(COMPILER) -c -g src/reader.cpp
lexer_rules.o: src/lexer_rules.cpp includes/lexer_rules.hpp
	$(COMPILER) -c -g src/lexer_rules.cpp
run:
	./$(OUTPUT) source.txt
clean: object_clean
	rm $(OUTPUT)
object_clean:
	rm $(objects)
debug: delta
	gdb $(OUTPUT)
