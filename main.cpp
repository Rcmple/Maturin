#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <string>

#include <tgbot/tgbot.h>
#include "Maturin_Bot.h"
using namespace std;
using namespace TgBot;

int main() {

    string token("6783099024:AAGoHd9Dm-ZvYwfqcK7B1hyNKbcN1CRyq-o");

    Bot bot(token);

    InlineKeyboardMarkup::Ptr keyboard(new InlineKeyboardMarkup);
    Maturin_Bot Maturin(bot, keyboard);
    Maturin.processing_Events();
//    bot.getEvents().onAnyMessage([&bot](Message::Ptr message) {
//        printf("User wrote %s\n", message->text.c_str());
//        bot.getApi().sendMessage(message->chat->id, "Your message is: " + message->text);
//    });
//    bot.getEvents().onCommand("start", [&bot, &keyboard](Message::Ptr message) {
//        bot.getApi().sendMessage(message->chat->id, "Вас приветствует компания Профбух. Выберите сайт для перехода:",
//                                 nullptr, nullptr, keyboard);
//    });
//    bot.getEvents().onCallbackQuery([&bot, &keyboard](CallbackQuery::Ptr query) {
//        if (StringTools::startsWith(query->data, "ProfBuhLink")) {
//            string response = "Ссылка на сайт поздразделения Профбух:\nhttps://профбух15.рф/";
//            bot.getApi().sendMessage(query->message->chat->id, response,
//                                     nullptr, nullptr);
//        }
//        if (StringTools::startsWith(query->data, "MaturinLink")) {
//            string response = "Ссылка на сайт поздразделения Матурин:\nhttps://матурин15.рф/";
//            bot.getApi().sendMessage(query->message->chat->id, response,
//                                     nullptr, nullptr);
//        }
//        if (StringTools::startsWith(query->data, "Contacts")) {
//            string response = "бла бла бла бла";
//            bot.getApi().sendMessage(query->message->chat->id, response,
//                                     nullptr, nullptr);
//        }
//    });
    try {
        printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
        bot.getApi().deleteWebhook();

        TgLongPoll longPoll(bot);
        while (true) {
            printf("Long poll started\n");
            longPoll.start();
        }
    } catch (exception& e) {
        printf("error: %s\n", e.what());
    }

    return 0;
}