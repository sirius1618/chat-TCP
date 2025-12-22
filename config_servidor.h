#ifndef CONFIG_SERVIDOR_H
#define CONFIG_SERVIDOR_H

#include <sys/socket.h>

typedef struct
{
    int rede;
    int tipoComunicacao;
    int protocolo; 
} ConfiguracaoServidor;

ConfiguracaoServidor configuracaoTcpIpv4(void); 

#endif
