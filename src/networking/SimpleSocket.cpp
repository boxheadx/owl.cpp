#include "../networking/SimpleSocket.hpp"

owl::SimpleSocket::SimpleSocket(int domain,int service, int protocol,int port,u_long interface){

    sock = socket(domain,service,protocol);
    test_connection(sock);

    address.sin_family=domain;
    address.sin_port=port;
    address.sin_addr.s_addr=htonl(interface);

    connection=establish_connection(sock,address);
    test_connection(connection);
}

void owl::SimpleSocket::test_connection(int c){
    if(c < 0){
        perror("Connection failed...\n");
        exit(EXIT_FAILURE);
    }
}

inline struct sockaddr_in owl::SimpleSocket::get_address(){
    return address;
}

inline int owl::SimpleSocket::get_connection(){
    return connection;
}

inline int owl::SimpleSocket::get_sock(){
    return sock;
}