#include <stdio.h>
#include <string.h>
#include <math.h>
#include "lua.h"
#include <lauxlib.h>
#include <lualib.h>

int main(int argc, int *argv[]){
	printf("HuLua, Lua 5.3\n");
	char buffer[256];
	int error;
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);
	int index = 1;

	if ( argc > 1 ){
		for ( ; index < argc ; index++ ){
			luaL_dofile(L, argv[index]);
		}
	}
	else {
		while ( fgets( buffer, sizeof(buffer), stdin ) != NULL ){
			error = ( luaL_loadbuffer(L, buffer, strlen(buffer), "line") || lua_pcall(L, 0, 0, 0) );
			if ( error ){
				fprintf(stderr, "%s", lua_tostring(L, -1) );
				lua_pop(L, 1);
			}
		}
	}

	lua_close(L);
	return 0;

}
