#pragma once
#include"cocos2d.h"
USING_NS_CC;

class PointDelegate : public Ref
{
private:
	float _x=0;
	float _y=0;
public:
	static PointDelegate* create(float x, float y)
	{
		PointDelegate* p = new PointDelegate();
		if (p) {
			p->initPoint(x, y);
			p->autorelease();
			return p;
		}
		CC_SAFE_DELETE(p);
		return nullptr;
	}
	// ≥ı ºªØ∏≥÷µ
	void initPoint(float x, float y) {
		_x = x;
		_y = y;
	}
	float getX() {
		return _x;
	}
	float getY() {
		return _y;
	}
};