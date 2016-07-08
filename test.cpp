/*------------------------------------------------------------------------------
 * test.cpp : for socket functions testing.
 * 
 * author   : Guangli Dong
 *
 * history  : 2016/07/07 new
 *
 *----------------------------------------------------------------------------*/

#include "socket_lib.h"

int main(int argc, char *argv[])
{
    int sockfd;
    int recvnum, i;
    unsigned char buff[4096];
    FILE *output;

    /* set for SiNan data stream */
    sockfd = creat_client_socket("192.168.3.212", 40001);
    
    /* set output file */
    output = fopen("log.bin", "wb");

    if(sockfd <0 ) {
        printf("error\n");
        exit(0);
    }

    while(1) {
        recvnum = 0;
        memset(buff, 0x00, sizeof(buff));
        recvnum = recv(sockfd, (char *)buff, 4000, 0);
#ifdef WIN32
        Sleep(1000);
#endif
        for(i = 0; i<recvnum; i++) {
            fwrite(&(buff[i]), 1, 1, output);
#if 1
            if((i%16) == 0) printf("\n");
            printf("%02X ", buff[i]);
#endif
#if 0
            printf("%c", buff[i]);
#endif
        }
    }

    fclose(output);
    close_client_socket(sockfd);


    return 0;
}
