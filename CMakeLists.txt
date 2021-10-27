cmake_minimum_required(VERSION 3.17)

set(This Poker)
set(CMAKE_CXX_STANDARD 20)
project(${This} CXX)

enable_testing()
add_subdirectory(googletest)

set(Headers
        src/PokerGame.h
        src/PokerStyles/PokerStyleFactory.h
        src/PokerStyles/PokerStyle.h
        src/PokerStyles/Texas/TexasPoker.h
        src/Models/Card/Card.h
        src/Models/Hand/Hand.h
        src/Models/Player/Player.h
        src/Consoles/CardConsole.h
        src/Consoles/PlayerConsole.h
        src/Consoles/Console.h
        src/CoR/HandHandler.h
        src/CoR/HandHandlerHelper.h
        src/CoR/HighCardHandler/HighCardHandler.h
        src/CoR/PairHandler/PairHandler.h
        src/CoR/TwoPairHandler/TwoPairHandler.h
        src/CoR/ThreeOfKindHandler/ThreeOfKindHandler.h
        src/CoR/StraightHandler/StraightHandler.h
        src/CoR/FlushHandler/FlushHandler.h
        src/CoR/FullHouseHandler/FullHouseHandler.h
        src/CoR/FourOfKindHandler/FourOfKindHandler.h
        src/CoR/StraightFlushHandler/StraightFlushHandler.h
        src/CoR/RoyalFlushHandler/RoyalFlushHandler.h
        src/CoR/HandChecker.h
        )

set(Sources
        main.cpp
        src/PokerGame.cpp
        src/PokerStyles/PokerStyleFactory.cpp
        src/PokerStyles/PokerStyle.cpp
        src/PokerStyles/Texas/TexasPoker.cpp
        src/Models/Card/Card.cpp
        src/Models/Hand/Hand.cpp
        src/Models/Player/Player.cpp
        src/Consoles/CardConsole.cpp
        src/Consoles/PlayerConsole.cpp
        src/Consoles/Console.cpp
        src/CoR/HandHandler.cpp
        src/CoR/HandHandlerHelper.cpp
        src/CoR/HighCardHandler/HighCardHandler.cpp
        src/CoR/PairHandler/PairHandler.cpp
        src/CoR/TwoPairHandler/TwoPairHandler.cpp
        src/CoR/ThreeOfKindHandler/ThreeOfKindHandler.cpp
        src/CoR/StraightHandler/StraightHandler.cpp
        src/CoR/FlushHandler/FlushHandler.cpp
        src/CoR/FullHouseHandler/FullHouseHandler.cpp
        src/CoR/FourOfKindHandler/FourOfKindHandler.cpp
        src/CoR/StraightFlushHandler/StraightFlushHandler.cpp
        src/CoR/RoyalFlushHandler/RoyalFlushHandler.cpp
        src/CoR/HandChecker.cpp
        )

add_library(${This} STATIC ${Sources} ${Headers} src/PokerGame.cpp src/PokerGame.h)

add_executable(PokerExec ${Sources} ${Headers})

add_subdirectory(tests)