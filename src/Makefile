
detected_OS := $(shell sh -c 'uname -s 2>/dev/null || echo not')

ifeq ($(detected_OS),Linux)
PATH_V=../build/maze
endif
ifeq ($(detected_OS),Darwin)
PATH_V=../build/maze.app/Contents/MacOS/maze
endif

all: install start

r: uninstall install start

install:
	cmake -B" ../build"
	$(MAKE) -C ../build
	ln -sf $(abspath $(PATH_V)) ~/Desktop/maze

start:
	./$(PATH_V)

dist:
	tar czf ../dist.tar *

test:
	$(MAKE) test -C cave/tests

dvi:
	@doxygen Doxyfile && mv html documentation
	@open documentation/index.html

uninstall:
	rm -rf ../build
	rm -rf CMakeLists.txt.user
	rm -rf ~/Desktop/maze
	rm -rf ../dist.tar

clean: uninstall
	rm -rf documentation
	rm -rf latex
	$(MAKE) clean -C cave/tests
