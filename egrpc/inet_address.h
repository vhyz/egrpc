#pragma once
#include <arpa/inet.h>
#include <memory>
#include <string>

namespace egrpc {

class InetAddress {
   public:
    InetAddress(){};

    bool SetByIpAndPort(const char* ip, uint16_t port);

    bool SetBySockaddr(const sockaddr_in& addr);

    static std::shared_ptr<InetAddress> CreateByIpAndPort(const char* ip, uint16_t port);

    static std::shared_ptr<InetAddress> CreateBySockaddr(const sockaddr_in& addr);

    const std::string& GetIp() const {
        return ip_;
    }

    uint16_t GetPort() const {
        return port_;
    }

    const sockaddr_in& GetSockAddr() const {
        return addr_;
    }

   private:
    sockaddr_in addr_;

    std::string ip_;

    uint16_t port_;
};

};  // namespace egrpc