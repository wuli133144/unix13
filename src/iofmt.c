
#include"../inc/common.h"

/*@main start@*/
int main(){
   

   Init_Buffer(buffer);
   //SCPY(buffer,"234567");
   snprintf(buffer,BUFSIZE,"%s","12345");
   OUT(buffer);
   return  0;
}
/*@main end@*/