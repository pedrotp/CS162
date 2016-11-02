
#include "Critter.hpp"

Critter::Critter(Critter ***matrPtr, int matrSize, int startX, int startY) {
  srand (std::time(NULL));
  matrix = matrPtr;
  matrixSize = matrSize;
  xCoord = startX;
  yCoord = startY;
  breedCounter = 0;
  stepCounter = 0;
};

std::string Critter::type() {
  return critterType;
};

bool Critter::step(int currentStep) {
  bool moved = true;
  if (stepCounter == currentStep) {
    moved = move();
    breedCounter++;
    if (breedCounter == breedSteps) {
      breed();
      breedCounter = 0;
    }
    stepCounter++;
  }
  return moved;
};
