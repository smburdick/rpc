#include "ret.h"

s *mod_s_1_svc( s* param, struct svc_req *req) {
    param->value++;
    return param;
}
