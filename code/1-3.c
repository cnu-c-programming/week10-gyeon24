#include <stdio.h>
#include <string.h>

struct IPv4 {
    unsigned int version;
    unsigned int ihl;
    unsigned long long ttl;
    unsigned long long protocol;
    unsigned char data[1024];
};

void update_val(struct IPv4 s) {
    sprintf(s.data, "update_val"); [span_9](start_span)//[span_9](end_span)
}

void update_ptr(struct IPv4* s) {
    sprintf(s->data, "update_ptr"); [span_10](start_span)//[span_10](end_span)
}

int main() {
    struct IPv4 s1 = {0}, s2 = {0}; [span_11](start_span)//[span_11](end_span)
    
    update_val(s1);
    update_ptr(&s2);
    
    printf("%s\n", s1.data);
    printf("%s\n", s2.data); [span_12](start_span)//[span_12](end_span)
    
    return 0;
}
