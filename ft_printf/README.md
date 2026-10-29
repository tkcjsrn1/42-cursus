# ft_printf

`printf`의 핵심 서식 지정자를 가변 인자(`stdarg.h`)로 직접 구현한 정적 라이브러리(`libftprintf.a`)입니다.

## 지원 서식

| 지정자 | 출력 | 담당 파일 |
|---|---|---|
| `%c` | 문자 | `print_char.c` |
| `%s` | 문자열 (`NULL`이면 `(null)`) | `print_str.c` |
| `%p` | 포인터 16진수 (`NULL`이면 `(nil)`) | `print_pointer.c` |
| `%d` `%i` | 부호 있는 10진수 | `print_int.c` |
| `%u` | 부호 없는 10진수 | `print_unsigned.c` |
| `%x` `%X` | 16진수 소문자 / 대문자 | `print_sx.c` / `print_X.c` |
| `%%` | `%` | `print_percent.c` |

## 구조

```
ft_printf()          서식 문자열을 한 글자씩 읽음
  └─ '%' 다음 글자 → ft_format()   지정자별 함수로 분기
                       └─ print_*()  재귀로 자릿수 출력, 출력한 글자 수 반환
```

모든 출력 함수가 출력한 글자 수를 돌려주고, `ft_printf`가 합산해 반환합니다. `print_int`는 `INT_MIN`을 따로 처리해 부호 반전 오버플로를 피합니다.

## 빌드

```bash
make        # libftprintf.a
```

## 재검증 결과

같은 인자를 `printf`와 `ft_printf`에 넣어 출력 바이트와 반환값을 비교했습니다(`../verification/test_printf.c`).

- 18건 중 17건 일치 (`INT_MIN`, `UINT_MAX`, `NULL` 문자열·포인터, 0 등 경계값 포함)
- 다른 1건: 서식 문자열이 `%`로 끝날 때. glibc는 `-1`을 반환하고 아무것도 출력하지 않지만, 이 구현은 `%`를 그대로 출력합니다. C 표준상 정의되지 않은 경우라 크래시를 피하는 쪽을 택한 설계입니다.

## 복원 메모

개인 PC(Windows) 사본에서 복원했습니다. Linux 빌드를 위해 바꾼 것은 다음과 같습니다.

- 소문자 16진수 파일 이름은 사본 그대로 `print_sx.c`를 유지했습니다. PC 사본에 이 이름으로 저장되어 있었고, Windows는 대소문자만 다른 `print_x.c`와 `print_X.c`를 한 폴더에 둘 수 없어 그대로 두었습니다. `Makefile`의 소스 목록도 `print_sx.c`로 맞췄고, CRLF 줄바꿈은 LF로 바꿨습니다.
- `Makefile`: 의존성 헤더 이름 `libftprintf.h` → `ft_printf.h`, `re: fclean alls` 오타 수정
- `print_pointer.c`: 값만 대입하고 쓰지 않던 변수 `addr` 삭제. 최신 gcc/clang에서는 `-Wunused-but-set-variable`로 `-Werror` 빌드가 실패합니다.
