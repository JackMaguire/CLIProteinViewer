#pragma once

#include <array>

namespace CLIProteinViewer{
namespace keylistener {

constexpr std::array< int, 3 > LEFT_keys { 27, 91, 68 };
constexpr std::array< int, 3 > RIGHT_keys { 27, 91, 67 };
constexpr std::array< int, 3 > UP_keys { 27, 91, 65 };
constexpr std::array< int, 3 > DOWN_keys { 27, 91, 66 };

constexpr int ONE_key = 49;
constexpr int TWO_key = 50;
constexpr int THREE_key = 51;
constexpr int FOUR_key = 52;
constexpr int FIVE_key = 53;
constexpr int SIX_key = 54;
constexpr int SEVEN_key = 55;
constexpr int EIGHT_key = 56;
constexpr int NINE_key = 57;
constexpr int ZERO_key = 48;

constexpr int W_key = 119; //capitol is 87
constexpr int S_key = 115; //83
constexpr int A_key = 87;  //65
constexpr int D_key = 100; //68

enum class Key {
  NONE,

  LEFT,
  RIGHT,
  UP,
  DOWN,

  W,
  S,
  A,
  D,

  ONE,
  TWO,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN,
  EIGHT,
  NINE,
  ZERO
};

//The "correct" way would be to keep a short history of the previous 3 numbers.
//Let's do the hacky way instead

Key
parse_int( int const command ){
  switch( command ){
  case LEFT_keys[2]: return LEFT;
  case RIGHT_keys[2]: return RIGHT;
  case UP_keys[2]: return UP;
  case DOWN_keys[2]: return DOWN;

  case ONE_key: return ONE;
  case TWO_key: return TWO;
  case THREE_key: return THREE;
  case FOUR_key: return FOUR;
  case FIVE_key: return FIVE;
  case SIX_key: return SIX;
  case SEVEN_key: return SEVEN;
  case EIGHT_key: return EIGHT;
  case NINE_key: return NINE;
  case ZERO_key: return ZERO;

  case W_key: return W;
  case S_key: return S;
  case A_key: return A;
  case D_key: return D;

  default: return NONE;
  };
  return NONE;
}

}//namespace
}//namespace
