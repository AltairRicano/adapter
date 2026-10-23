#include "payments/LegacyPaymentGateway.hpp"

namespace payments {

std::vector<Payment> LegacyPaymentGateway::fetchPayments() const {
    return {
        {"Ana Perez", 125050},
        {"Luis Gomez", 9999},
        {"Reembolso Ana", -2500},
        {"Marta Diaz", 40000},
    };
}

}  // namespace payments
