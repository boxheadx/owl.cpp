#pragma once

#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <iostream>

namespace owl{
    class SimpleSocket{
        
        int sock,connection;
        struct sockaddr_in address;

        public:
            SimpleSocket(int domain,int service,int protocol,int port,u_long interface);
            virtual int establish_connection(int sock, struct sockaddr_in address) = 0;
            void test_connection(int);
            struct sockaddr_in get_address();
            int get_sock();
            int get_connection();
    };
}