
#include"../inc/common.h"



// int Reg_lock(int fd,int cmd,int type,off_t offset,int when,off_t len){
//     struct flock lock;
//     lock.l_type=type;
//     lock.l_start=offset;
//     lock.l_whence=when;
//     lock.l_len=len;
//     return Fcntl(fd,cmd,&lock);
// }
   
// #define  read_lock(fd,offset,whence,len) \
//             Reg_lock((fd),(F_SETLK),(F_RDLCK),(offset),(whence),(len))

// #define  readw_lock(fd,offset,whence,len) \
//            Reg_lock((fd),(F_SETLKW),(F_RDLCK),(offset),(whence),(len))


// #define  write_lock(fd,offset,whence,len) \
//            Reg_lock((fd),(F_SETLK),(F_WRLCK),(offset),(whence),(len))

// #define  writew_lock(fd,offset，whence,len)\
//            Reg_lock((fd),(F_SETLKW),(F_WRLCK),(offset),(whence),(len))


void sighand(int a){
  printf("signal=%d\n",a);
  return;
}

#define CP_SZ   1024*1024*1024
#define PAGESIZE  4096
             
int main(int argc,char **argv){
  
    
    int fd;
    struct stat st;
    int size;
    void *addr_start=nullptr;

    fd=Open("info",O_CREAT|O_RDWR,0666);
    
    fstat(fd,&st);


    signal(SIGSEGV,sighand);
    size=st.st_size;
    printf("size=%d",size);
    //Get size 
    off_t off=(st.st_size%PAGESIZE==0)?(st.st_size):(st.st_size/PAGESIZE+1)*PAGESIZE;

    addr_start=Mmap(nullptr,size,PROT_WRITE,MAP_SHARED,fd,off);//success
    
    printf("%s",addr_start);
   
    return 0;
}