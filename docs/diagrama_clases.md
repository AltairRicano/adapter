# Diagrama de clases

Las clases de los módulos **no se modifican**; sólo el bloque *Adapter* es código nuevo.
Las firmas están en notación C++; la versión Python es equivalente (`snake_case`, `list`).

```mermaid
classDiagram
    direction LR

    class Payment {
        +string name
        +long amountCents
    }
    class LegacyPaymentGateway {
        +fetchPayments() vector~Payment~
    }

    class Invoice {
        +string name
        +double amount
        +string issuedOn
    }
    class InvoiceSource {
        <<interface>>
        +listInvoices() vector~Invoice~
    }
    class InvoiceReport {
        -InvoiceSource source
        +total() double
        +print(ostream)
    }

    class Clock {
        <<interface>>
        +today() string
    }
    class SystemClock {
        +today() string
    }
    class FixedClock {
        -string date
        +today() string
    }
    class PaymentInvoiceAdapter {
        -LegacyPaymentGateway gateway
        -Clock clock
        +listInvoices() vector~Invoice~
    }

    note for LegacyPaymentGateway "MÓDULO PAGOS: no se toca"
    note for InvoiceSource "MÓDULO FACTURACIÓN: no se toca"
    note for PaymentInvoiceAdapter "CÓDIGO NUEVO: el adapter"

    LegacyPaymentGateway ..> Payment : devuelve
    InvoiceSource ..> Invoice : devuelve
    InvoiceReport o--> InvoiceSource : usa (Client)
    PaymentInvoiceAdapter ..|> InvoiceSource : implementa (Target)
    PaymentInvoiceAdapter o--> LegacyPaymentGateway : envuelve (Adaptee)
    PaymentInvoiceAdapter o--> Clock : fecha
    SystemClock ..|> Clock
    FixedClock ..|> Clock
```

## Qué traduce el adapter

| Pagos (Adaptee)            | Facturación (Target)        | Traducción                          |
| :------------------------- | :-------------------------- | :---------------------------------- |
| `amountCents` (entero)     | `amount` (decimal, unidades) | `centavos / 100`                    |
| *(sin fecha)*              | `issuedOn` obligatoria      | se toma de un `Clock` inyectable    |
| reembolsos (monto `<= 0`)  | no existen                  | se omiten                           |
