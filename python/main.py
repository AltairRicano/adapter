from adapter.payment_invoice_adapter import PaymentInvoiceAdapter
from invoicing.invoice_source import InvoiceReport
from payments.legacy_payment_gateway import LegacyPaymentGateway

# El cliente sólo ve InvoiceSource; no sabe que detrás hay pagos heredados.
print(InvoiceReport(PaymentInvoiceAdapter(LegacyPaymentGateway())).render())
