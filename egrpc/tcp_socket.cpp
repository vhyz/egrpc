#include "tcp_socket.h"
#include <unistd.h>
#include "socket_util.h"

namespace egrpc {

TcpSocket::~TcpSocket() {
    close(socket_fd_);
}

bool TcpSocket::SetNoDelay() {
    int ret = SocketUtil::SetNoDelay(socket_fd_);
    return ret == 0;
}

ssize_t TcpSocket::Read(void* buf, size_t size) {
    ssize_t ret = read(socket_fd_, buf, size);
    return ret;
}

ssize_t TcpSocket::Write(const void* buf, size_t size) {
    ssize_t ret = write(socket_fd_, buf, size);
    return ret;
}

ssize_t TcpSocket::ReadUntilNBytes(const char* buf, size_t size) {}

};  // namespace egrpc