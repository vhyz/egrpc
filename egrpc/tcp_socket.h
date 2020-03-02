#pragma once
#include "inet_address.h"
#include "noncopyable.hpp"
#include "socket_util.h"

namespace egrpc {

class TcpSocket : public noncopyable {
   public:
    TcpSocket(int socket_fd, std::shared_ptr<InetAddress> local,
              std::shared_ptr<InetAddress> remote)
        : socket_fd_(socket_fd), local_(local), remote_(remote) {}

    ~TcpSocket();

    bool SetNoDelay();

    ssize_t Read(void* buf, size_t size);

    ssize_t Write(const void* buf, size_t size);

    ssize_t ReadUntilNBytes(const char* buf, size_t size);

   private:
    int socket_fd_;

    std::shared_ptr<InetAddress> local_;

    std::shared_ptr<InetAddress> remote_;
};

};  // namespace egrpc