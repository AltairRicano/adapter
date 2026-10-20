#pragma once
#include "IUserProvider.hpp"
#include "LegacyJsonService.hpp"
#include "nlohmann/json.hpp"
#include <memory>

/**
 * @brief ADAPTER: Conecta IUserProvider (Target) con LegacyJsonService (Adaptee).
 * 
 * Tu tarea es completar esta clase:
 * 1. Debe heredar públicamente de IUserProvider.
 * 2. Debe mantener una referencia o puntero (o std::shared_ptr) a LegacyJsonService.
 * 3. Debe implementar el método virtual `UserProfile getUser(int userId) override`.
 * 
 * En `getUser`:
 *   - Llama a `fetchRawUserData(userId)` del servicio legacy.
 *   - Parsea el JSON con `nlohmann::json::parse(...)`.
 *   - Extrae "user_id", "user_handle" y "contact_mail".
 *   - Construye y retorna un objeto `UserProfile`.
 */
class JsonUserAdapter : public IUserProvider {
public:
    // TODO: Diseña el constructor. ¿Cómo recibe o guarda el LegacyJsonService?
    // Sugerencia: recibir una referencia (LegacyJsonService&) o std::shared_ptr.
    explicit JsonUserAdapter(LegacyJsonService& legacyService)
        : m_legacyService(legacyService) {}

    UserProfile getUser(int userId) override {
        // TODO: 
        // 1. Obtener el string JSON desde m_legacyService:
        //    std::string rawJson = m_legacyService.fetchRawUserData(userId);

        // 2. Parsear el JSON usando nlohmann::json:
        //    auto data = nlohmann::json::parse(rawJson);

        // 3. Extraer los campos y construir UserProfile:
        //    data["user_id"].get<int>()
        //    data["user_handle"].get<std::string>()
        //    data["contact_mail"].get<std::string>()

        // 4. Retornar el UserProfile resultante.
        
        // (Reemplaza este placeholder por tu implementación)
        return UserProfile{ userId, "PENDIENTE_DE_IMPLEMENTAR", "PENDIENTE_DE_IMPLEMENTAR" };
    }

private:
    LegacyJsonService& m_legacyService;
};
