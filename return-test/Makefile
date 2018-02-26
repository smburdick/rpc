all:
	rpcgen ret.x
	gcc -c -o ret_xdr.o ret_xdr.c
	echo "compiling client"
	gcc -c -o ret_clnt.o ret_clnt.c
	gcc -c -o ret.o ret.c
	gcc -o client ret.o ret_clnt.o ret_xdr.o
	echo "compiling server"
	gcc -c -o ret_svc.o ret_svc.c
	gcc -c -o ret_svc_proc.o ret_svc_proc.c
	gcc -o server ret_svc_proc.o ret_svc.o ret_xdr.o

clean:
	rm ret.h ret_svc.c ret_clnt.c ret_xdr.c client server *.o
