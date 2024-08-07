#include "GameState.h"
#include "GameState.h"
#include <string>




std::string gameStateToString(GameState state) {
    switch (state) {
    case GameState::Playing:
        return "Playing";
    case GameState::GameOver:
        return "Game Over";
    case GameState::GameWin:
        return "You Win";
    default:
        return "Unknown State";
    }
}


static void handleGameState(GameState state) {
    switch (state) {
    case GameState::Playing:
        //  the game is playing
        break;
    case GameState::GameOver:
        //  the game is over
        break;
    case GameState::GameWin:
        //  the game is won
        break;
    default:
        //u unknown state
        break;
    }
}


