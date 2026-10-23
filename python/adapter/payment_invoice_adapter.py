"""ADAPTER: implementa InvoiceSource delegando en LegacyPaymentGateway.

Traduce tres diferencias: centavos -> unidades, falta de fecha -> reloj
inyectable, y reembolsos (monto <= 0) que facturación no acepta -> se omiten.
"""
from datetime import date
from typing import Callable

from invoicing.invoice_source import Invoice, InvoiceSource
from payments.legacy_payment_gateway import LegacyPaymentGateway


class PaymentInvoiceAdapter(InvoiceSource):
    def __init__(self, gateway: LegacyPaymentGateway, clock: Callable[[], date] = date.today) -> None:
        self._gateway = gateway
        self._clock = clock

    def list_invoices(self) -> list[Invoice]:
        hoy = self._clock()
        return [
            Invoice(p.name, p.amount_cents / 100, hoy)
            for p in self._gateway.fetch_payments()
            if p.amount_cents > 0
        ]
