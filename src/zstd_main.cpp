#include "zstd-proxy.h"
#include <memory>
#include <thread>

int main(int argc, char **argv) {
    auto proxy = std::make_unique<zstd_proxy>();
    zstd_proxy_init(proxy.get());

    char *endptr;
    proxy->listen.fd = (int) std::strtol(argv[1], &endptr, 10);
    proxy->connect.fd = (int) std::strtol(argv[2], &endptr, 10);

    std::thread t(zstd_proxy_run, proxy.get());
    t.join();
}

