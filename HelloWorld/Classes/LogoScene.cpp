#include "LogoScene.h"
#include "HelloWorldScene.h"
#include <iostream>
USING_NS_CC;

Scene * LogoScene::createScene()
{
	return LogoScene::create();
}

bool LogoScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto ground = Sprite::create("./Sprites/Parallax/ground.png");
	auto trees = Sprite::create("./Sprites/Parallax/tree.png");
	auto background = Sprite::create("./Sprites/background.png");
	auto curSizeBG = background->getContentSize();
	auto winSize = Director::getInstance()->getWinSize();
	background->setScale(winSize.width / curSizeBG.width, winSize.height / curSizeBG.height);
	trees->setPosition(Vec2(0, 160));
	background->setPosition(300, 300);
	addChild(ground, 0);
	addChild(trees, 0);
	addChild(background, -1);
	//scheduleUpdate();
	return true;
}

void LogoScene::update(float deltaTime)
{
	static int j = 0;
	j++;
	if (j == 50) {
		j = 0;
		auto hello = HelloWorld::createScene();
		Director::getInstance()->replaceScene(TransitionPageTurn::create(0.9, hello, true));

		//Director::getInstance()->replaceScene(TransitionJumpZoom::create(0.9, hello));

		//Director::getInstance()->replaceScene(TransitionFade::create(0.9, hello,Color3B(255,255,255)));

		//Director::getInstance()->replaceScene(TransitionFlipX::create(0.9, hello));

		//Director::getInstance()->replaceScene(TransitionFlipY::create(0.9,hello));
	}
}
