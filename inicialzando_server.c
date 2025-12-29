#include "config_servidor.h"
#include "confing_socket.h"
#include "inicialzando_server.h"

#define PORTA 8080 
#define BUFFER_SIZE 1024

void inicializandoServer() {

    int ativOpcao = 1;
    int maxConex = 2;
    ConfiguracaoServidor configRede = configuracaoTcpIpv4();  
    struct sockaddr_in endereco = ConfigurandoEnderecoIpv4(PORTA);
    
    // TODO(mudar): Esses dados virão do host cliente:
    char dados[BUFFER_SIZE] = {0};
    char* resposta = "teste servidor";

    int descritorSock = criarSockted(configRede); 

    configFechamentoPortSock(descritorSock, ativOpcao);

    associarIpAoSocket(descritorSock, endereco);

    escutarSocket(descritorSock, maxConex);

    int descritorCliente = conecatarCliente(descritorSock, endereco); 

    lerDadosCliente(descritorCliente, dados, BUFFER_SIZE);

    requestSocket(descritorCliente, resposta); 

    fecharSocket(descritorCliente); 
    fecharSocket(descritorSock); 

}

