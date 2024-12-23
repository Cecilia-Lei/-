#pragma once

#include"cocos2d.h"

USING_NS_CC;

// 存储关卡数据信息
class LevelData:public Ref
{
public:
	int _number;// 怪物波数
	std::string _bg; //关卡背景
	std::string _data;//关卡数据文件

	static LevelData* create(int number, std::string bg, std::string data) {
		LevelData* Sprite = new LevelData();
		if (Sprite) {
			Sprite->autorelease();
			Sprite->_number = number;
			Sprite->_bg = bg;
			Sprite->_data = data;
			return Sprite;
		}
		CC_SAFE_DELETE(Sprite);
		return nullptr;
	}
};

