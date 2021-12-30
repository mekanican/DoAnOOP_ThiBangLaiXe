#pragma once

#include <cmath>
#include <tuple>

#include "../Utility/constants.h"

struct ExamComponents {
  int questionCount;
  int minCorrectAnswer;
  int timeAllowed;

  int requiredCount;
  int topicCount[7];
};

const ExamComponents types[10] = {
    {25, 21, 19 * 60, 1, {8, 0, 1, 1, 0, 7, 7}},    // A1
    {25, 23, 19 * 60, 1, {8, 0, 1, 1, 0, 7, 7}},    // A2
    {25, 23, 19 * 60, 1, {8, 0, 1, 1, 0, 7, 7}},    // A3
    {25, 23, 19 * 60, 1, {8, 0, 1, 1, 0, 7, 7}},    // A4
    {30, 27, 20 * 60, 1, {8, 0, 1, 1, 1, 9, 9}},    // B1
    {35, 32, 22 * 60, 1, {9, 1, 1, 2, 1, 10, 10}},  // B2
    {40, 36, 24 * 60, 1, {9, 1, 1, 2, 1, 14, 11}},  // C
    {45, 41, 26 * 60, 1, {9, 1, 1, 2, 1, 16, 14}},  // D
    {45, 41, 26 * 60, 1, {9, 1, 1, 2, 1, 16, 14}},  // E
    {45, 41, 26 * 60, 1, {9, 1, 1, 2, 1, 16, 14}}   // F
};

// id has 32 bit, first 7 bit is for topic, 8th bit for required, 9-18th bit for
// types
std::tuple<int, bool, int> idParser(int id) {
  bool isRequired = id & (1 << 8);

  int i = log2(id & ((1 << 8) - 1));
  int j = log2(id & (((1 << 10) - 1) << 9));
  return {i, isRequired, j};
}
