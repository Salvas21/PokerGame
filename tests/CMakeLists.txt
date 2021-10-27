cmake_minimum_required(VERSION 3.17)

set(This PokerTest)

set(Sources
        RoyalFlushHandlerTest.cpp
        StraightFlushHandlerTest.cpp
        FourOfKindHandlerTest.cpp
        FullHouseHandlerTest.cpp
        FlushHandlerTest.cpp
        StraightHandlerTest.cpp
        ThreeOfKindHandlerTest.cpp
        TwoPairHandlerTest.cpp
        PairHandlerTest.cpp
        )

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
        gtest_main
        Poker
        )

add_test(
        NAME ${This}
        COMMAND ${This}
)