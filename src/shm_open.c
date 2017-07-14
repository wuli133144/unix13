#include"../inc/common.h"

#define SHM_NAME  "info"
#define OPEN_FLAG  O_RDWR|O_CREAT
#define OPEN_MODE  0777



int main(){

    int fd;
    int rval=-1;
    char buffer[BUFSIZE];
    memset(buffer,0,BUFSIZE);
    void *base=nullptr;
    fd=Shm_open(SHM_NAME,OPEN_FLAG,OPEN_MODE);
    
    Ftruncate(fd,BUFSIZE);//截断文件内容
    
    base=Mmap(nullptr,BUFSIZE,PROT_READ,MAP_SHARED,fd,SEEK_SET);
    
    memcpy(buffer,base,sizeof(buffer));
    
    printf("%s",base);
    
    Munmap(base,BUFSIZE);//除去映射共享

    Shm_unlink(SHM_NAME);

    return 0;
}