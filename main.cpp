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

    string token("my token");

    Bot bot(token);

    InlineKeyboardMarkup::Ptr keyboard(new InlineKeyboardMarkup);
    Maturin_Bot Maturin(bot, keyboard);
    Maturin.processing_Events();
    return 0;
}
