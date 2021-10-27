//
// Created by Mickael Salvas on 2021-02-28.
//

#include "PokerGame.h"
#include "PokerStyles/PokerStyle.h"
#include "PokerStyles/Texas/TexasPoker.h"
#include "PokerStyles/PokerStyleFactory.h"
#include <iostream>

void PokerGame::start() {
    printMenu();
    int keepPlaying = -1;
    do {
        printPokerChoice();
        int pokerChoice = getPokerChoice();
        PokerStyle *pokerStyle = PokerStyleFactory().createPokerStyle(pokerChoice);
        if (pokerStyle == nullptr) {
            if (pokerChoice == 0) {
                return;
            } else {
                unImplementedMsg();
                return;
            }
        }
        int playersNb = getPlayersNb(pokerStyle->getMinPlayers(), pokerStyle->getMaxPlayers());
        pokerStyle->play(playersNb);
        keepPlaying = getPlayingChoice();
        delete pokerStyle;
    } while (keepPlaying != 0);
    std::cout << std::endl << "Goodbye ! 😄" << std::endl;
}

void PokerGame::printMenu() {
    std::cout << "Welcome to my beautiful poker game ! ♥️♠️♦️♣️\n"
                 "You will need to choose the poker style that you want to play\n"
                 "and then select the amount of players (including you) !\n";
}

void PokerGame::printPokerChoice() {
    std::cout << "\n"
                 "Select your poker style : \n"
                 "1. Texas Hold'em Limit\n"
                 "2. Ohama\n"
                 "3. Fermé\n"
                 "4. Royal\n"
                 "0. QUIT GAME\n";
}

int PokerGame::getPokerChoice() {
    int choice = -1;
    do {
        std::cout << "Your choice : ";
        std::cin >> choice;
        if (choiceIsInvalid(choice)) {
            invalidChoiceMessage();
        }
    } while (choiceIsInvalid(choice));
    std::cout << std::endl;
    return choice;
}

int PokerGame::getPlayersNb(int min, int max) {
    int nb = -1;
    do {
        std::cout << "Enter your player amount : ";
        std::cin >> nb;
        if (playersNbIsInvalid(min, max, nb)) {
            invalidPlayersNbMessage(min, max);
        }
    } while (playersNbIsInvalid(min, max, nb));
    std::cout << std::endl;
    return nb;
}

bool PokerGame::choiceIsInvalid(int choice) {
    return choice < MIN_CHOICE || choice > MAX_CHOICE;
}

bool PokerGame::playersNbIsInvalid(int min, int max, int nb) {
    return nb < min || nb > max;
}

void PokerGame::invalidChoiceMessage() {
    std::cout << "\nYour choice is invalid, your choice must be between "
              << MIN_CHOICE << " and " << MAX_CHOICE << ".\n";
}

void PokerGame::invalidPlayersNbMessage(int min, int max) {
    std::cout << "\nYour player amount is invalid, it must be between "
              << min << " and " << max << ".\n";
}

void PokerGame::unImplementedMsg() {
    std::cout << "Un-implemented poker style choice, quitting application..." << std::endl;
}

int PokerGame::getPlayingChoice() {
    int choice = -1;
    do {
        std::cout << std::endl << "What do you want to do ?" << std::endl;
        std::cout << "1. Keep playing\n0. Leave" << std::endl;
        std::cout << "Your choice : ";
        std::cin >> choice;
        if (choice < 0 || choice > 1) {
            std::cout << "Your choice is invalid." << std::endl;
        }
    } while (choice < 0 || choice > 1);
    return choice;
}




