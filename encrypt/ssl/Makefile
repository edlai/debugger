all:
	gcc -Wall ssl_server.c -o ssl_server -levent -lpthread -lssl -lcrypto -levent_openssl
	#gcc -Wall ssl_client.c -o ssl_client -levent -levhtp -lpthread -lssl -lcrypto -levent_openssl

clean:
	rm ssl_client ssl_server
