#pragma once
#include <string>

/**
 * @brief ADAPTEE: Servicio existente / de terceros con interfaz incompatible.
 * 
 * Este servicio devuelve información de usuario como un string en formato JSON crudo
 * y sus claves no coinciden directamente con UserProfile (usa snake_case y nombres distintos).
 * El cliente NO puede usar este servicio directamente sin acoplarse a él.
 */
class LegacyJsonService {
public:
    // Devuelve un string JSON con formato:
    // { "user_id": 42, "user_handle": "neo_matrix", "contact_mail": "neo@zion.org" }
    std::string fetchRawUserData(int id);
};
