#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

class $modify(PlayerObject) {
	bool init(int p0, int p1, GJBaseGameLayer* p2, cocos2d::CCLayer* p3, bool p4) {
		if (!PlayerObject::init(p0, p1, p2, p3, p4)) return false;

    auto node = as<CCNode*>(this->getChildren()->objectAtIndex(0));
    as<CCSprite*>(as<CCSprite*>(node->getChildren()->objectAtIndex(6))->getChildren()->objectAtIndex(1))->setID("gamemode-glow");
    as<CCSprite*>(as<CCSprite*>(node->getChildren()->objectAtIndex(6))->getChildren()->objectAtIndex(2))->setID("ship-glow");

    return true;
	}

  void updatePlayerArt() {
    PlayerObject::updatePlayerArt();

    ccBlendFunc blendFunc = { GL_ONE, GL_ONE_MINUS_CONSTANT_ALPHA };

    auto gamemodeGlow = as<CCSprite*>(PlayerObject::getChildByIDRecursive("gamemode-glow"));
    auto shipGlow = as<CCSprite*>(PlayerObject::getChildByIDRecursive("ship-glow"));

    if (gamemodeGlow) gamemodeGlow->setBlendFunc(blendFunc);
    if (shipGlow) shipGlow->setBlendFunc(blendFunc);
  }
};