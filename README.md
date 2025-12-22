### 1. Objetovo do Projeto

> Desenvolver um chat de comunicação simples entre dois clientes. A comunicação entre eles será realizada por meio de sockets de rede, utilizando o protocolo TCP para o transporte de dados. Este projeto tem como objetivo compreender, na prática, os conceitos de cliente e servidor, sockets de rede e o funcionamento do protocolo TCP.

- **Tecnologias:** socket, TCP, C, postgreSQL, cliente servidor. 
---

### 2. Requisitos Projeto

| **Requisitos Funcionais** | **Requisitos Não Funcionais** |
|---------------------------|-------------------------------|
| Permitir o envio de mensagens via terminal para um host remoto | As mensagens devem ser entregues na ordem correta (sequencialmente) |
| Armazenar o histórico completo das mensagens enviadas e recebidas | O sistema deve garantir baixa latência no envio das mensagens |
| Exibir o status do usuário (conectado ou desconectado) | O sistema deve ser confiável e evitar perda de mensagens |
| Permitir a identificação do remetente das mensagens | A interface via terminal deve ser simples e intuitiva |
| Possibilitar a leitura do histórico ao iniciar a aplicação | |
|Permitir que o usuario coloque um nickename| |
| Implementar comandos no terminal (ex: `/sair`, `/usuarios`) ||
|Permitir limpar o histórico de mensagens | | 

---
### Arquitetura