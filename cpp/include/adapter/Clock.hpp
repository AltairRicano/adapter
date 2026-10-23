#pragma once
#include <ctime>
#include <string>

namespace adapter {

// El módulo de pagos no tiene fecha; el adapter la obtiene de un reloj
// inyectable para poder probar sin depender del día real.
class Clock {
public:
    virtual ~Clock() = default;
    virtual std::string today() const = 0;  // "AAAA-MM-DD"
};

class SystemClock : public Clock {
public:
    std::string today() const override {
        std::time_t t = std::time(nullptr);
        char buf[11];
        std::strftime(buf, sizeof buf, "%Y-%m-%d", std::localtime(&t));
        return buf;
    }
};

class FixedClock : public Clock {
public:
    explicit FixedClock(std::string date) : date_(std::move(date)) {}
    std::string today() const override { return date_; }

private:
    std::string date_;
};

}  // namespace adapter
