
detected_OS := $(shell sh -c 'uname -s 2>/dev/null || echo not')

ifeq ($(detected_OS),Linux)
PATH_V=build/maze
endif
ifeq ($(detected_OS),Darwin)
PATH_V=build/viewer.app/Contents/MacOS/maze
endif

all: install start

r: uninstall install start

install:
	# cmake -B" build" -H"build"
	cmake -B" build"
	$(MAKE) -C build
	# rm -rf ~/Desktop/viewer
	# ln $(PATH_V) ~/Desktop

start:
	./$(PATH_V)

dist:
	tar czf ../dist.tar *

dvi:
	open ../README_RUS.md

uninstall:
	rm -rf build/*
	rm -rf CMakeLists.txt.user
	# rm -rf ../dist.tar
