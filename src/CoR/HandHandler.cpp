//
// Created by Mickael Salvas on 2021-03-22.
//

#include "HandHandler.h"

HandHandler *HandHandler::setNext(HandHandler *handler) {
    next = handler;
    return handler;
}