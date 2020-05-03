cmake_minimum_required(VERSION 3.15)
project(LEXERLAB4)

set(CMAKE_CXX_STANDARD 20)

add_executable(LEXERLAB4 main.cpp Compiler/Scanner.cpp Compiler/Scanner.h Token/Token.cpp Token/Token.h Position/Position.h Position/Fragment.h Position/Position.cpp Token/NonTermToken.cpp Token/NonTermToken.h Token/TermToken.cpp Token/TermToken.h Token/SpecToken.cpp Token/SpecToken.h Message/Message.cpp Message/Message.h Compiler/Compiler.cpp Compiler/Compiler.h Compiler/Scanner.h Compiler/Parser.cpp Compiler/Parser.h Node/Node.cpp Node/Node.h Node/ResultNode.cpp Node/ResultNode.h)