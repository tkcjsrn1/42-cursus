# libft

C 표준 라이브러리 함수를 직접 다시 구현한 정적 라이브러리(`libft.a`)입니다. 42 Common Core의 첫 과제입니다.

## 구현한 함수 (필수 34개)

| 분류 | 함수 |
|---|---|
| 문자 판별·변환 | `ft_isalpha` `ft_isdigit` `ft_isalnum` `ft_isascii` `ft_isprint` `ft_toupper` `ft_tolower` |
| 메모리 | `ft_memset` `ft_bzero` `ft_memcpy` `ft_memmove` `ft_memchr` `ft_memcmp` `ft_calloc` |
| 문자열 (libc) | `ft_strlen` `ft_strlcpy` `ft_strlcat` `ft_strchr` `ft_strrchr` `ft_strncmp` `ft_strnstr` `ft_strdup` `ft_atoi` |
| 문자열 (추가) | `ft_substr` `ft_strjoin` `ft_strtrim` `ft_split` `ft_itoa` `ft_strmapi` `ft_striteri` |
| 출력 | `ft_putchar_fd` `ft_putstr_fd` `ft_putendl_fd` `ft_putnbr_fd` |

보너스(연결 리스트 `ft_lst*`)는 구현하지 않았습니다.

## 빌드

```bash
make        # libft.a
make re
```

## 구현 포인트

- `ft_memmove`: 원본과 대상 영역이 겹칠 때 방향을 나눠 복사합니다.
- `ft_calloc`: `c > SIZE_MAX / s`로 곱셈 오버플로를 할당 전에 막습니다.
- `ft_itoa`: 자릿수를 먼저 세어 한 번에 할당하고, `unsigned int`로 바꿔 뒤에서부터 채웁니다.

## 재검증 결과

libc 함수와 같은 입력을 넣어 결과를 비교했습니다(ASan + UBSan, `../verification/test_libft.c`).

- 2,402건 모두 일치
- UBSan 검출 1건: `ft_itoa(INT_MIN)`에서 `-n`이 `int` 오버플로(정의되지 않은 동작). 출력은 gcc/clang 모든 최적화 레벨에서 정상이었지만 보장된 결과는 아닙니다. `ft_putnbr_fd`도 같은 패턴입니다. 고친다면 `0u - (unsigned int)n` 형태가 맞습니다.

## 복원 메모

개인 PC 사본에서 복원했습니다. 바꾼 것은 다음 하나입니다.

- `ft_split.c`: 함수 사이 빈 줄 1줄 추가 (norminette `NEWLINE_PRECEDES_FUNC`)
