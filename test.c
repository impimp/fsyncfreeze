#include<stdio.h>

int main() {
	FILE* fp = fopen("./file","wb");

	fputs("test", fp);
	fsync(fileno(fp));
	fclose(fp);
}