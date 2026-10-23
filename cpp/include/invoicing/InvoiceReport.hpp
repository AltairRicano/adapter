#pragma once
#include <iomanip>
#include <ostream>

#include "invoicing/InvoiceSource.hpp"

namespace invoicing {

// Client: sólo depende de InvoiceSource, nunca del módulo de pagos.
class InvoiceReport {
public:
    explicit InvoiceReport(const InvoiceSource& source) : source_(source) {}

    double total() const {
        double sum = 0;
        for (const auto& inv : source_.listInvoices()) sum += inv.amount;
        return sum;
    }

    void print(std::ostream& out) const {
        out << std::fixed << std::setprecision(2);
        for (const auto& inv : source_.listInvoices())
            out << inv.issuedOn << "  " << inv.name << "  " << inv.amount << "\n";
        out << "TOTAL: " << total() << "\n";
    }

private:
    const InvoiceSource& source_;
};

}  // namespace invoicing
