#pragma once
#include <string>
#include <vector>

// MÓDULO 1 (Adaptee, no se modifica): sistema de pagos heredado.
// Sólo conoce nombre y monto, y el monto viene en CENTAVOS enteros.
namespace payments {

struct Payment {
    std::string name;
    long amountCents;  // negativo = reembolso
};

class LegacyPaymentGateway {
public:
    std::vector<Payment> fetchPayments() const;
};

}  // namespace payments
