# C++ chess

This project contains implementation of chess in c++.

## Purpose
Learn c++ on simple project

## Features
* 2 player game of chess in terminal
* players plays in turns and provide input on std::cin in classical
  form of writing chess moves

## Chess board positions

+----+----+----+----+----+----+----+----+
|  0 |  1 |  2 |  3 |  4 |  5 |  6 |  7 |
+----+----+----+----+----+----+----+----+
|  8 |  9 | 10 | 11 | 12 | 13 | 14 | 15 |
+----+----+----+----+----+----+----+----+
| 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 |
+----+----+----+----+----+----+----+----+
| 24 | 25 | 26 | 27 | 28 | 29 | 30 | 31 |
+----+----+----+----+----+----+----+----+
| 32 | 33 | 34 | 35 | 36 | 37 | 38 | 39 |
+----+----+----+----+----+----+----+----+
| 40 | 41 | 42 | 43 | 44 | 45 | 46 | 47 |
+----+----+----+----+----+----+----+----+
| 48 | 49 | 50 | 51 | 52 | 53 | 54 | 55 |
+----+----+----+----+----+----+----+----+
| 56 | 57 | 58 | 59 | 60 | 61 | 62 | 63 |
+----+----+----+----+----+----+----+----+

## Build
In project root create `build` directory (if not existing).
`mkdir build`
`cd build`
`cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ../`
`make`

