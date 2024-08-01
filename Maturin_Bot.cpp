//
// Created by rcmpl on 01.08.2024.
//

#include "Maturin_Bot.h"
#include <tgbot/tgbot.h>
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <string>
using namespace TgBot;
using namespace std;
void Maturin_Bot::processing_Events() {
    Mat_Bot.getEvents().onCommand("start", [this](Message::Ptr message) {
        vector<InlineKeyboardButton::Ptr> start_buttons;
        InlineKeyboardButton::Ptr MaturinLink(new InlineKeyboardButton), ProfBuhLink(new InlineKeyboardButton),
                Contacts(new InlineKeyboardButton);
        ProfBuhLink->text = "Наш Instagram";
        ProfBuhLink->callbackData = "InstagramLink";
        MaturinLink->text = "Услуги";
        MaturinLink->callbackData = "Services";
        Contacts->text = "Контакты";
        Contacts->callbackData = "Contacts";
        start_buttons.push_back(ProfBuhLink);
        start_buttons.push_back(MaturinLink);
        start_buttons.push_back(Contacts);
        Mat_keyboard->inlineKeyboard.push_back(start_buttons);
        Mat_Bot.getApi().sendPhoto(message->chat->id,
                                   InputFile::fromFile("/mnt/d/MaturinBot/pictures/maturin.png", "image/png"),
                                   "Вас приветствует компания Матурин. Выберите необходимую вам опцию:",
                                   nullptr, Mat_keyboard);
    });
}

