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
	scheduleUpdate();
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
