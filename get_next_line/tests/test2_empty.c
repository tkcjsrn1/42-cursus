#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	printf("=== 빈 파일 테스트 ===\n");
	
	fd = open("empty.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error: 파일을 열 수 없습니다.\n");
		return (1);
	}
	
	line = get_next_line(fd);
	if (line == NULL)
		printf("빈 파일에서 NULL이 반환됨 (정상)\n");
	else
	{
		printf("예상하지 못한 결과: %s\n", line);
		free(line);
	}
	
	close(fd);
	return (0);
}