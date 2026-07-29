#include "AppConfig.h"

#include <algorithm>
#include <charconv>
#include <cctype>
#include <cstdlib>
#include <limits>
#include <string_view>
#include <system_error>

namespace restaurant::config {
namespace {

[[nodiscard]] bool isBlank(const std::string_view value) {
    return std::all_of(
        value.begin(),
        value.end(),
        [](const char character) {
            return std::isspace(static_cast<unsigned char>(character)) != 0;
        });
}

[[nodiscard]] std::string requireEnvironment(const char* const name) {
    const char* const rawValue = std::getenv(name);

    if (rawValue == nullptr || isBlank(rawValue)) {
        throw ConfigError{"Variable de entorno obligatoria ausente o vacía: " +
                          std::string{name}};
    }

    return rawValue;
}

[[nodiscard]] std::uint16_t parsePort(const std::string& value) {
    unsigned int port = 0;
    const char* const begin = value.data();
    const char* const end = begin + value.size();
    const auto [position, error] = std::from_chars(begin, end, port);

    if (error != std::errc{} || position != end || port == 0 ||
        port > std::numeric_limits<std::uint16_t>::max()) {
        throw ConfigError{"Variable de entorno inválida: APP_PORT"};
    }

    return static_cast<std::uint16_t>(port);
}

}  // namespace

AppConfig AppConfig::fromEnvironment() {
    const std::string botToken = requireEnvironment("BOT_TOKEN");
    const std::string adminUsername = requireEnvironment("ADMIN_USERNAME");
    const std::string adminPasswordHash =
        requireEnvironment("ADMIN_PASSWORD_HASH");
    const std::string sessionSecret = requireEnvironment("SESSION_SECRET");
    const std::string databasePath = requireEnvironment("DATABASE_PATH");
    const std::string appHost = requireEnvironment("APP_HOST");
    const std::uint16_t appPort =
        parsePort(requireEnvironment("APP_PORT"));

    return {
        botToken,
        adminUsername,
        adminPasswordHash,
        sessionSecret,
        databasePath,
        appHost,
        appPort,
    };
}

}  // namespace restaurant::config
