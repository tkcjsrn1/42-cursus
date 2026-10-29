#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		line_count = 0;

	printf("=== 긴 줄 테스트 (BUFFER_SIZE보다 긴 줄) ===\n");
	
	fd = open("large_line.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error: 파일을 열 수 없습니다.\n");
		return (1);
	}
	
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line %d (길이: %zu): %.50s", ++line_count, strlen(line), line);
		if (strlen(line) > 50)
			printf("...");
		if (line[strlen(line) - 1] != '\n')
			printf(" (개행 없음)");
		printf("\n");
		free(line);
	}
	
	close(fd);
	printf("총 %d줄을 읽었습니다.\n", line_count);
	return (0);
}