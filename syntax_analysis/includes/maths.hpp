#pragma once

enum compare_code {
  eLess,
  eGreater,
  eLessEqual,
  eGreaterEqual,
  eExplicitCompare,
  eExplicitCompareReverse,
  eDoubleAnd,
  eDoubleOr,
  eCompNotFound
};

enum arthimetic_code {
  eAdd,
  eSub,
  eDiv,
  eMul,
  eMod,
  eInc,
  eDec,
  eMathNotFound
};

compare_code compareHash(std::string);

arthimetic_code mathHash(std::string);

uint64_t compute(uint64_t, uint64_t, std::string);

bool compare(uint64_t a, uint64_t b, std::string c);

void helloWorld();
