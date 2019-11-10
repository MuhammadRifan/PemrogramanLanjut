#include <stdio.h>
#include <stdlib.h>

static int i;
static void func();

void cetak();

//int main(int argc, char *argv[]) {
//	
//	int i;
//	
//	for (i=0; i<5; i++) cetak();
//	for (i=0; i<3; i++) cetak();
//	
//	return 0;
//}

void cetak() {
	static int count = 0;
	printf("count = %d\n", count++);
}

int max_so_far(int curr){
	static int biggest;
	
	if (curr > biggest) biggest = curr;
	return biggest;
}

#define ERROR printf("Error..\n");

int main()
{
	int x=0;
	int y=35;
	if(x == 0) ERROR;

	return 0;
}
