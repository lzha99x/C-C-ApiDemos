#ifndef APIDEMOS_H
#define APIDEMOS_H

typedef struct
{
	const char *module;
 	int  (*GetValue)(char *pszVal);
 	int   (*PrintfHello)();
}hello_ST_API;
#endif