#include <stdio.h>

struct access_rights {
    unsigned char execute : 1;
    unsigned char write : 1;
    unsigned char read : 1;
}; [span_21](start_span)//[span_21](end_span)

union file_access_rights {
    unsigned int int_value;
    struct access_rights rights;
}; [span_22](start_span)//[span_22](end_span)

int main() {
    union file_access_rights some_file = {0};
    
    some_file.rights.read = 1;
    some_file.rights.write = 0;
    some_file.rights.execute = 1; [span_23](start_span)//[span_23](end_span)
    
    printf("current mode: %u\n", some_file.int_value); [span_24](start_span)//[span_24](end_span)
    
    return 0;
}
