/*------------------------------------------------------------------------------
 * socket_lib.h
 * 
 * author   : Guangli Dong
 *
 * history  : 2016/07/07 new
 *
 *----------------------------------------------------------------------------*/

/* ----------------------------------------------------------------------------/
 | usage - server:
 |
 | 1. creat server socket
 |      socket_t servfd = creat_server_socket("192.168.3.212", 40001);
 |
 | 2. accept request from client using standard socket fuction
 |      socket_t clntfd = accept(servfd, (struct sockaddr*)NULL, NULL);
 |
 | 3. send and recv operations using standard socket function
 |      n = send(sockfd, sendline, stren(sendline), 0);
 |      n = recv(clntfd, recvline, RECVSIZE, 0);
 |
 | 4. close connected client socket
 |      closesocket(clntfd);
 |
 | 5. close server socket
 |      closesocket(servfd);
 |
 |
 | usage - client:
 |
 | 1. creat client socket
 |      socket_t clntfd = creat_client_socket("192.168.3.212", 40001);
 |
 | 2. send and recv operations using standard socket function
 |      n = send(clntfd, sendline, stren(sendline), 0);
 |      n = recv(clntfd, recvline, RECVSIZE, 0);
 |
 | 3. close client socket
 |      closesocket(clntfd);
 |
 *----------------------------------------------------------------------------*/

#ifndef WINDOWS_SOCKET_H
#define WINDOWS_SOCKET_H

/* includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#ifdef WIN32
#include <WinSock2.h>
#pragma comment (lib, "ws2_32.lib")
#endif

/* macros --------------------------------------------------------------------*/
#ifdef WIN32
#define socket_t    SOCKET
#else
#define socket_t    int
#define closesocket close
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* extern functions ----------------------------------------------------------*/
extern socket_t creat_server_socket(const char *IP, int PORT);
extern socket_t creat_client_socket(const char *IP, int PORT);

#ifdef __cplusplus
}
#endif

#endif // WINDOWS_SOCKET_H