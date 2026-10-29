#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;

	printf("=== 에러 케이스 테스트 ===\n");
	
	printf("1. 잘못된 fd (-1) 테스트: ");
	line = get_next_line(-1);
	if (line == NULL)
		printf("NULL 반환 (정상)\n");
	else
	{
		printf("예상하지 못한 결과: %s\n", line);
		free(line);
	}
	
	printf("2. 닫힌 fd 테스트: ");
	line = get_next_line(999);
	if (line == NULL)
		printf("NULL 반환 (정상)\n");
	else
	{
		printf("예상하지 못한 결과: %s\n", line);
		free(line);
	}
	
	printf("3. 같은 fd로 두 번째 호출 후 파일 닫기 테스트\n");
	int fd = open("test.txt", O_RDONLY);
	if (fd != -1)
	{
		line = get_next_line(fd);
		if (line)
		{
			printf("첫 번째 줄: %s", line);
			free(line);
		}
		close(fd);
		
		line = get_next_line(fd);
		if (line == NULL)
			printf("닫힌 fd에서 NULL 반환 (정상)\n");
		else
		{
			printf("예상하지 못한 결과: %s\n", line);
			free(line);
		}
	}
	
	return (0);
}