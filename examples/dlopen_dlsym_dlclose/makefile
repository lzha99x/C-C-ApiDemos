LIB_NAME?=hello
SOURCE?=dlopen_dlsym_dlclose

all:shared_library source


shared_library:
	gcc -shared -fpic -o lib${LIB_NAME}.so ${LIB_NAME}.c

source:
	gcc -o ${SOURCE} ${SOURCE}.c -ldl

clean:
	rm -rf lib${LIB_NAME}.so
	rm -rf ${SOURCE}
