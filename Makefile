HEADER = /path/to/lua5.3/headers/
LIB = /path/to/lua5.3/lib/
all: interp.c
        mkdir -p build
        gcc hulua.c -llua -lm -L $(LIB) -I $(HEADER) -R $(LIB) -o hulua


