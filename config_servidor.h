#ifndef CONFIG_SERVIDOR_H
#define CONFIG_SERVIDOR_H

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

typedef struct
{
    int rede;
    int tipoComunicacao;
    int protocolo; 
} ConfiguracaoServidor;

ConfiguracaoServidor configuracaoTcpIpv4(void); 
struct sockaddr_in ConfigurandoEnderecoIpv4(uint16_t);

#endif
