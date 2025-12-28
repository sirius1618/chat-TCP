#include "config_servidor.h"
#include "confing_socket.h"
#include "inicialzando_server.h"

#define PORTA 8080 

int inicializandoServer(int descritorSock) {

    int ativOpcao = 1;
    int maxConex = 2;
    ConfiguracaoServidor configRede;  
    struct sockaddr_in endereco = ConfigurandoEnderecoIpv4(PORTA);
    
    // TODO(mudar): Esses dados virão do host cliente:
    size_t tamanho = 1024;
    char dados[tamanho] = {0};
    char* resposta = "teste servidor";

    int descritorSock = descriarSockted(configRede); 

    configFechamentoPortSock(descritorSock, ativOpcao);

    associarIpAoSocket(descritorSock, endereco);

    escutarSocket(descritorSock, maxConex);

    int descritorCliente = conecatarCliente(descritorSock, endereco); 

    lerDadosCliente(descritorCliente, dados, tamanho);

    requestSocket(descritorCliente, resposta); 

    fecharSocket(descritorCliente); 
    fecharSocket(descritorSock); 

}

