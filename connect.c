#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>

int __wrap_connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
    return __connect(sockfd, addr, addrlen);
}

int function_in_so_which_calls_connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
  connect(sockfd, addr, addrlen);
}
