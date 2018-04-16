#include"MainScene.h"
#include"CharacterScene.h"
#include"Others.h"
#include"ConsoleLayer.h"
#include"ConsoleManager.h"
#include<ui/CocosGUI.h>

USING_NS_CC;

bool MainScene::init() {
	if(!Scene::init()) {
		return false;
	}
	auto VisionSize = Director::getInstance()->getVisibleSize();

	//Keyboard
	CONSOLE_KEY;

	//Background
	auto Background = Sprite::create(DIR_IMAGES + "Background.png");
	Background->setScale(VisionSize.width / 1215., VisionSize.height / 717.);
	Background->setPosition(Vec2(VisionSize.width / 2, VisionSize.height / 2));
	this->addChild(Background);

	//CharacterButton
	auto CharacterButton = ui::Button::create(DIR_IMAGES + "Button_Normal.png", DIR_IMAGES + "Button_Press.png", DIR_IMAGES + "Button_Disable.png");
	CharacterButton->setName("Char");
	CharacterButton->setPosition(Vec2(664, 62));
	CharacterButton->setScale9Enabled(true);
	CharacterButton->setContentSize(Size(80, 80));
	CharacterButton->addTouchEventListener(
		[&](Ref* sender, ui::Widget::TouchEventType type) {
			switch(type) {
			case ui::Widget::TouchEventType::ENDED:
				Director::getInstance()->pushScene(CharacterScene::create());
				break;
			}
		}
	);
	auto CharacterButtonLabel = Label::createWithTTF(u8"����", FONTS_KAI, 32);
	CharacterButtonLabel->setColor(Color3B(0, 0, 0));
	CharacterButton->setTitleLabel(CharacterButtonLabel);
	this->addChild(CharacterButton);

	//BagButton
	auto BagButton = ui::Button::create(DIR_IMAGES + "Button_Normal.png", DIR_IMAGES + "Button_Press.png", DIR_IMAGES + "Button_Disable.png");
	BagButton->setName("Bag");
	BagButton->setPosition(Vec2(746, 62));
	BagButton->setScale9Enabled(true);
	BagButton->setContentSize(Size(80, 80));
	BagButton->addTouchEventListener(
		[&](Ref* sender, ui::Widget::TouchEventType type) {
			//TODO: Add the Bag Layer.
		}
	);
	auto BagButtonLabel = Label::createWithTTF(u8"����", FONTS_KAI, 32);
	BagButtonLabel->setColor(Color3B(0, 0, 0));
	BagButton->setTitleLabel(BagButtonLabel);
	this->addChild(BagButton);

	ConsoleManager::Get()->
		AddCommand("/setpos", 3,
				   [&](std::vector<std::string> t)->bool {
					   this->getChildByName(t[0])->setPosition(Vec2(std::stof(t[1]), std::stof(t[2])));
					   return true;
				   }
	);
	return true;
}