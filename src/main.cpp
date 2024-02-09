#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

class $modify(PlayerObject) {
    void updatePlayerArt() {
        PlayerObject::updatePlayerArt();

        ccBlendFunc blendFunc = {GL_ONE, GL_ONE_MINUS_CONSTANT_ALPHA};

        auto iconGlow = m_iconGlow;
        auto vehicleGlow = m_vehicleGlow;

        if (iconGlow) iconGlow->setBlendFunc(blendFunc);
        if (vehicleGlow) vehicleGlow->setBlendFunc(blendFunc);
    }
};