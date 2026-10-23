#pragma once
#include <vector>

#include "invoicing/Invoice.hpp"

namespace invoicing {

// Target: la interfaz que espera el cliente de facturación.
class InvoiceSource {
public:
    virtual ~InvoiceSource() = default;
    virtual std::vector<Invoice> listInvoices() const = 0;
};

}  // namespace invoicing
