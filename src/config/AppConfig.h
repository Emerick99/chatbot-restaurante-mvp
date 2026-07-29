#ifndef RESTAURANT_CONFIG_APP_CONFIG_H
#define RESTAURANT_CONFIG_APP_CONFIG_H

#include <cstdint>
#include <stdexcept>
#include <string>

namespace restaurant::config {

class ConfigError : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

struct AppConfig {
    std::string botToken;
    std::string adminUsername;
    std::string adminPasswordHash;
    std::string sessionSecret;
    std::string databasePath;
    std::string appHost;
    std::uint16_t appPort;

    [[nodiscard]] static AppConfig fromEnvironment();
};

}  // namespace restaurant::config

#endif
