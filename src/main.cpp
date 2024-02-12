#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

class $modify(PlayerObject) {
    bool isBrighterGlow = Mod::get()->getSettingValue<bool>("brighter-glow");
    
    void updatePlayerArt() {
        PlayerObject::updatePlayerArt();

        if (m_hasGlow == false) return;

        if (isBrighterGlow) {
            int r = std::min(static_cast<int>(m_glowColor.r * 1.5), 255);
            int g = std::min(static_cast<int>(m_glowColor.g * 1.5), 255);
            int b = std::min(static_cast<int>(m_glowColor.b * 1.5), 255);
            
            m_glowColor = ccc3(r, g, b);
            updateGlowColor();
        }

        ccBlendFunc blendFunc = {GL_ONE, GL_ONE_MINUS_CONSTANT_ALPHA};

        auto iconGlow = m_iconGlow;
        auto vehicleGlow = m_vehicleGlow;

        if (iconGlow) iconGlow->setBlendFunc(blendFunc);
        if (vehicleGlow) vehicleGlow->setBlendFunc(blendFunc);
    }
};