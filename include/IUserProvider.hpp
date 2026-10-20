#pragma once
#include "UserProfile.hpp"

/**
 * @brief TARGET INTERFACE: La interfaz esperada por el cliente.
 * 
 * Todo el código del cliente trabaja contra esta interfaz y espera
 * recibir un objeto 'UserProfile' limpio, sin saber de dónde viene ni cómo se obtiene.
 */
class IUserProvider {
public:
    virtual ~IUserProvider() = default;
    virtual UserProfile getUser(int userId) = 0;
};
