//
// Created by rcmpl on 01.08.2024.
//

#ifndef MATURINBOT_MATURIN_BOT_H
#define MATURINBOT_MATURIN_BOT_H
#include <tgbot/tgbot.h>

#include <utility>
#include <string>

using namespace std;
class Maturin_Bot {
private:
    TgBot::Bot& Mat_Bot;
    TgBot::InlineKeyboardMarkup::Ptr Mat_keyboard;
public:
    explicit Maturin_Bot(TgBot::Bot& Bot, TgBot::InlineKeyboardMarkup::Ptr keyboard) : Mat_Bot(Bot), Mat_keyboard(std::move(keyboard)) {};
    void processing_Events();
    void start_general_menu(const TgBot::Message::Ptr& message);
    void general_menu(const TgBot::CallbackQuery::Ptr& query);
    void change_to_InstagramLink(const TgBot::CallbackQuery::Ptr& query);
    void change_to_Contacts(const TgBot::CallbackQuery::Ptr& query);

};


#endif //MATURINBOT_MATURIN_BOT_H
