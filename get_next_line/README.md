# get_next_line

파일 디스크립터에서 한 줄씩 읽어 돌려주는 `get_next_line(int fd)` 구현입니다. `read`가 `BUFFER_SIZE` 단위로만 읽기 때문에, 줄 경계를 넘어 읽은 나머지를 `static` 버퍼에 보관했다가 다음 호출에 이어 씁니다.

## 구조

| 함수 | 역할 |
|---|---|
| `get_next_line` | `static char *stash` 관리, 줄 하나 반환 |
| `read_until_nl` | `stash`에 `'\n'`이 생기거나 EOF가 될 때까지 `read` 후 이어 붙임 |
| `extract_line` | `stash`에서 첫 줄(`'\n'` 포함)을 잘라 새로 할당 |
| `clean_stash` | 반환한 줄을 뺀 나머지만 남김 |

## 빌드와 테스트

```bash
make                                   # get_next_line.a (BUFFER_SIZE=1024)
cd tests
cc -D BUFFER_SIZE=42 -I.. test1_basic.c ../get_next_line.c ../get_next_line_utils.c && ./a.out
```

`tests/`에는 과제 당시 직접 만든 테스트 5종(기본, 빈 파일, 마지막 개행 없음, `BUFFER_SIZE`보다 긴 줄, 잘못된 fd)이 있습니다. AddressSanitizer를 켜고 다시 돌려 모두 통과했습니다.

## 퍼징으로 다시 검증

이 구현을 libFuzzer와 AFL++로 다시 검증한 기록은 별도 저장소 [gnl-fuzz](https://github.com/tkcjsrn1/gnl-fuzz)에 있습니다. 2025년 8월 중간 버전에서 EOF 이후 재호출 시 use-after-free와 메모리 누수를 찾았고, 이 저장소의 최종 버전에서는 두 문제가 모두 고쳐져 있습니다.

## 복원 메모

- 소스는 2025-09-04 제출 시점 압축본(`get_next_line.zip`)을 사용했습니다. 이후(2025-12) PC에서 다시 편집된 `get_next_line_utils.c`는 변수 `j`가 두 번 선언되어 컴파일되지 않아 제외했습니다.
- `get_next_line.c` 52번째 줄 `if (!buf)` 앞에 빠져 있던 탭 1개 추가 (norminette `TOO_FEW_TAB`)
