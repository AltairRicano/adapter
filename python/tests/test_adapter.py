import unittest
from datetime import date

from adapter.payment_invoice_adapter import PaymentInvoiceAdapter
from invoicing.invoice_source import InvoiceReport
from payments.legacy_payment_gateway import LegacyPaymentGateway

HOY = date(2026, 1, 15)


def crear_adapter():
    return PaymentInvoiceAdapter(LegacyPaymentGateway(), clock=lambda: HOY)


class TestPaymentInvoiceAdapter(unittest.TestCase):
    def test_convierte_centavos_a_unidades(self):
        primera = crear_adapter().list_invoices()[0]
        self.assertEqual(primera.name, "Ana Perez")
        self.assertAlmostEqual(primera.amount, 1250.50)

    def test_agrega_la_fecha_del_reloj(self):
        for inv in crear_adapter().list_invoices():
            self.assertEqual(inv.issued_on, HOY)

    def test_omite_reembolsos(self):
        self.assertEqual(len(crear_adapter().list_invoices()), 3)

    def test_funciona_como_cliente_de_facturacion(self):
        self.assertAlmostEqual(InvoiceReport(crear_adapter()).total(), 1750.49)


if __name__ == "__main__":
    unittest.main()
