#include "screen.h"

namespace {
	std::string currentScreen = "";
	unsigned long screenLightMillisOn = 0;
}

namespace screen {

	void init() {
		pinMode(25, OUTPUT);
		digitalWrite(25, HIGH);
		screen_tft::init();
	}

	std::string getCurrentScreen() {
		return currentScreen;
	}

	void showInsertFiatScreen(const float &amount) {
		screen_tft::showInsertFiatScreen(amount);
		currentScreen = "insertFiat";
	}

	void showTradeCompleteScreen(const float &amount, const std::string &qrcodeData) {
		screen_tft::showTradeCompleteScreen(amount, qrcodeData);
		currentScreen = "tradeComplete";
	}

	void showWelcomeScreen() {
		screen_tft::showWelcomeScreen();
		currentScreen = "welcome";
	}

	void showCreditScreen() {
		screen_tft::showCreditScreen();
		currentScreen = "credit";
	}

	void loop(){
		if(millis() - screenLightMillisOn > 10000){
			digitalWrite(25, LOW);  
		}
	}

	void turnOnScreenLight(){
		digitalWrite(25, HIGH);
		screenLightMillisOn = millis();
	}
}
