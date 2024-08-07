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
void Maturin_Bot::start_general_menu(const TgBot::Message::Ptr &message)  {
    Mat_keyboard->inlineKeyboard.clear();
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
    InputFile::Ptr Mat_photo = InputFile::fromFile("/mnt/d/MaturinBot/pictures/maturin.png", "image/png");
    Mat_Bot.getApi().sendPhoto(message->chat->id,
                               Mat_photo,
                               "Здравствуйте, " + message->chat->firstName +
                               ". Вас приветствует компания Матурин. Выберите необходимую вам опцию:",
                               nullptr, Mat_keyboard);
}
void Maturin_Bot::general_menu(const CallbackQuery::Ptr& query) {
    Mat_Bot.getApi().deleteMessage(query->message->chat->id, query->message->messageId);
    Mat_keyboard->inlineKeyboard.clear();
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
    InputFile::Ptr Mat_photo = InputFile::fromFile("/mnt/d/MaturinBot/pictures/maturin.png", "image/png");
    Mat_Bot.getApi().sendPhoto(query->message->chat->id,
                              Mat_photo,
                              "Выберите необходимую вам опцию:",
                              nullptr, Mat_keyboard);
}
void Maturin_Bot::change_to_InstagramLink(const CallbackQuery::Ptr &query) {
    Mat_keyboard->inlineKeyboard.clear();
    vector<InlineKeyboardButton::Ptr> InstagramLink;
    InlineKeyboardButton::Ptr Mat_Link(new InlineKeyboardButton), Back_button(new InlineKeyboardButton);
    Mat_Link->text = "Инстаграм";
    Mat_Link->callbackData = "FinalInstagramLink";
    Mat_Link->url = "https://www.instagram.com/maturin_vld/";
    Back_button->text = "Главное меню";
    Back_button->callbackData = "general menu instagram";
    InstagramLink.push_back(Mat_Link);
    InstagramLink.push_back(Back_button);
    Mat_keyboard->inlineKeyboard.push_back(InstagramLink);
    Mat_Bot.getApi().editMessageCaption(query->message->chat->id, query->message->messageId,
                                    "Нажмите на кнопку ниже для перехожа в Instagram:",
                                    query->inlineMessageId, Mat_keyboard);
}
void Maturin_Bot::change_to_Contacts(const CallbackQuery::Ptr &query) {
    Mat_keyboard->inlineKeyboard.clear();
    vector<InlineKeyboardButton::Ptr> InstagramLink;
    InlineKeyboardButton::Ptr Back_button(new InlineKeyboardButton);
    Back_button->text = "Главное меню";
    Back_button->callbackData = "general menu";
    InstagramLink.push_back(Back_button);
    Mat_keyboard->inlineKeyboard.push_back(InstagramLink);
    Mat_Bot.getApi().editMessageCaption(query->message->chat->id, query->message->messageId,
                                        "Контакты расположены ниже, также вы можете вернуться в главное меню:",
                                        query->inlineMessageId, Mat_keyboard);
    Mat_Bot.getApi().sendContact(query->message->chat->id, "+7(918)8233010", "Инна", "Крыжановская");
}
void Maturin_Bot::processing_Events() {

    Mat_Bot.getEvents().onCommand("start", [this](const Message::Ptr& message) {
        start_general_menu(message);
    });
    Mat_Bot.getEvents().onCallbackQuery([this](const CallbackQuery::Ptr& query) {
        InputFile::Ptr Mat_photo = InputFile::fromFile("/mnt/d/MaturinBot/pictures/maturin.png", "image/png");
        cout << query -> data << '\n';
        if (StringTools::startsWith(query->data, "InstagramLink")) {
            change_to_InstagramLink(query);
        }
        if (StringTools::startsWith(query->data, "Contacts")) {
            change_to_Contacts(query);
        }
        if (StringTools::startsWith(query->data, "general menu")) {
            general_menu(query);
        }
    });

    try {
        printf("Bot username: %s\n", Mat_Bot.getApi().getMe()->username.c_str());
        Mat_Bot.getApi().deleteWebhook();

        TgLongPoll longPoll(Mat_Bot);
        while (true) {
            printf("Long poll started\n");
            longPoll.start();
        }
    } catch (exception& e) {
        printf("error: %s\n", e.what());
    }
}


