#include <sys/socket.h> 
#include <arpa/inet.h>
#include <netinet/in.h>

typedef struct 
{
    int rede;
    int tipoComunicacao;
    int protocolo; 
} ConfiguracaoServidor;

ConfiguracaoServidor configuracaoTcpIpv4() {
    ConfiguracaoServidor config;
    config.rede = AF_INET;
    config.tipoComunicacao = SOCK_STREAM;
    config.protocolo = 0; 

    return config;
}

struct sockaddr_in ConfigurandoEnderecoIpv4(uint16_t porta) {
    struct sockaddr_in endereco;

    endereco.sin_family = AF_INET;
    endereco.sin_addr.s_addr = INADDR_ANY;
    endereco.sin_port = htons(porta);
    
    return endereco;
}