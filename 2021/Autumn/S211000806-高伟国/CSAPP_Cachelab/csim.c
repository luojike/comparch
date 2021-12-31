#include "cachelab.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdint.h>
char *path;
char str[1024];

int Hits=0 , Misses=0, Evicts=0;
typedef struct CacheStruct {
    int valid;
    int tag;
    int stamp;
}CacheLine;
CacheLine **Cache= NULL;
void InitCache(int S,int E){
    Cache = ( CacheLine**)malloc(sizeof(CacheLine*) * S);
    for(int i=0;i<S;i++){
        Cache[i]=( CacheLine*)malloc(sizeof( CacheLine)*E);
        for(int j=0;j<E;j++){
            Cache[i][j].tag=-1;
            Cache[i][j].stamp=-1;
            Cache[i][j].valid=0;
        }
    }
}
void FreeCache(int S){
    for(int i=0;i<S;i++)free(Cache[i]);
    free(Cache);
}
int char2int(char c){
    return c-'0';
}
void  updateStamp(int s,int E)
{
    for(int i = 0; i < 1<<s; ++i)
        for(int j = 0; j < E; ++j)
            if(Cache[i][j].valid == 1)
                ++Cache[i][j].stamp;
}
void update(uint64_t address,int b,int s,int E){
    int index = (address >> b) & ((-1U) >> (64 - s));
    int tag = address >> (b + s);
    int MaxStamp=INT_MIN;
    int MaxStamp_index=-1;
    for(int i=0;i<E;i++){
        if(Cache[index][i].tag==tag)
        {
            Cache[index][i].stamp=0;
            ++Hits;
            return ;
        }
    }
    for(int i=0;i<E;i++){
        if (Cache[index][i].valid==0){
            Cache[index][i].stamp=0;
            Cache[index][i].valid=1;
            Cache[index][i].tag=tag;
            ++Misses;
            return ;
        }
    }
    ++Evicts;++Misses;
    for(int i = 0; i < E; ++i)
    {
        if(Cache[index][i].stamp > MaxStamp)
        {
            MaxStamp = Cache[index][i].stamp;
            MaxStamp_index = i;
        }
    }
    Cache[index][MaxStamp_index].tag = tag;
    Cache[index][MaxStamp_index].stamp = 0;

    return ;

}

int main(int argc,char* argv[])
{
    int s,E,b,size;
    char op;
    uint64_t address;
    FILE *fp;
    for(int i=1;i<argc;i++) {
        if (argv[i][0]=='-'){
            char tag=argv[i][1];
            switch (tag) {
                case 's':
                    s=char2int(argv[++i][0]);
                    break;
                case 'E':
                    E=char2int(argv[++i][0]);
                    break;
                case 'b':
                    b=char2int(argv[++i][0]);
                    break;
                case  't':
                    path=argv[++i];
                    break;
                default:
                    break;
            }
        }
        if(i>argc)break;
    }
    InitCache(1<<s, E);
    fp=fopen(path,"r");
    if(fp == NULL)
    {
        printf("open error");
        exit(-1);
    }
    while( fgets(str, 100, fp) != NULL ) {
        sscanf(str, " %c %lx,%d", &op, &address, &size);
        switch (op) {
            case 'I':
                continue;
            case 'L':case 'S':
                update(address, b, s, E);
                break;
            case 'M':
                update(address,b,s,E);
                update(address, b, s, E);
                break;
        }
        updateStamp(s,E);
        }
    fclose(fp);
    FreeCache(1>>s);
    printSummary(Hits, Misses, Evicts);
    return 0;
}
