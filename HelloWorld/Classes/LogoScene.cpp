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
	static int i = 0;
	i++;
	if (i == 50) {
		i = 0;
		auto hello = HelloWorld::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(1,hello,Color3B(255,255,255)));
	}
	else
	{
		std::cout << i << std::endl;
	}
}
