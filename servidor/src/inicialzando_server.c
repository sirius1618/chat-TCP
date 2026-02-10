#include "config_servidor.h"
#include "confing_socket.h"
#include "inicialzando_server.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <unistd.h>

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

int identificar_escrita(int descritor) {
    fd_set fila_descritores;
    FD_ZERO(&fila_descritores);

    struct timeval tm;
    tm.tv_sec = 0;
    tm.tv_usec = 1000;

    FD_SET(descritor, &fila_descritores);

    int monitorando  = select(descritor + 1, &fila_descritores, NULL, NULL, &tm);

    return (monitorando > 0); 

}

void loopConecao(int descritorCliente) {
    char dadosCliente[BUFFER_SIZE];
    int bytesLidos;
    char msg_servidor[50];

    while (1) {  
        
        if (identificar_escrita(descritorCliente) > 0) {

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

        if (identificar_escrita(0)) {
            fgets(msg_servidor, sizeof(msg_servidor), stdin);
            requestSocket(descritorCliente, msg_servidor); 
        }

    }

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
