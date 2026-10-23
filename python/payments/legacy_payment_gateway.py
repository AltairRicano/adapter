"""MÓDULO 1 (Adaptee, no se modifica): sistema de pagos heredado.

Sólo conoce nombre y monto, y el monto viene en CENTAVOS enteros.
"""
from dataclasses import dataclass


@dataclass
class Payment:
    name: str
    amount_cents: int  # negativo = reembolso


class LegacyPaymentGateway:
    def fetch_payments(self) -> list[Payment]:
        return [
            Payment("Ana Perez", 125050),
            Payment("Luis Gomez", 9999),
            Payment("Reembolso Ana", -2500),
            Payment("Marta Diaz", 40000),
        ]
