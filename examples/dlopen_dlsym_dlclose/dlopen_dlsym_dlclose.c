#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <dlfcn.h>
#include "apidemos.h"
/*
typedef struct {
 const char *module;
 int  (*GetValue)(char *pszVal);
 int   (*PrintfHello)();
} hello_ST_API;
*/
int main( void ) {
	hello_ST_API *hello;
	int i = 0;
	void *handle;
	char psValue[20] = {0};

	handle = dlopen("./libhello.so",RTLD_LAZY);
	if (! handle) {
  		printf("%s,%d, NULL == handle\n", __FUNCTION__, __LINE__);
  		return -1;
 	}
 	dlerror();

 	hello = (hello_ST_API *)dlsym(handle, "Hello");
 	if (!hello) {
  		printf("%s,%d, NULL == handle\n", __FUNCTION__, __LINE__);
  		return -1;
 	}

 	if (hello && hello->PrintfHello)
  		i = hello->PrintfHello();

  	printf("%s, %d, i = %d\n", __FUNCTION__, __LINE__, i);

 	if (hello && hello->GetValue)
  		i = hello->GetValue(psValue);

  	printf("Get Value is <%s>\n", psValue);

 	if (hello && hello->module)
  	{
   		printf("%s, %d, module = %s\n", __FUNCTION__, __LINE__, hello->module);
  	}
    dlclose(handle);
    return 0;
}