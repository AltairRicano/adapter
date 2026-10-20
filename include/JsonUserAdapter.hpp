#pragma once
#include "IUserProvider.hpp"
#include "LegacyJsonService.hpp"
#include "nlohmann/json.hpp"

class JsonUserAdapter : public IUserProvider {
public:
    explicit JsonUserAdapter(LegacyJsonService& legacyService)
        : m_legacyService(legacyService) {}

    UserProfile getUser(int userId) override {
        std::string rawJson = m_legacyService.fetchRawUserData(userId);
        auto data = nlohmann::json::parse(rawJson);

        return UserProfile{
            data.at("user_id").get<int>(),
            data.at("user_handle").get<std::string>(),
            data.at("contact_mail").get<std::string>()
        };
    }

private:
    LegacyJsonService& m_legacyService;
};
