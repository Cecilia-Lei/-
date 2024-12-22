#include "MenuScene.h"
#include "SettingScene.h"
#include "ui/CocosGUI.h"
#include "AudioEngine.h"
#include "Music.h"
using namespace ui;

//��ǵ�ǰ�����Ƿ��ڲ���
//bool isMusicOn = true;

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
}

Scene* SettingScene::createScene()
{
	auto scene = Scene::create();
	auto layer = SettingScene::create();
	scene->addChild(layer);
	return scene;
}

bool SettingScene::init() {
	if (!Layer::init())
		return false;

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	//��ӱ���ͼƬ
	auto settingBackground = Sprite::create("CarrotGuardRes/UI/SettingBackground.png");
	if (settingBackground == nullptr)
	{
		problemLoading("'SettingBackground.png'");
	}
	else
	{
		settingBackground->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
		settingBackground->setScale(visibleSize.width / settingBackground->getContentSize().width);
		this->addChild(settingBackground, 0);
	}

	//��ñ���ͼƬ�ʹ��ڵ����ű���
	float backgroundScale = visibleSize.width / settingBackground->getContentSize().width;

	//��ӷ��ذ�ť
	auto menu = Menu::create();
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	auto returnButton = MenuItemImage::create("CarrotGuardRes/UI/SettingReturnNormal.png", "CarrotGuardRes/UI/SettingReturnSelected.png", CC_CALLBACK_1(SettingScene::ToMenuScene, this));
	if (returnButton == nullptr ||
		returnButton->getContentSize().width <= 0 ||
		returnButton->getContentSize().height <= 0)
	{
		problemLoading("'SettingReturnNormal.png' and 'SettingReturnSelected.png'");
	}
	else
	{
		float x = origin.x + returnButton->getContentSize().width / 2 + visibleSize.width * 0.05f;
		float y = origin.y + visibleSize.height - returnButton->getContentSize().width / 2 - visibleSize.height * 0.04f;
		returnButton->setPosition(Vec2(x, y));
		returnButton->setScale(1.8f * backgroundScale);
		menu->addChild(returnButton);
	}

	//��Ӳ���bgm��ť
	auto musicLabel_1 = Label::createWithSystemFont(StringUtils::format("Background"), "Arial", 27);
	auto musicLabel_2 = Label::createWithSystemFont(StringUtils::format("music"), "Arial", 27);
	musicLabel_1->setPosition(Vec2(visibleSize.width * 0.62, visibleSize.height * 0.77));
	musicLabel_2->setPosition(Vec2(visibleSize.width * 0.62, visibleSize.height * 0.72));
	musicLabel_1->setColor(Color3B::BLACK);
	musicLabel_2->setColor(Color3B::BLACK);
	this->addChild(musicLabel_1,2);
	this->addChild(musicLabel_2, 2);


	

	auto playMusicButton = MenuItemImage::create("CarrotGuardRes/UI/MusicOn.png", "CarrotGuardRes/UI/MusicClose.png", CC_CALLBACK_1(SettingScene::PlayBGM, this));
	if (playMusicButton == nullptr)
	{
		problemLoading("'MusicOn.png' and 'MusicClose.png'");
	}
	else
	{
		playMusicButton->setPosition(Vec2(visibleSize.width*0.62, visibleSize.height *0.64));
		playMusicButton->setScale(1.7f * backgroundScale);
		menu->addChild(playMusicButton);
		if (MusicManager::getInstance()->getIsBGMPlay()) {
			playMusicButton->setNormalImage(Sprite::create("CarrotGuardRes/UI/MusicOn.png"));
			playMusicButton->setSelectedImage(Sprite::create("CarrotGuardRes/UI/MusicOn.png"));
		}
		else {
			playMusicButton->setNormalImage(Sprite::create("CarrotGuardRes/UI/MusicClose.png"));
			playMusicButton->setSelectedImage(Sprite::create("CarrotGuardRes/UI/MusicClose.png"));
		}
	}

	//��Ӳ�����Ч��ť
	auto soundLabel_1 = Label::createWithSystemFont(StringUtils::format("Sound"), "Arial", 27);
	auto soundLabel_2 = Label::createWithSystemFont(StringUtils::format("effect"), "Arial", 27);
	soundLabel_1->setPosition(Vec2(visibleSize.width * 0.38, visibleSize.height * 0.77));
	soundLabel_2->setPosition(Vec2(visibleSize.width * 0.38, visibleSize.height * 0.72));
	soundLabel_1->setColor(Color3B::BLACK);
	soundLabel_2->setColor(Color3B::BLACK);
	this->addChild(soundLabel_1, 2);
	this->addChild(soundLabel_2, 2);


	auto playSoundButton = MenuItemImage::create("CarrotGuardRes/UI/soundOn.png", "CarrotGuardRes/UI/soundClose.png", CC_CALLBACK_1(SettingScene::PlaySoundEffect, this));
	if (playSoundButton == nullptr)
	{
		problemLoading("'soundOn.png' and 'soundClose.png'");
	}
	else
	{
		playSoundButton->setPosition(Vec2(visibleSize.width * 0.38, visibleSize.height * 0.64));
		playSoundButton->setScale(1.7f * backgroundScale);
		menu->addChild(playSoundButton);
		if (MusicManager::getInstance()->getIsSoundPlay()) {
			playSoundButton->setNormalImage(Sprite::create("CarrotGuardRes/UI/soundOn.png"));
			playSoundButton->setSelectedImage(Sprite::create("CarrotGuardRes/UI/soundOn.png"));
		}
		else {
			playSoundButton->setNormalImage(Sprite::create("CarrotGuardRes/UI/soundClose.png"));
			playSoundButton->setSelectedImage(Sprite::create("CarrotGuardRes/UI/soundClose.png"));
		}
	}

	// ���������Ϣ
	auto authorLabel_1 = Label::createWithSystemFont(StringUtils::format("Game developers: Wang,  Dai"), "Arial", 27);
	auto authorLabel_2 = Label::createWithSystemFont(StringUtils::format("Development time: 2023/12/31"), "Arial", 27);
	auto authorLabel_3 = Label::createWithSystemFont(StringUtils::format("ABOUT"), "Arial", 27);
	authorLabel_1->setPosition(Vec2(visibleSize.width * 0.5, visibleSize.height * 0.4));
	authorLabel_2->setPosition(Vec2(visibleSize.width * 0.5, visibleSize.height * 0.3));
	authorLabel_3->setPosition(Vec2(visibleSize.width * 0.5, visibleSize.height * 0.5));
	authorLabel_1->setColor(Color3B::WHITE);
	authorLabel_2->setColor(Color3B::WHITE);
	authorLabel_3->setColor(Color3B::BLACK);
	this->addChild(authorLabel_1, 2);
	this->addChild(authorLabel_2, 2);
	this->addChild(authorLabel_3, 2);

	return true;
}


