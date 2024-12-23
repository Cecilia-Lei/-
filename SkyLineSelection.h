#pragma once
//Ì½ÏÕÄ£Ê½
#ifndef __SKYLINE_SCENE_H__
#define __SKYLINE_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class SkyLineSelection : public Layer {
private:
	int _selectLevelIndex;

public:
	static Scene* createScene();
	virtual bool init();
	void ToAdvantureScene(Ref* pSender);
	CREATE_FUNC(SkyLineSelection);

	int getSelectLevelIndex() {
		return _selectLevelIndex;
	}
	void setSelectLevelIndex(int index) {
		_selectLevelIndex = index;
		return;
	}
};

#endif __SKYLINE_SCENE_H__
