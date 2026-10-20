# Patrón Adapter en C++ (Ejemplo con JSON)

Este repositorio contiene un ejemplo práctico del patrón de diseño **Adapter** implementado en C++17 utilizando la biblioteca [`nlohmann/json`](https://github.com/nlohmann/json).

## Estructura de Componentes

| Rol del Patrón | Clase / Archivo | Descripción |
| :--- | :--- | :--- |
| **Target Interface** | [`IUserProvider.hpp`](include/IUserProvider.hpp) | Interfaz esperada por la lógica de negocio / cliente. |
| **Domain Model** | [`UserProfile.hpp`](include/UserProfile.hpp) | Estructura de datos limpia usada internamente. |
| **Adaptee** | [`LegacyJsonService.hpp`](include/LegacyJsonService.hpp) | Servicio existente o de terceros que devuelve strings JSON sin estructurar. |
| **Adapter** | [`JsonUserAdapter.hpp`](include/JsonUserAdapter.hpp) | **Tu tarea:** Implementa `IUserProvider`, consume el JSON y produce `UserProfile`. |
| **Client** | [`main.cpp`](src/main.cpp) | Consume usuarios únicamente a través de `IUserProvider`. |

---

## Cómo Compilar y Ejecutar

Compilar el proyecto:
```bash
make
```

Compilar y ejecutar:
```bash
make run
```

Limpiar archivos generados:
```bash
make clean
```
