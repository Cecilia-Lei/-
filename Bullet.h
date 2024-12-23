#pragma once

#include"cocos2d.h"
USING_NS_CC;

// ×Óµ¯Àà
class Bullet :public Sprite {
private:
	int _damage = 1;     // ÉËº¦
public:
	static Bullet* createWithSpriteFrameName(const std::string& filename) {
		Bullet* sprite = new Bullet();
		if (sprite && sprite->initWithSpriteFrameName(filename)) {
			sprite->autorelease();
			return sprite;
		}
		CC_SAFE_DELETE(sprite);
		return nullptr;
	}
	void setDamage(int damage) {
		_damage = damage;
		return;
	}
	int getDamage() {
		return _damage;
	}
};