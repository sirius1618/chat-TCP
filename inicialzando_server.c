#include "config_servidor.h"
#include "confing_socket.h"
#include "inicialzando_server.h"

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024 

int setupServidor(int porta, int maxConex, struct sockaddr_in *endereco) {

    int ativOpcao = 1; // 1 = sim , 0 = não
    ConfiguracaoServidor configRede = configuracaoTcpIpv4();  
    endereco = ConfigurandoEnderecoIpv4(porta);
    int descritorSock = criarSockted(configRede); 

    configFechamentoPortSock(descritorSock, ativOpcao);
    associarIpAoSocket(descritorSock, *endereco);
    
    return descritorSock;
}

void loopConecao(int descritorCliente) {
    char dadosCliente[BUFFER_SIZE] = {0};
    char *response = "Conexão com o servidor encerrada";

    while (dadosCliente != "!q"){ 
        lerDadosCliente(descritorCliente, dadosCliente, BUFFER_SIZE);
        printf("%s", dadosCliente);
    }

    requestSocket(descritorCliente, response); 
    fecharSocket(descritorCliente); 
}

void initServidor(int porta, int maxConex) {
    struct sockaddr_in *endereco;
    int descritorSock = setupServidor(porta, maxConex, endereco);
    escutarSocket(descritorSock, maxConex);
    int descritorCliente = conecatarCliente(descritorSock, *endereco); 

    loopConecao(descritorCliente);

    fecharSocket(descritorSock); 
}
