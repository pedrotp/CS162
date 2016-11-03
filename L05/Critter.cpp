
#include "Critter.hpp"

Critter::Critter(Critter ***matrPtr, int matrSize, int startX, int startY, int startStep) {
  srand (std::time(NULL));
  matrix = matrPtr;
  matrixSize = matrSize;
  xCoord = startX;
  yCoord = startY;
  breedCounter = 0;
  stepCounter = startStep;
};

std::string Critter::type() {
  return critterType;
};

bool Critter::step(int currentStep) {
  bool moved = true;
  if (stepCounter == currentStep) {
    stepCounter++;
    moved = move();
    breedCounter++;
    if (breedCounter == breedSteps) {
      breed();
      breedCounter = 0;
    }
    // stepCounter++;
  }
  return moved;
};
