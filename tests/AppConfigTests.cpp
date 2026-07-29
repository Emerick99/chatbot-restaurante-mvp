#include "config/AppConfig.h"

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>

namespace {

void require(const bool condition, const std::string& message) {
    if (!condition) {
        throw std::runtime_error{message};
    }
}

void setEnvironment(const char* const name, const char* const value) {
#ifdef _WIN32
    if (_putenv_s(name, value) != 0) {
#else
    if (setenv(name, value, 1) != 0) {
#endif
        throw std::runtime_error{"No se pudo preparar el entorno de prueba"};
    }
}

void unsetEnvironment(const char* const name) {
#ifdef _WIN32
    if (_putenv_s(name, "") != 0) {
#else
    if (unsetenv(name) != 0) {
#endif
        throw std::runtime_error{"No se pudo limpiar el entorno de prueba"};
    }
}

void setValidEnvironment() {
    setEnvironment("BOT_TOKEN", "test-bot-secret");
    setEnvironment("ADMIN_USERNAME", "test-admin");
    setEnvironment("ADMIN_PASSWORD_HASH", "test-password-secret");
    setEnvironment("SESSION_SECRET", "test-session-secret");
    setEnvironment("DATABASE_PATH", "test.db");
    setEnvironment("APP_HOST", "127.0.0.1");
    setEnvironment("APP_PORT", "8080");
}

void requireSafeError(const std::string& message,
                      const std::string& variableName) {
    require(message.find(variableName) != std::string::npos,
            "El error no identifica la variable");
    require(message.find("test-bot-secret") == std::string::npos,
            "El error expone BOT_TOKEN");
    require(message.find("test-password-secret") == std::string::npos,
            "El error expone ADMIN_PASSWORD_HASH");
    require(message.find("test-session-secret") == std::string::npos,
            "El error expone SESSION_SECRET");
}

void testCompleteConfiguration() {
    setValidEnvironment();

    const auto config = restaurant::config::AppConfig::fromEnvironment();

    require(config.botToken == "test-bot-secret", "BOT_TOKEN incorrecto");
    require(config.adminUsername == "test-admin",
            "ADMIN_USERNAME incorrecto");
    require(config.adminPasswordHash == "test-password-secret",
            "ADMIN_PASSWORD_HASH incorrecto");
    require(config.sessionSecret == "test-session-secret",
            "SESSION_SECRET incorrecto");
    require(config.databasePath == "test.db", "DATABASE_PATH incorrecto");
    require(config.appHost == "127.0.0.1", "APP_HOST incorrecto");
    require(config.appPort == 8080, "APP_PORT incorrecto");
}

void testMissingVariable() {
    setValidEnvironment();
    unsetEnvironment("BOT_TOKEN");

    try {
        static_cast<void>(restaurant::config::AppConfig::fromEnvironment());
    } catch (const restaurant::config::ConfigError& error) {
        requireSafeError(error.what(), "BOT_TOKEN");
        return;
    }

    throw std::runtime_error{"BOT_TOKEN ausente no fue rechazado"};
}

void testInvalidPort(const char* const value) {
    setValidEnvironment();
    setEnvironment("APP_PORT", value);

    try {
        static_cast<void>(restaurant::config::AppConfig::fromEnvironment());
    } catch (const restaurant::config::ConfigError& error) {
        requireSafeError(error.what(), "APP_PORT");
        require(std::string{error.what()}.find(value) == std::string::npos,
                "El error expone el valor inválido de APP_PORT");
        return;
    }

    throw std::runtime_error{"APP_PORT inválido no fue rechazado"};
}

}  // namespace

int main() {
    try {
        testCompleteConfiguration();
        testMissingVariable();
        testInvalidPort("0");
        testInvalidPort("65536");
        testInvalidPort("invalid");
        std::cout << "AppConfigTests: OK\n";
        return 0;
    } catch (const std::exception& error) {
        std::cerr << "AppConfigTests: ERROR: " << error.what() << '\n';
        return 1;
    }
}
