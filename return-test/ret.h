/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _RET_H_RPCGEN
#define _RET_H_RPCGEN

#define RPCGEN_VERSION	199506

#include <rpc/rpc.h>


struct s {
	int value;
};
typedef struct s s;
#ifdef __cplusplus
extern "C" bool_t xdr_s(XDR *, s*);
#elif __STDC__
extern  bool_t xdr_s(XDR *, s*);
#else /* Old Style C */
bool_t xdr_s();
#endif /* Old Style C */


#define MOD_STRUCT ((rpc_uint)0x2fffffff)
#define MOD_STRUCT_V1 ((rpc_uint)1)

#ifdef __cplusplus
#define MOD_S ((rpc_uint)1)
extern "C" s * mod_s_1(s *, CLIENT *);
extern "C" s * mod_s_1_svc(s *, struct svc_req *);

#elif __STDC__
#define MOD_S ((rpc_uint)1)
extern  s * mod_s_1(s *, CLIENT *);
extern  s * mod_s_1_svc(s *, struct svc_req *);

#else /* Old Style C */
#define MOD_S ((rpc_uint)1)
extern  s * mod_s_1();
extern  s * mod_s_1_svc();
#endif /* Old Style C */

#endif /* !_RET_H_RPCGEN */
