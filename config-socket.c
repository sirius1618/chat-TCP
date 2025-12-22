
#include <sys/socket.h> 
#include <stdlib.h>

// TODO ver a diferença entre as duas bibliotecas de manipulação de rede:
// #include <arpa/inet.h>
#include <netinet/in.h>

#include "config_servidor.h"

int criarSockted(int descritoSock, ConfiguracaoServidor config) {
    descritoSock = socket(config.rede, config.tipoComunicacao, config.protocolo); 

    if (descritoSock < 0) {
        perror("Erro ao criar socket!");
        return -1;
    }

    return descritoSock; 
}

int configFechamentoPortSock(int descritorSock, int opt) {
    int confPort = setsockopt(descritorSock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));
    
    if (confPort < 0) {
        perror("Falha ao configurar como se dara o fechamento de portas quando se usa socket");
        return -1;
    }

    return 0;
}

int associarIpAoSocket(int descritorSock, struct sockaddr_in endereco) {
    int ipAssociado = bind(descritorSock, (struct sockaddr*) &endereco, sizeof(endereco));

    if (ipAssociado < 0) {
        perror("Falha ao associar IP ao socket");
        return -1;
    }

    return 0; 
}

void  escutarSocket(int descritorSock, int maxConexoa) {
    int escuta = listen(descritorSock, maxConexoa);

    if (escuta < 0) {
        perror("Falha ao escutar cliente");
        exit(EXIT_FAILURE); 
    }
}

int conecatarCliente(int descritorSock, struct sockaddr_in endereco) {
    int descSockTemp = accept(descritorSock, (struct sockaddr*) &endereco, sizeof(endereco));

    if (descSockTemp < 0) {
        perror("Erro ao conectar cliente");
        return -1;
    }

    return 0; 
}

// TODO: verificar como definir o tamanho dos dados que o cliente pode mandar.  
int lerDadosCliente(int descSock, char dados[1014]) {
    return read(descSock, dados, 1014 -1); 
}

int requestSocket(int descSock, char* resposta) {
    return send(descSock, resposta, strlen(resposta), 0); 
}

void fecharSocket(int descSock) {
    close(descSock); 
}