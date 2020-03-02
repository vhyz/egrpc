#include "inet_address.h"
#include <cstring>

namespace egrpc {

bool InetAddress::SetByIpAndPort(const char* ip, uint16_t port) {
    if (inet_pton(AF_INET, ip, &addr_.sin_addr) < 0) {
        return false;
    }
    memset(&addr_, 0, sizeof(addr_));
    addr_.sin_family = AF_INET;
    addr_.sin_port = htons(port);
    ip_ = ip;
    port_ = port;
    return true;
}

bool InetAddress::SetBySockaddr(const sockaddr_in& addr) {
    char ip_buf[INET_ADDRSTRLEN];
    if (inet_ntop(AF_INET, &addr.sin_addr, ip_buf, sizeof(ip_buf)) == nullptr) {
        return false;
    }
    ip_ = ip_buf;
    port_ = ntohs(addr.sin_port);
    return true;
}

std::shared_ptr<InetAddress> InetAddress::CreateByIpAndPort(const char* ip,
                                                            uint16_t port) {
    std::shared_ptr<InetAddress> ptr;
    bool ok = ptr->SetByIpAndPort(ip, port);
    if (!ok) {
        return nullptr;
    }
    return ptr;
}

std::shared_ptr<InetAddress> InetAddress::CreateBySockaddr(
    const sockaddr_in& addr) {
    std::shared_ptr<InetAddress> ptr;
    bool ok = ptr->SetBySockaddr(addr);
    if (!ok) {
        return nullptr;
    }
    return ptr;
}

}  // namespace egrpc