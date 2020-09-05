objects = reader.o lexi.o lexer_rules.o lexeme.o lexer.o
COMPILER = clang++ -Wc++17-extensions
OUTPUT = lexi

all: lexi run

lexi: $(objects)
	$(COMPILER) -o $(OUTPUT) $(objects)
lexi.o: lexi.cpp
	$(COMPILER) -c lexi.cpp
reader.o: src/reader.cpp includes/reader.hpp
	$(COMPILER) -c -g src/reader.cpp
lexer.o: src/lexer.cpp includes/lexer.hpp
	$(COMPILER) -c -g src/lexer.cpp
lexer_rules.o: src/lexer_rules.cpp includes/lexer_rules.hpp
	$(COMPILER) -c -g src/lexer_rules.cpp
lexeme.o: src/lexeme.cpp includes/lexeme.hpp
	$(COMPILER) -c -g src/lexeme.cpp
run:
	./$(OUTPUT) source.txt
clean: object_clean
	rm $(OUTPUT)
object_clean:
	rm $(objects)
debug: delta
	gdb $(OUTPUT)
