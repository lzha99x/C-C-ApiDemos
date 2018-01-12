#include <stdio.h>
//#include "apidemos.h"


typedef struct
{
	const char * module;
	int (*GetValue)(char *pszVal);
	int (*PrintHello)();
}hello_ST_API;

int GetValue(char *pszVal){
	int ret = -1;

	if (pszVal) {
		ret = sprintf(pszVal, "%s", "From GetValue");
//		printf("%s, %d, pszVer = %s\n", __FUNCTION__, __LINE__, pszVal);
		return ret;
	}
}


int PrintfHello()
{
 	int retval = -1;

 printf("%s, %d, hello everyone\n", __FUNCTION__, __LINE__);
 return 0;
}

const hello_ST_API Hello = {
	.module = "hello",
	.GetValue = GetValue,
	.PrintHello = PrintfHello ,
};

