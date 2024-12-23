#include "music.h"

MusicManager* MusicManager::instance = nullptr;

MusicManager::MusicManager() {
    // ��ʼ��
}

MusicManager::~MusicManager() {
    // ������Դ
}

MusicManager* MusicManager::getInstance() {
    if (!instance) {
        instance = new MusicManager();
    }
    return instance;
}



void MusicManager::preloadSoundEffect(const std::string& soundEffectFile) {
    AudioEngine::preload(soundEffectFile);
}
int MusicManager::getIsBGMPlay() {
    return isBGMPlay;
}
void MusicManager::setIsBGMPlay(int option) {
    isBGMPlay = option;
}
int MusicManager::getIsBGMPause() {
	return isBGMPause;
}
void MusicManager::setIsBGMPause(int option) {
	isBGMPause = option;
}
int MusicManager::getIsSoundPlay() {
	return isSoundPlay;
}
void MusicManager::setIsSoundPlay(int option) {
	isSoundPlay = option;
}
void MusicManager::playBackgroundMusic() {
	bgmID=AudioEngine::play2d("CarrotGuardRes/Music/bgm.mp3", true, 0.5f);
}
void MusicManager::pauseBackgroundMusic() {
	AudioEngine::pause(bgmID);
}
void MusicManager::buttonSound() {
	if(isSoundPlay)
		AudioEngine::play2d("CarrotGuardRes/Music/button.mp3", false, 0.5f);
}
void MusicManager::pageSound() {
	if (isSoundPlay)
		AudioEngine::play2d("CarrotGuardRes/Music/page.mp3", false, 0.2f);
}
void MusicManager::buildSound() {
	if (isSoundPlay)
		AudioEngine::play2d("CarrotGuardRes/Music/build.mp3", false, 1.0f);
}
//���ų�����Ч
void  MusicManager::sellSound() {
	if (isSoundPlay)
		AudioEngine::play2d("CarrotGuardRes/Music/sell.mp3", false, 1.0f);
}
//����������Ч
void MusicManager::upgradeSound() {
	if (isSoundPlay)
		AudioEngine::play2d("CarrotGuardRes/Music/upgrade.mp3", false, 1.0f);
}
void  MusicManager::sunSound() {
	if (isSoundPlay)
		AudioEngine::play2d("CarrotGuardRes/Music/sun.mp3", false, 1.0f);
}
//����ƿ�ӹ�����Ч
void  MusicManager::bottleSound() {
	if (isSoundPlay)
		AudioEngine::play2d("CarrotGuardRes/Music/bottle.mp3", false, 1.0f);
}
//���ŷ��ȹ�����Ч
void  MusicManager::fanSound() {
	if (isSoundPlay)
		AudioEngine::play2d("CarrotGuardRes/Music/fan.mp3", false, 1.0f);
}
//�����ܲ�������Ч
void  MusicManager::carrotSound() {
	if (isSoundPlay)
		AudioEngine::play2d("CarrotGuardRes/Music/carrot.mp3", false, 1.0f);
}
//������ͨ��������Ч
void MusicManager::normalSound() {
	if (isSoundPlay)
		AudioEngine::play2d("CarrotGuardRes/Music/dead.mp3", false, 1.0f);
}
void MusicManager::countSound() {
	if (isSoundPlay)
		AudioEngine::play2d("CarrotGuardRes/Music/count.mp3", false, 1.0f);
}
void MusicManager::downSound() {
	if (isSoundPlay)
		AudioEngine::play2d("CarrotGuardRes/Music/down.mp3", false, 1.0f);
}


