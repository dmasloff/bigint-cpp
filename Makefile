build: test_simple test_simple_opt test_ubsan

test_simple: tests/biginteger_test.cpp src/biginteger.h
	clang++ -std=c++20 -gdwarf-4 -O0 -Wall -Wextra -Werror -o ./test_simple tests/biginteger_test.cpp src/biginteger.cpp

test_simple_opt: tests/biginteger_test.cpp src/biginteger.h
	clang++ -std=c++20 -O2 -Wall -Wextra -Werror -o ./test_simple_opt tests/biginteger_test.cpp src/biginteger.cpp

test_ubsan: tests/biginteger_test.cpp src/biginteger.h
	clang++ -std=c++20 -g -O0 -Wall -Wextra -Werror -fsanitize=undefined -o ./test_ubsan tests/biginteger_test.cpp src/biginteger.cpp

info:
	clang++ --version
	clang-tidy --version
	clang-format --version
	valgrind --version

run: build
	@echo 'Run tests (simple)'
	time ./test_simple
	@echo 'Run tests (simple_opt)'
	time ./test_simple_opt
	@echo 'Run tests (ubsan)'
	time ./test_ubsan
	@echo 'Run tests (valgrind)'
	time valgrind --leak-check=yes ./test_simple

test: info run lint
	@echo 'Great job!'

clean:
	rm test_simple test_simple_opt test_ubsan