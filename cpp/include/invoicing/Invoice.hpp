#pragma once
#include <string>

// MÓDULO 2 (no se modifica): facturación moderna.
// Exige nombre, monto en unidades (double) y fecha de elaboración "AAAA-MM-DD".
namespace invoicing {

struct Invoice {
    std::string name;
    double amount;
    std::string issuedOn;
};

}  // namespace invoicing
