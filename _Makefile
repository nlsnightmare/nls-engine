LIBS      := -lGL -lglfw -lGLEW -lboost_system -lboost_filesystem -llua5.3
STD       := -std=c++1z
BUILDDIR  := ./obj
CC        := clang++-5.0

DEBUG_FLAG:= -g

DIRECTORY = $(sort $(dir $(wildcard ./src/*/*/ ./src/*)))

src := $(wildcard ./src/*.cpp)
src_obj := $(filter-out src/main.cpp, $(src))
src_obj := $(patsubst ./src/%.cpp, ./obj/%.o, $(src))

graphics :=$(wildcard ./src/graphics/*.cpp)
graphics_obj := $(patsubst ./src/graphics/%.cpp, ./obj/%.o, $(graphics))

low_graphics :=$(wildcard ./src/graphics/low_level/*.cpp)
low_graphics_obj := $(patsubst ./src/graphics/low_level/%.cpp, ./obj/%.o, $(low_graphics))

game :=$(wildcard ./src/game/*.cpp)
game_obj := $(patsubst ./src/game/%.cpp, ./obj/%.o, $(game))


main: $(src_obj) $(graphics_obj) $(low_graphics_obj) $(game_obj)
	$(CC) -omain $(wildcard ./obj/*.o) $(LIBS) $(STD) $(DEBUG_FLAG) -MJ./obj/main.o.json

./src/compile_commands.json:
	sed -e '1s/^/[\n/' -e '$s/,$/\n]/' ./obj/*.o.json > ./src/compile_commands.json


clean:
	rm -f ./main ./obj/*
	find . -type f -name '*~' -delete


./obj/main.o: ./src/main.cpp
	$(CC) -c -o./obj/main.o ./src/main.cpp $(STD) $(DEBUG_FLAG) -MJ ./obj/main.o.json

./obj/%.o: ./src/graphics/low_level/%.cpp ./src/graphics/low_level/%.hpp
	$(CC) -c -o$@ $< $(STD) $(DEBUG_FLAG) -MJ $@.json
./obj/%.o: ./src/graphics/%.cpp ./src/graphics/%.hpp
	$(CC) -c -o$@ $< $(STD) $(DEBUG_FLAG) -MJ $@.json
./obj/%.o: ./src/graphics/%.cpp ./src/graphics/%.hpp
	$(CC) -c -o$@ $< $(STD) $(DEBUG_FLAG) -MJ $@.json
./obj/%.o: ./src/game/%.cpp ./src/game/%.hpp
	$(CC) -c -o$@ $< $(STD) $(DEBUG_FLAG) -MJ $@.json
./obj/%.o: ./src/%.cpp ./src/%.hpp
	$(CC) -c -o$@ $< $(STD) $(DEBUG_FLAG) -MJ $@.json
