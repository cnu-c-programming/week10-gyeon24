#include <stdio.h>

struct S1 {
    char c;
    int i;
    long long l;
};

struct S2 {
    char c;
    int i;
    long long l;
} __attribute__((packed)); [span_3](start_span)// gcc 문법, #pragma pack(1)로 대체 가능[span_3](end_span)

int main() {
    struct S1 s1;
    struct S2 s2;
    printf("%zu %zu\n", sizeof(s1), sizeof(s2)); [span_4](start_span)//[span_4](end_span)
    return 0;
}
