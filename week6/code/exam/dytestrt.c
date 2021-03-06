#include "dylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
int main()
{
	void *hd;
	void (*f1)();
	int (*f2)(),(*f3)();
    char *error;
    int a[100] = {99,-887,9874,1,23};
    hd = dlopen("../dynamiclib/libtest.so",RTLD_LAZY);
    if (!hd){
        fprintf(stderr,"%s\n",dlerror());
        exit(1);
    }
    f1 = dlsym(hd,"showarray");
    if((error = dlerror())!=NULL){
        fprintf(stderr,"%s\n",dlerror());
        exit(1);
    }
    f2 = dlsym(hd,"max");
	if((error=dlerror())!=NULL){
        fprintf(stderr,"%s\n",dlerror());
        exit(1);
    }
	f3 = dlsym(hd,"sum");
    if((error=dlerror())!=NULL){
        fprintf(stderr,"%s\n",dlerror());
        exit(1);
    }
    f1(a,5);
    printf("max=%d",f2(a,10));
	printf("sum=%d",f3(a,10));
	
	if(dlclose(hd)<0){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}	
	return 0;
}
