all:
	rpcgen msg.x
	gcc -v rprintmsg.c msg_clnt.c -o rprintmsg -lnsl
	gcc -v msg_proc.c msg_svc.c -o msg_server -lnsl

clean:
	rm rprintmsg msg_server
