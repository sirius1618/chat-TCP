#ifndef INICIALIZANDO_SERVIDOR_H
#define INICIALIZANDO_SERVIDOR_H

#include "config_servidor.h"
#include "config_servidor.h"

#define PORTA 8080
#define BUFFER_SIZE 1024

int setupServidor(int porta, int maxConex, struct sockaddr_in *endereco);
void loopConecao(int descritorCliente);
void initServidor(int porta, int maxConex);
#endif