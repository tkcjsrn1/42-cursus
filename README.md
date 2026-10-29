# 42-cursus

42 Tokyo Common Core에서 작성한 C 과제 모음입니다. 각 과제는 원본 코드를 그대로 담고, 다시 빌드하고 테스트한 결과를 함께 기록했습니다.

## 진행 현황

| Rank | 과제 | 이 저장소 | 비고 |
|---|---|---|---|
| 00 | libft | [libft/](libft/) | 필수 34개 함수, libc 대조 테스트 2,402건 통과 |
| 01 | get_next_line | [get_next_line/](get_next_line/) | 퍼징 검증은 [gnl-fuzz](https://github.com/tkcjsrn1/gnl-fuzz) |
| 01 | ft_printf | [ft_printf/](ft_printf/) | `cspdiuxX%` 지원, printf 대조 18건 중 17건 일치 |
| 01 | Born2beroot | 없음 | 가상머신 서버 설정 과제(코드 산출물 없음) |
| 02 | push_swap, pipex, minitalk, so_long | 없음 | 수행했으나 원본 코드 보관본 없음 |
| 02 | Exam Rank 02 연습 | [exam_rank02/](exam_rank02/) | `first_word` |

42 인트라 계정이 비활성화되어 제출 저장소(vogsphere)에 접근할 수 없어서, 개인 PC에 남아 있던 사본으로 복원했습니다. 원본이 남아 있지 않은 과제는 올리지 않았습니다. 사본 일부는 Windows에서 편집된 흔적(CRLF 줄바꿈, 대소문자만 다른 파일명 충돌)이 있어 Linux 빌드를 위해 최소한으로 손봤고, 바꾼 내용은 각 과제 README의 "복원 메모"에 모두 적었습니다. 함수 로직은 바꾸지 않았습니다(예외: ft_printf의 사용하지 않는 변수 1개 삭제).

> 작업 방식: 과제 코드는 직접 작성한 원본입니다. 복원 작업, README, `verification/`의 검증 코드는 AI 코딩 도구(Claude)와 함께 작성했습니다.

## 다시 검증한 결과

| 항목 | 결과 |
|---|---|
| norminette | 세 과제 모두 통과 |
| `cc -Wall -Wextra -Werror` 빌드 | 세 과제 모두 통과 |
| libft vs libc 대조 (ASan + UBSan) | 2,402건 통과. UBSan이 `ft_itoa`의 정의되지 않은 동작 1건 검출 (아래) |
| ft_printf vs printf 대조 (ASan + UBSan) | 18건 중 17건 일치. 1건은 의도한 설계 차이 |
| get_next_line | 본인 테스트 5종 통과, 퍼징으로 과거 버전 버그 2건 발견 (gnl-fuzz) |

### 다시 보며 찾은 것: `ft_itoa`의 정의되지 않은 동작

```c
if (n < 0)
    num = (unsigned int)(-n);   /* n == INT_MIN 이면 -n 이 int 오버플로 (UB) */
```

`-n`이 `unsigned int`로 바뀌기 전에 `int`에서 계산되므로, `n == INT_MIN`이면 부호 있는 정수 오버플로(UB)입니다. gcc와 clang의 -O0 ~ -O3, -Os 결과는 모두 `-2147483648`로 정상이었지만, 이는 우연히 맞은 것이지 보장된 결과가 아닙니다. 올바른 형태는 `num = 0u - (unsigned int)n;`입니다. `ft_putnbr_fd`도 같은 패턴입니다.

반대로 `ft_calloc`의 `if (s != 0 && c > SIZE_MAX / s)`는 곱셈 오버플로를 곱하기 전에 막는 올바른 가드입니다(테스트로 확인).

## 검증 코드

`verification/`의 테스트는 재검증을 위해 새로 작성한 코드이며, 과제 제출물이 아닙니다.

```bash
cd verification
cc -fsanitize=address,undefined test_libft.c ../libft/*.c -I../libft -lbsd -o test_libft && ./test_libft
cc -fsanitize=address,undefined test_printf.c ../ft_printf/*.c -I../ft_printf -o test_printf && ./test_printf
```
