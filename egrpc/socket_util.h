#pragma once
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/fcntl.h>
#include <sys/socket.h>
#include <sys/types.h>

namespace egrpc {
class SocketUtil {
   public:
    static int CreateTcpSocketFd() {
        int fd = socket(AF_INET, SOCK_STREAM, 0);
        return fd;
    }

    static int SetNonBlock(int fd) {
        int flags = fcntl(fd, F_GETFL);
        return fcntl(fd, F_SETFL, flags | O_NONBLOCK);
    }

    static int SetReuseAddr(int fd) {
        int on = 1;
        return setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
    }

    static int SetReusePort(int fd) {
        int on = 1;
        return setsockopt(fd, SOL_SOCKET, SO_REUSEPORT, &on, sizeof(on));
    }

    static int SetNoDelay(int fd) {
        int on = 1;
        return setsockopt(fd, IPPROTO_TCP, TCP_NODELAY, &on, sizeof(on));
    }
};
};  // namespace egrpc