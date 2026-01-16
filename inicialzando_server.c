#include "config_servidor.h"
#include "confing_socket.h"
#include "inicialzando_server.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024 

int setupServidor(int porta, struct sockaddr_in *endereco) {

    int ativOpcao = 1; // 1 = sim , 0 = não
    ConfiguracaoServidor configRede = configuracaoTcpIpv4();  
    *endereco = ConfigurandoEnderecoIpv4(porta);
    int descritorSock = criarSockted(configRede); 

    configFechamentoPortSock(descritorSock, ativOpcao);
    associarIpAoSocket(descritorSock, *endereco);
    
    return descritorSock;
}

void loopConecao(int descritorCliente) {
    char dadosCliente[BUFFER_SIZE];
    int bytesLidos;
    char *response = "saiu do servidor o host:\n"; 

    while (1) {  
        memset(dadosCliente, 0, BUFFER_SIZE);
        bytesLidos = lerDadosCliente(descritorCliente, dadosCliente, BUFFER_SIZE -1);
        
        if (bytesLidos <= 0) break; 

        dadosCliente[bytesLidos] = '\0';        

        size_t len = strlen(dadosCliente);

        if (len > 0 && dadosCliente[len -1] == '\n') {
            dadosCliente[len -1] = '\0';
        }
        
        if (strcmp(dadosCliente, "!q") == 0) {
         break;               
        }

        printf("%s\n", dadosCliente);
    }

    requestSocket(descritorCliente, response); 
    fecharSocket(descritorCliente); 
}

void initServidor(int porta, int maxConex) {
    struct sockaddr_in endereco;
    int descritorSock = setupServidor(porta, &endereco);
    escutarSocket(descritorSock, maxConex);
    int descritorCliente = conecatarCliente(descritorSock, endereco); 

    loopConecao(descritorCliente);

    fecharSocket(descritorSock); 
}
