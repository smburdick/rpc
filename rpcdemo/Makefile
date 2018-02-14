.SUFFIXES:
.SUFFIXES: .c .o
CLNT = llist
SRVR = llist_svc
CFLAGS = -g -Wall

SRVR_OBJ = llist_svc_proc.o llist_xdr.o llist_svc.o
CLNT_OBJ = llist.o llist_xdr.o llist_clnt.o
RPC_GEN_FILES = llist.h llist.o llist_clnt.c llist_svc.c llist_xdr.c

.c.o:; gcc -c -o $@ $(CFLAGS) $<

default: RPC_GEN_FILES $(CLNT) $(SRVR)

RPC_GEN_FILES:
	rpcgen llist.x

$(CLNT): $(CLNT_OBJ) llist.h
	gcc -o $(CLNT) $(CLNT_OBJ)

$(SRVR): $(SRVR_OBJ) llist.h
	gcc -o $(SRVR) $(SRVR_OBJ)

clean:
	rm $(RPC_GEN_FILES)
	rm *.o $(CLNT) $(SRVR)
	rm -i *~
	rm core
