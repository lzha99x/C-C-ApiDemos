#include <stdio.h>
#include <string.h>

int div16(int x) {
    int bais = (x >> 31) & 0x1;
    printf("bais = %d\n",bais);
    return (x + bais) >> 1;
}
#define MAXNUM_PER_LINE 100
#define false 0
#define true  1
int testLog() {
    char line_data[MAXNUM_PER_LINE];
    char *p = NULL;
    memset(line_data, 0, MAXNUM_PER_LINE);

    FILE *fp = NULL;
    if ((fp = fopen("D:\\WorkSpaces\\Source\\git\\C-C-ApiDemos\\code\\data\\sysinfo", "r")) == NULL) {
        return false;
    }

    while(fgets(line_data, MAXNUM_PER_LINE, fp)) {
        char* pname = strtok(line_data, ":");
        if (pname == NULL) {
            memset(line_data, 0, MAXNUM_PER_LINE);
            continue;
        }
        if (strstr(pname, "Version") != NULL) {
            int offset = strlen(line_data) + 1;
            while (line_data[offset] == ' ' && offset < MAXNUM_PER_LINE) {
                offset++;
            }
            p = strtok(line_data + offset, "\n");
            printf("1  p = %s\n", p);
            //break;
        }
/********************************/
        if (strstr(pname, "OEM") != NULL) {
            int offset = strlen(line_data) + 1;
            while (line_data[offset] == ' ' && offset < MAXNUM_PER_LINE) {
                offset++;
            }
            p = strtok(line_data + offset, "\n");
            printf("2   p = %s\n", p);
            printf("ret == %d\n",memcmp(p,"0x98401019",10));
            printf("ret == %d\n",strcmp(p,"0x98401019"));
            printf("%d\n",(p == "0x98401011"));
            if ((memcmp(p,"0x98401011",10)) != 0) {
                printf("11111\n");
            }
            //break;
        }
/********************************/
    }
    fclose(fp);
    return true;
}

void main( void ) {
    short int v = -12345;
    unsigned  uv =  v;
    // printf("v = %d, uv = %u\n", v, uv);
    // printf("number = %I64d\n",1048577*(__UINT64_TYPE__)4096);
    // printf("sum = %d\n",(10<<3) + (10<<2) + (10<<1));
    // printf("sum = %d  == %d\n",(10<<2)+(10<<1), (10<<3) -(10<<1));
    // printf("sum = %d  == %d\n",(10<<3)+(10<<2)+(10<<1), (10<<4) -(10<<1));

    // printf("ret = %d \n",div16(-16));
    // printf("-TMin = %d \n",-(-(__INT32_MAX__ + 1)));

    testLog();
    
}
