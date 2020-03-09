cmake_minimum_required(VERSION 3.15)
project(LexerLab3)

set(CMAKE_CXX_STANDARD 20)

add_executable(LexerLab3 main.cpp Scanner/Scanner.cpp Scanner/Scanner.h Token/Token.cpp Token/Token.h Position/Position.h Position/Fragment.h Position/Position.cpp Token/AlphabeticToken.cpp Token/AlphabeticToken.h Token/NumericToken.cpp Token/NumericToken.h Token/SpecToken.cpp Token/SpecToken.h)