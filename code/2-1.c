#include <stdio.h>

union U {
    float f;
    unsigned char c[4];
}; [span_17](start_span)//[span_17](end_span)

int main() {
    union U u;
    u.f = 3.14f; [span_18](start_span)//[span_18](end_span)
    
    for (int i = 0; i < 4; i++) {
        printf("%x\n", (unsigned)u.c[i]); [span_19](start_span)//[span_19](end_span)
    }
    
    return 0;
}
