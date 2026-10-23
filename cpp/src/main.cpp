#include <iostream>

#include "adapter/PaymentInvoiceAdapter.hpp"
#include "invoicing/InvoiceReport.hpp"

int main() {
    payments::LegacyPaymentGateway gateway;
    adapter::SystemClock clock;
    adapter::PaymentInvoiceAdapter adapter(gateway, clock);

    // El cliente sólo ve InvoiceSource; no sabe que detrás hay pagos heredados.
    invoicing::InvoiceReport report(adapter);
    report.print(std::cout);
}
