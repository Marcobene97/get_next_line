/* #include"get_next_line.h"
#include<unistd.h>

int main() {
	int descriptor = open("test.txt", O_RDONLY);
	char* line = NULL;
	int limit = 15;
	while((line = get_next_line(descriptor)) != NULL && limit > 0) {
		limit--;
		puts(line);
		free(line);
		usleep(250000);
	}
	free(line);
	close(descriptor);
} */