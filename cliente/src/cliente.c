#include <stdlib.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024


int criar_sockt() {
    int descritor_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);   

    if (descritor_socket < 0) {
        perror("Erro ao criar o socket");
        exit(EXIT_FAILURE);
    }
    return descritor_socket;
}

struct sockaddr_in config_endereco_servidor() {

    struct sockaddr_in server_config;
    const char* host = "127.0.0.1";

    server_config.sin_port = htons(PORT);
    server_config.sin_family = AF_INET;
    
    if (inet_pton(AF_INET,host, &server_config.sin_addr) < 0) {
        perror("Erro configurar IP");
        exit(EXIT_FAILURE);
    }

    return server_config;
}

int conectar_servidor (int descritor_socket, struct sockaddr_in config_server) {
    int status = connect(descritor_socket, (struct sockaddr*) &config_server, sizeof(config_server));

    if (status < 0) {
        perror("Erro ao estabelexer conexão com o servidor");
        exit(EXIT_FAILURE);
    }

    printf("Conectado ao servidor");
    return status;
}

void envio_mensagem(int descritor_sock, char* mensagem) {
    size_t dados_enviados = send(descritor_sock, mensagem, strlen(mensagem), 0);

    if (dados_enviados < 1) {
        perror ("Não foi possível enviar a mensagem!");
        exit(EXIT_FAILURE);
    }
}

// TODO: tratar erros: 
void receber_resposta(int descritor_sock) {
    char buffer[BUFFER_SIZE];
    size_t resposta = read(descritor_sock, buffer ,BUFFER_SIZE);
    buffer[BUFFER_SIZE] = '\0';
    printf("%s", buffer);
}

int main() {

    char mensagem[50]; 

    int descrito_sock = criar_sockt();
    struct sockaddr_in status_servidor = config_endereco_servidor(); 
    conectar_servidor(descrito_sock, status_servidor);
    
    int contador = 0; 
    while (1)
    {
        scanf("%49s", &mensagem);
        envio_mensagem(descrito_sock, mensagem);
        receber_resposta(descrito_sock);
    }


    close(descrito_sock);
    printf("Conexão encerrada\n");
    
    return 0;
}

