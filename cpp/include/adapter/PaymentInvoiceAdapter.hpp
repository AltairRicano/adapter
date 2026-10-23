#pragma once
#include "adapter/Clock.hpp"
#include "invoicing/InvoiceSource.hpp"
#include "payments/LegacyPaymentGateway.hpp"

namespace adapter {

// ADAPTER: implementa la interfaz que pide facturación (InvoiceSource)
// delegando en el módulo de pagos heredado (LegacyPaymentGateway).
// Traduce tres diferencias: centavos -> unidades, falta de fecha -> reloj,
// y reembolsos (monto <= 0) que facturación no acepta -> se omiten.
class PaymentInvoiceAdapter : public invoicing::InvoiceSource {
public:
    PaymentInvoiceAdapter(const payments::LegacyPaymentGateway& gateway, const Clock& clock)
        : gateway_(gateway), clock_(clock) {}

    std::vector<invoicing::Invoice> listInvoices() const override {
        std::vector<invoicing::Invoice> out;
        const std::string date = clock_.today();
        for (const auto& p : gateway_.fetchPayments()) {
            if (p.amountCents <= 0) continue;
            out.push_back({p.name, p.amountCents / 100.0, date});
        }
        return out;
    }

private:
    const payments::LegacyPaymentGateway& gateway_;
    const Clock& clock_;
};

}  // namespace adapter
