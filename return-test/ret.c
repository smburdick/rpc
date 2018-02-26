#include <stdio.h>
#include <stdlib.h>

#include "ret.h"

int main(void)
{
    CLIENT *clnt;
    clnt = clnt_create("10.250.94.63", MOD_STRUCT, MOD_STRUCT_V1, "tcp");
    s *param = (s*) malloc(sizeof(s));
    param->value = 0;
    if (clnt == NULL) {
        printf("error: could not connect to server.\n");
        return 1;
    }
    printf("value = %d\n", param->value);
    param = mod_s_1(param, clnt);
    printf("value is now %d\n", param->value);
    //param = mod_struct_1(param, clnt);
    //printf("Value = %d\n", param->value);
    return 0;
}
