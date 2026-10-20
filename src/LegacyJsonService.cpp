#include "LegacyJsonService.hpp"
#include <sstream>

std::string LegacyJsonService::fetchRawUserData(int id) {
    // Simula una respuesta JSON cruda desde un API externa o base de datos legacy
    std::ostringstream oss;
    oss << "{\n"
        << "  \"user_id\": " << id << ",\n"
        << "  \"user_handle\": \"dev_coder_" << id << "\",\n"
        << "  \"contact_mail\": \"coder" << id << "@example.com\"\n"
        << "}";
    return oss.str();
}
