.PHONY: all upx ptf web webrun test testsoft test60 dbg grind clean

name = FishyHotel
SHELL := /bin/bash

all:
	gcc main.c -Ofast -lSDL2 -lGLESv2 -lEGL -lm -o $(name)_linux

upx:
	strip --strip-unneeded $(name)_linux
	upx --lzma --best $(name)_linux

ptf:
	cc assets/ptf.c -lm -Ofast -march=native -o assets/ptf

web:
	source ~/emsdk/emsdk_env.sh && emcc main.c -DWEB -O3 --closure 1 -s FILESYSTEM=0 -s FETCH -s USE_SDL=2 -s ENVIRONMENT=web -s TOTAL_MEMORY=64MB -o web/index.html --shell-file t.html && emrun web/index.html

webrun:
	source ~/emsdk/emsdk_env.sh && emrun web/index.html

test:
	gcc main.c -I inc -Ofast -lSDL2 -lGLESv2 -lEGL -lm -o /tmp/$(name)_test
	/tmp/$(name)_test
	rm /tmp/$(name)_test

testsoft:
	gcc main.c -Ofast -lSDL2 -lGLESv2 -lEGL -lm -o /tmp/$(name)_test
	LIBGL_ALWAYS_SOFTWARE=1 /tmp/$(name)_test
	rm /tmp/$(name)_test

test60:
	gcc main.c -Ofast -lSDL2 -lGLESv2 -lEGL -lm -o /tmp/$(name)_test
	xrandr --rate 60 && /tmp/$(name)_test && xrandr --rate 165
	rm /tmp/$(name)_test

dbg:
	cc main.c -fsanitize=leak -fsanitize=undefined -fsanitize=address -ggdb3 -lSDL2 -lGLESv2 -lEGL -lm -o $(name)_dbg
	$(name)_dbg

grind:
	valgrind --track-origins=yes --leak-check=full --leak-check=full ./$(name)_linux

clean:
	rm -f $(name)_linux
	rm -f web/index.html
	rm -f web/index.js
	rm -f web/index.wasm
	rm -f assets/ptf