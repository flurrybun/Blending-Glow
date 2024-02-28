#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

class $modify(PlayerObject) {
    void updatePlayerArt() {
        PlayerObject::updatePlayerArt();

        bool isBlendingGlow = Mod::get()->getSettingValue<bool>("blending-glow");
        if (!m_hasGlow || !isBlendingGlow) return;

        ccBlendFunc blendFunc = {GL_ONE, GL_ONE_MINUS_CONSTANT_ALPHA};

        auto iconGlow = m_iconGlow;
        auto vehicleGlow = m_vehicleGlow;

        if (iconGlow) iconGlow->setBlendFunc(blendFunc);
        if (vehicleGlow) vehicleGlow->setBlendFunc(blendFunc);
    }

    void updateGlowColor() {
        bool isBlendingGlow = Mod::get()->getSettingValue<bool>("blending-glow");
        bool isBrighterGlow = Mod::get()->getSettingValue<bool>("brighter-glow");
        
        if (isBrighterGlow && isBlendingGlow) {
            auto gm = GameManager::sharedState();
            auto glowColor = gm->colorForIdx(gm->getPlayerGlowColor());
            
            int r = std::min(static_cast<int>(glowColor.r * 1.5), 255);
            int g = std::min(static_cast<int>(glowColor.g * 1.5), 255);
            int b = std::min(static_cast<int>(glowColor.b * 1.5), 255);
            
            m_glowColor = ccc3(r, g, b);
        }

        PlayerObject::updateGlowColor();
    }
};