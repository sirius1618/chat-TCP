#ifndef CONFIG_SOCKET_H
#define CONFIG_SOCKET_H

#include "config_servidor.h"
#include <netinet/in.h>

int criarSockted(int , ConfiguracaoServidor);

int configFechamentoPortSock(int ,int);

int associarIpAoSocket(int, struct sockaddr_in);

void  escutarSocket(int, int);

int conecatarCliente(int, struct sockaddr_in);

int lerDadosCliente(int, char*, size_t);

int requestSocket(int, char*);

void fecharSocket(int); 

#endif