void SettingScene::ToMenuScene(Ref* pSender) {
	MusicManager::getInstance()->buttonSound();
	auto menuScene = MenuScene::createScene();
	Director::getInstance()->replaceScene(menuScene);
}
//��bgm
void SettingScene::PlayBGM(Ref* pSender) {
	MusicManager::getInstance()->buttonSound();
	int isMusicOn = MusicManager::getInstance()->getIsBGMPlay();
	MenuItemImage* button = static_cast<MenuItemImage*>(pSender);

	//��֮ǰû�в�������
	if (!isMusicOn) {
		MusicManager::getInstance()->playBackgroundMusic();
		button->setNormalImage(Sprite::create("CarrotGuardRes/UI/MusicOn.png"));
		button->setSelectedImage(Sprite::create("CarrotGuardRes/UI/MusicOn.png"));
		MusicManager::getInstance()->setIsBGMPlay(1);

	}
	//��֮ǰ���ڲ�������
	else {
		MusicManager::getInstance()->pauseBackgroundMusic();
		button->setNormalImage(Sprite::create("CarrotGuardRes/UI/MusicClose.png"));
		button->setSelectedImage(Sprite::create("CarrotGuardRes/UI/MusicClose.png"));
		MusicManager::getInstance()->setIsBGMPlay(0);

	}
}

//����Ч
void SettingScene::PlaySoundEffect(Ref* pSender) {
	MusicManager::getInstance()->buttonSound();
	int isSoundOn = MusicManager::getInstance()->getIsSoundPlay();
	MenuItemImage* button = static_cast<MenuItemImage*>(pSender);

	//��֮ǰû����Ч
	if (!isSoundOn) {
		button->setNormalImage(Sprite::create("CarrotGuardRes/UI/soundOn.png"));
		button->setSelectedImage(Sprite::create("CarrotGuardRes/UI/soundOn.png"));
		MusicManager::getInstance()->setIsSoundPlay(1);

	}
	//��֮ǰ������Ч
	else {
		button->setNormalImage(Sprite::create("CarrotGuardRes/UI/soundClose.png"));
		button->setSelectedImage(Sprite::create("CarrotGuardRes/UI/soundClose.png"));
		MusicManager::getInstance()->setIsSoundPlay(0);

	}
}
