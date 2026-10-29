#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		line_count = 0;

	printf("=== 기본 테스트: 일반 텍스트 파일 ===\n");
	
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error: 파일을 열 수 없습니다.\n");
		return (1);
	}
	
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line %d: %s", ++line_count, line);
		if (line[strlen(line) - 1] != '\n')
			printf("\n");
		free(line);
	}
	
	close(fd);
	printf("총 %d줄을 읽었습니다.\n", line_count);
	return (0);
}