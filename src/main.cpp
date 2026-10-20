#include <iostream>
#include <memory>
#include "IUserProvider.hpp"
#include "LegacyJsonService.hpp"
#include "JsonUserAdapter.hpp"

/**
 * @brief CLIENTE: Función de alto nivel / lógica de negocio.
 * 
 * Observa que printUserInfo NO sabe nada de LegacyJsonService ni de JSON.
 * Solo conoce la interfaz IUserProvider.
 */
void printUserInfo(IUserProvider& provider, int userId) {
    std::cout << "[Cliente] Solicitando usuario con ID: " << userId << "...\n";
    UserProfile profile = provider.getUser(userId);

    std::cout << "----------------------------------------\n";
    std::cout << "  ID       : " << profile.id << "\n";
    std::cout << "  Username : " << profile.username << "\n";
    std::cout << "  Email    : " << profile.email << "\n";
    std::cout << "----------------------------------------\n";
}

int main() {
    std::cout << "=== Patrón Adapter en C++ con JSON ===\n\n";

    // 1. Instanciamos el servicio legado (Adaptee)
    LegacyJsonService legacyService;

    std::cout << "[Adaptee Raw Output para ID 101]:\n" 
              << legacyService.fetchRawUserData(101) << "\n\n";

    // 2. Usamos el adaptador (Adapter) para envolver el servicio legado
    JsonUserAdapter adapter(legacyService);

    // 3. El cliente consume el adaptador a través de la interfaz Target (IUserProvider)
    std::cout << "[Ejecución del Cliente con el Adaptador]:\n";
    printUserInfo(adapter, 101);
    printUserInfo(adapter, 204);

    return 0;
}
