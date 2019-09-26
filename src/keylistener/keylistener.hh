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
constexpr int Q_key = 113;  //
constexpr int E_key = 101; //
constexpr int R_key = 114; //

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

  Q,
  E,

  R,

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
  case LEFT_keys[2]: return Key::LEFT;
  case RIGHT_keys[2]: return Key::RIGHT;
  case UP_keys[2]: return Key::UP;
  case DOWN_keys[2]: return Key::DOWN;

  case ONE_key: return Key::ONE;
  case TWO_key: return Key::TWO;
  case THREE_key: return Key::THREE;
  case FOUR_key: return Key::FOUR;
  case FIVE_key: return Key::FIVE;
  case SIX_key: return Key::SIX;
  case SEVEN_key: return Key::SEVEN;
  case EIGHT_key: return Key::EIGHT;
  case NINE_key: return Key::NINE;
  case ZERO_key: return Key::ZERO;

  case W_key: return Key::W;
  case S_key: return Key::S;
  case A_key: return Key::A;
  case D_key: return Key::D;

  case Q_key: return Key::Q;
  case E_key: return Key::E;
  case R_key: return Key::R;

  default: return Key::NONE;
  };
  return Key::NONE;
}

}//namespace
}//namespace
