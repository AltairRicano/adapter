#include <cassert>
#include <cmath>
#include <iostream>

#include "adapter/Clock.hpp"
#include "adapter/PaymentInvoiceAdapter.hpp"
#include "invoicing/InvoiceReport.hpp"
#include "payments/LegacyPaymentGateway.hpp"

using namespace adapter;


static void convierteCentavosAUnidades() {
    payments::LegacyPaymentGateway gw;
    FixedClock clock("2026-01-15");
    PaymentInvoiceAdapter a(gw, clock);
    auto inv = a.listInvoices();
    assert(inv[0].name == "Ana Perez");
    assert(std::fabs(inv[0].amount - 1250.50) < 1e-9);
}

static void agregaLaFechaDelReloj() {
    payments::LegacyPaymentGateway gw;
    FixedClock clock("2026-01-15");
    PaymentInvoiceAdapter a(gw, clock);
    for (const auto& i : a.listInvoices()) assert(i.issuedOn == "2026-01-15");
}

static void omiteReembolsos() {
    payments::LegacyPaymentGateway gw;
    FixedClock clock("2026-01-15");
    PaymentInvoiceAdapter a(gw, clock);
    assert(a.listInvoices().size() == 3);  // 4 pagos, 1 reembolso
}

static void funcionaComoClienteDeFacturacion() {
    payments::LegacyPaymentGateway gw;
    FixedClock clock("2026-01-15");
    PaymentInvoiceAdapter a(gw, clock);
    invoicing::InvoiceReport report(a);
    assert(std::fabs(report.total() - (1250.50 + 99.99 + 400.00)) < 1e-6);
}

int main() {
    convierteCentavosAUnidades();
    agregaLaFechaDelReloj();
    omiteReembolsos();
    funcionaComoClienteDeFacturacion();
    std::cout << "OK: 4 pruebas\n";
}
