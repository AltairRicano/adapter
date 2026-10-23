"""MÓDULO 2 (no se modifica): facturación moderna.

Exige nombre, monto en unidades (float) y fecha de elaboración.
"""
from abc import ABC, abstractmethod
from dataclasses import dataclass
from datetime import date


@dataclass
class Invoice:
    name: str
    amount: float
    issued_on: date


class InvoiceSource(ABC):
    """Target: la interfaz que espera el cliente de facturación."""

    @abstractmethod
    def list_invoices(self) -> list[Invoice]: ...


class InvoiceReport:
    """Client: sólo depende de InvoiceSource, nunca del módulo de pagos."""

    def __init__(self, source: InvoiceSource) -> None:
        self._source = source

    def total(self) -> float:
        return sum(inv.amount for inv in self._source.list_invoices())

    def render(self) -> str:
        lines = [f"{i.issued_on}  {i.name}  {i.amount:.2f}" for i in self._source.list_invoices()]
        lines.append(f"TOTAL: {self.total():.2f}")
        return "\n".join(lines)
