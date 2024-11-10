#include<unistd.h>
#include<stdlib.h>
void *memset(void *dest, int c, size_t size){ //size is the number of bytes to set to c .
	unsigned char *str = (unsigned char *)dest;
	size_t i =0;
	while (i<size){
		str[i] = (unsigned char)c;
		i++;
	}
	return dest;
}
int main(){
	void *dest;
	dest = (char *)malloc(10);
	size_t n = 10;
	int c = 12;
	char *me = (char *)memset(dest, c, n);
	int i=-1;
	while(i++< 10){
		write(1, &me[i],1);
	}
}
